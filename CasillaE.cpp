/* 
 * File:   CasillaE.cpp
 * Author: pedro
 */

#include "CasillaE.h"

CasillaE::CasillaE()
{
    x = y = puntaje = 0;
}

CasillaE::CasillaE(int x_, int y_, int puntaje_)
{
    x = x_;
    y = y_;
    puntaje = puntaje_;
}

int CasillaE::getPuntaje() { return puntaje; }
int CasillaE::getX() { return x; }
int CasillaE::getY() { return y; }

CasillaE::~CasillaE()
{
}