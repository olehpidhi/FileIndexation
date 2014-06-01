#include "FileInfo.h"
#include <sstream>
#include <windows.h>

FileInfo::FileInfo():
    fName(NULL),
    fSize(NULL),
    fPath(NULL)
{

}

FileInfo::FileInfo(std::wstring pName, DateTime pDate, size_t pSize, std::wstring pPath):
    fName(pName),
    fDate(pDate),
    fSize(pSize),
    fPath(pPath)
{

}

FileInfo::FileInfo(const WIN32_FIND_DATA& pWindowsInfo, const std::wstring& absolutePath):
    fName(pWindowsInfo.cFileName),
    fSize(pWindowsInfo.nFileSizeHigh),
    fPath(absolutePath)
{
    FileTimeToSystemTime(&(pWindowsInfo.ftCreationTime), &fDate);
}

FileInfo::FileInfo(const FileInfo& toCopy)
{
    fName = toCopy.fName;
    fSize = toCopy.fSize;
    fDate = toCopy.fDate;
    fPath = toCopy.fPath;
}

const std::wstring& FileInfo::getName()const
{
    return fName;
}

void FileInfo::setName(const std::wstring& pName)
{
    fName = pName;
}

DateTime FileInfo::getDate()const
{
    return fDate;
}

void FileInfo::setDate(DateTime pDate)
{
    fDate = pDate;
}

size_t FileInfo::getSize()const
{
    return fSize;
}

void FileInfo::setSize(size_t pSize)
{
    fSize = pSize;
}

const std::wstring& FileInfo::getPath() const
{
    return fPath;
}

void FileInfo::setPath(const std::wstring& pPath)
{
    fPath = pPath;
}

std::wstring FileInfo::formXMLData()
{
    std::wostringstream XMLData;
    XMLData << L"<FileInfo>\n" <<
               L"\t<Name>" << fName << L"</Name>\n" <<
               L"\t<Date>" << fDate.wYear<< L"-" << fDate.wMonth << L"-" << fDate.wDay << L" " << fDate.wHour << L":" <<
                             fDate.wMinute << L":" << fDate.wSecond << L":" << fDate.wMilliseconds << L"</Date>\n" <<
               L"\t<Size>" << fSize <<L"</Size>\n" <<
               L"\t<Path>" << fPath << L"</Path>\n" <<
               L"</FileInfo>\n";
    return XMLData.str();
}

QDateTime SystemTimeToQDateTime(const SYSTEMTIME& timeToConvert)
{
    return QDateTime(QDate(timeToConvert.wYear, timeToConvert.wMonth, timeToConvert.wDay),
                     QTime(timeToConvert.wHour, timeToConvert.wMinute, timeToConvert.wSecond, timeToConvert.wMilliseconds));
}
