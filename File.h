/* 
 * File:   File.h
 * Author: pedro
 */
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "ListaDoble.h"
#include "ListaDoble.cpp"

class File
{
private:
    std::string cadena;
    ListaDoble<string>* dicionario;

public:
    File();
    File(ListaDoble<string>*);
    std::string ReadFile(std::string);
    bool createOrWriteFile(std::string, std::string);
    void readJson(std::string);
    bool dotGraphGenerator(std::string, std::string);
    ~File();
};
#endif