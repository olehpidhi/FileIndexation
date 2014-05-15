#include "FileInfo.h"
#include <sstream>
#include <windows.h>

FileInfo::FileInfo():
    fName(""),
    fSize(NULL),
    fPath("")
{

}

FileInfo::FileInfo(std::string pName, DateTime pDate, size_t pSize, std::string pPath):
    fName(pName),
    fDate(pDate),
    fSize(pSize),
    fPath(pPath)
{

}

FileInfo::FileInfo(const WIN32_FIND_DATAA& pWindowsInfo, const std::string& absolutePath):
    fName(pWindowsInfo.cFileName),
    fSize(pWindowsInfo.nFileSizeHigh),
    fPath(absolutePath)
{
    FileTimeToSystemTime(&(pWindowsInfo.ftCreationTime), &fDate);
}

std::string& FileInfo::getName()
{
    return fName;
}

void FileInfo::setName(const std::string& pName)
{
    fName = pName;
}

DateTime FileInfo::getDate()
{
    return fDate;
}

void FileInfo::setDate(DateTime pDate)
{
    fDate = pDate;
}

size_t FileInfo::getSize()
{
    return fSize;
}

void FileInfo::setSize(size_t pSize)
{
    fSize = pSize;
}

std::string& FileInfo::getPath()
{
    return fPath;
}

void FileInfo::setPath(const std::string& pPath)
{
    fPath = pPath;
}

std::string FileInfo::formXMLData()
{
    std::ostringstream XMLData;
    XMLData << "<FileInfo>\n" <<
               "\t<Name>" << fName << "</Name>\n" <<
               "\t<Date>" << fDate.wYear<< "-" << fDate.wMonth << "-" << fDate.wDay << " " << fDate.wHour << ":" <<
                             fDate.wMinute << ":" << fDate.wSecond << ":" << fDate.wMilliseconds << "</Date>\n" <<
               "\t<Size>" << fSize << "</Size>\n" <<
               "\t<Path>" << fPath << "</Path>\n" <<
               "</FileInfo>\n";
    return XMLData.str();
}
