/* 
 * File:   File.h
 * Author: pedro
 */
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "ListaDoble.h"

using std::string;

class File
{
private:
    string cadena;
    ListaDoble<string>* dictionary;
public:
    File();
    File(ListaDoble<string>*);
    string ReadFile(string);
    bool createOrWriteFile(string, string);
    void readJson(string);
    bool dotGraphGenerator(string, string);
    ~File();
};
#endif