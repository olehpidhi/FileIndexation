#include "indexation.h"
#include "Serializer.h"
#include <QFileDialog>

IndexatorRunnable::IndexatorRunnable()
{
    canTerminate = false;
    getDrivesLetters();
}

IndexatorRunnable::~IndexatorRunnable()
{
}

void IndexatorRunnable::getDrivesLetters()
{
    wchar_t driveStrings[MAX_PATH];
    DWORD result = GetLogicalDriveStrings(MAX_PATH, driveStrings);
    if(result > 0 && result <= MAX_PATH)
    {
        wchar_t* singleDrive = driveStrings;
        while(*singleDrive)
        {
            drivesLetters.push_back(std::wstring(singleDrive));
            singleDrive += wcslen(singleDrive) + 1;
        }
    }

}

void IndexatorRunnable::iterateAllFilesInDirectory(const wchar_t* dirPath)
{
    if(!canTerminate)
    {
        std::wostringstream directoryPath;
        directoryPath << dirPath;
        directoryPath << "\\*";

        WIN32_FIND_DATA foundFileData;
        HANDLE foundFileHandler = FindFirstFile(directoryPath.str().c_str(), &foundFileData);

        if (foundFileHandler == INVALID_HANDLE_VALUE)
        {
            return;
        }

        do
        {
            if(!(foundFileData.dwFileAttributes & (FILE_ATTRIBUTE_NOT_CONTENT_INDEXED))
                    && !(foundFileData.dwFileAttributes & (FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM))
                    && (foundFileData.cFileName[wcslen(foundFileData.cFileName)-1] != '.'))
            {
                std::wostringstream absolutePath;
                absolutePath << dirPath << "\\";
                absolutePath << foundFileData.cFileName;


                if (foundFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    textChanged(QString::fromStdWString(absolutePath.str()));
                    iterateAllFilesInDirectory(absolutePath.str().c_str());
                }
                else
                {
                    filesData.push_back(FileInfo(foundFileData, absolutePath.str()));
                }
            }
        }
        while (FindNextFile(foundFileHandler, &foundFileData) != 0);

        FindClose(foundFileHandler);
    }
    else
    {
        return;
    }
}


void* IndexatorRunnable::run()
{
    textChanged("Initializing...");
    indexationCompleted(false);
    drivesLetters.resize(2);
    for(auto i : drivesLetters)
    {
        iterateAllFilesInDirectory(i.c_str());
    }
    Serializer<std::deque<FileInfo>> xml("C:\\res.xml");
    textChanged("Serializing...");
    xml.serialize(filesData);
    textChanged("Done");
    indexationCompleted(true);
    return 0;
}

void IndexatorRunnable::terminate()
{
    canTerminate = true;
}
