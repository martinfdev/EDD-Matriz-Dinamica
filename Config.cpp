/* 
 * File:   Config.cpp
 * Author: pedro
 */
#include "Config.h"
Config::Config()
{
    dimension = 0;
    lCasillaE = new Lista<CasillaE *>();
}

void Config::setDimension(int dimesion_)
{
    dimension = dimesion_;
}

void Config::setCasillaE(int x, int y, int valor)
{
    lCasillaE->add_endC(new CasillaE(x, y, valor));
}

Lista<CasillaE *> *Config::getCasillaE() { return lCasillaE; }

int Config::getDimension() { return dimension; }
Config::~Config()
{
}
