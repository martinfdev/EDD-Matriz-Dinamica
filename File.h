/* 
 * File:   File.h
 * Author: pedro
 */
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "ListaDoble.h"
#include "Config.h"

using std::string;

class File
{
private:
    Config *configI;
    string cadena;
    ListaDoble<string> *dictionary;

public:
    File();
    File(ListaDoble<string> *, Config *);
    string ReadFile(string);
    bool createOrWriteFile(string, string);
    bool readJson(string);
    bool dotGraphGenerator(string, string);
    ~File();
};
#endif