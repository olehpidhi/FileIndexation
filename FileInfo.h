#ifndef FILEINFO_H
#define FILEINFO_H
#include <string>
#include <time.h>
#include <windows.h>
#include <QDateTime>
 typedef SYSTEMTIME DateTime;
class FileInfo
{

private:
    std::wstring fName;
    DateTime fDate;
    size_t fSize;
    std::wstring fPath;

public:
    FileInfo();

    FileInfo(std::wstring, DateTime, size_t, std::wstring);

    FileInfo(const WIN32_FIND_DATA&, const std::wstring&);

    FileInfo(const FileInfo&);

    const std::wstring &getName()const;

    void setName(const std::wstring&);

     DateTime getDate()const;

    void setDate(DateTime);

    size_t getSize()const;

    void setSize(size_t);

    const std::wstring &getPath() const;

    void setPath(const std::wstring&);

    std::wstring formXMLData();
};

QDateTime SystemTimeToQDateTime(const SYSTEMTIME&);

#endif // FILEINFO_H
