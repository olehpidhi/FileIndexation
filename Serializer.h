#ifndef SERIALIZET_H
#define SERIALIZER_H
#include <fstream>

template<typename ContainerType>
class Serializer
{
private:
    std::fstream xmlFile;
public:
    Serializer() = default;
    Serializer(const std::string& path)
    {
        xmlFile.open(path, std::fstream::out|std::fstream::in);
      // xmlFile << ""
    }
    void serialize(ContainerType& container)
    {
        xmlFile << "<?xml version=\"1.0\"?>\n" << "<FilesInfo>\n";
        for(typename ContainerType::iterator i = container.begin(); i != container.end(); i++)
        {
            xmlFile << i->formXMLData();
        }
        xmlFile << "</FilesInfo>\n";
    }
    ~Serializer()
    {
        xmlFile.close();
    }

};

#endif // SERIALIZER_H
