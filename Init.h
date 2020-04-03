/* 
 * File:   Init.h
 * Author: pedro
 */
#ifndef INIT_H
#define INIT_H
#include "File.h"
#include "Lista.h"
#include "Ficha.h"
class Init
{
private:
    File *f;
    Lista<Ficha*> *lFichas;
    void path_config_json();
    void generarFichas();
public:
    Init(/* args */);
    ~Init();
};

#endif