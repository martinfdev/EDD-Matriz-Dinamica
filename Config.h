/* 
 * File:   Config.h
 * Author: pedro
 */

#ifndef CONFIG_H
#define CONFIG_H
#include "Lista.h"
#include "CasillaE.h"

class Config
{
private:
    int dimension;
    Lista<CasillaE*> *lCasillaE;

public:
    Config();
    void setDimension(int);
    void setCasillaE(int, int, int);
    int getDimension();
    Lista<CasillaE*> *getCasillaE();
    ~Config();
};
#endif //CONFIG_H