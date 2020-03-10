#ifndef FILE_H
#define FILE_H
#include <iostream>

class File
{
private:
    std::string cadena;
public:
    File();
    std::string ReadFile(std::string);
    bool createOrWriteFile(std::string, std::string);
    void readJson(std::string);
    bool dotGraphGenerator(std::string, std::string);
    ~File();
};
#endif