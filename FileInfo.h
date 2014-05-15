#ifndef FILEINFO_H
#define FILEINFO_H
#include <string>
#include <time.h>
#include <windows.h>
 typedef SYSTEMTIME DateTime;
class FileInfo
{

private:
    std::string fName;
    DateTime fDate;
    size_t fSize;
    std::string fPath;

public:
    FileInfo();

    FileInfo(std::string, DateTime, size_t, std::string);

    FileInfo(const WIN32_FIND_DATAA&, const std::string&);

    inline std::string& getName();

    void setName(const std::string&);

    inline DateTime getDate();

    void setDate(DateTime);

    inline size_t getSize();

    void setSize(size_t);

    inline std::string& getPath();

    void setPath(const std::string&);

    std::string formXMLData();
};

#endif // FILEINFO_H
