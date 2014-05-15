#include "DiscFunctions.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

void findAllFilesInDirectory(const CHAR* dirPath, std::list<FileInfo>& filesData, QLabel* currentDirectory)
{
    //copy directory path to
    CHAR directoryPath[MAX_PATH];
    StringCchCopyA(directoryPath, MAX_PATH, dirPath);

    //get length of directory path
    size_t pathLength = strlen(dirPath);
    //StringCchLengthA(directoryPath, MAX_PATH, &pathLength);

    //check if length of path is valid
    if (pathLength > (MAX_PATH - 3))
    {
        //show error message here
        return;
    }
    //make string compatilbel with FundFile function

    StringCchCatA(directoryPath, MAX_PATH, "\\*");

    //find first file in directory
    WIN32_FIND_DATAA foundFileData;
    HANDLE foundFileHandler = FindFirstFileA(directoryPath, &foundFileData);

    if (foundFileHandler == INVALID_HANDLE_VALUE)
    {
        //show error message
        return;
    }

    do
    {
        char* filename = foundFileData.cFileName;
        if(!(foundFileData.dwFileAttributes & (FILE_ATTRIBUTE_NOT_CONTENT_INDEXED))
                && !(foundFileData.dwFileAttributes & (FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM))
                && (filename[strlen(filename)-1] != '.'))
        {
            CHAR absolutePath[MAX_PATH];
            StringCchCopyA(absolutePath, MAX_PATH, dirPath);
            StringCchCatA(absolutePath, MAX_PATH, foundFileData.cFileName);

            StringCchCatA(absolutePath, MAX_PATH, "\\\0");
            QString txt = QString(absolutePath);
            if(txt == "C:\\Program Files\\Common Files\\Adobe\\Adobe Photoshop CS5\\AMT_Driver")
            {
                int a =9;
            }
            currentDirectory->setText(txt);

            if (foundFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                findAllFilesInDirectory(absolutePath, filesData, currentDirectory);
            }
            else
            {
                filesData.push_back(FileInfo(foundFileData, std::string(absolutePath)));
            }
        }
    } while (FindNextFileA(foundFileHandler, &foundFileData) != 0);


    if (GetLastError() == ERROR_NO_MORE_FILES)
    {
        //showError
    }
    FindClose(foundFileHandler);
}

void DisplayErrorBox(LPTSTR lpszFunction)
{
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    // Display the error message and clean up

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40)*sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

std::list<std::string> getDiscsLetters()
{
    CHAR driveStrings[MAX_PATH];
    DWORD result = GetLogicalDriveStringsA(result, driveStrings);
    std::list<std::string> drivesLetters;
    if(result > 0 && result <= MAX_PATH)
    {
        char* singleDrive = driveStrings;
        while(*singleDrive)
        {
            drivesLetters.push_back(std::string(singleDrive));
            singleDrive += strlen(singleDrive) + 1;
        }
    }
    return drivesLetters;
}
