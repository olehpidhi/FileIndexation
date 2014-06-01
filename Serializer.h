#ifndef SERIALIZET_H
#define SERIALIZER_H
#include <fstream>
#include "FileInfo.h"
#include <sstream>
#include <string.h>
template<typename ContainerType>
class Serializer
{
private:
    FILE* xmlFile;
public:
    Serializer() = default;

    Serializer(const std::string& path)
    {
        xmlFile = fopen(path.c_str(), "w");
    }
    void serialize(ContainerType& container)
    {
        fwprintf(xmlFile, L"<?xml version=\"1.0\"?>\n<FilesInfo>\n");
        for(typename ContainerType::iterator i = container.begin(); i != container.end(); i++)
        {
            fwprintf(xmlFile, i->formXMLData().c_str());
        }
        fwprintf(xmlFile,L"</FilesInfo>\n");
    }

    ~Serializer()
    {
        fclose(xmlFile);
    }

};

#endif // SERIALIZER_H
