/* 
 * File:   Ficha.cpp
 * Author: pedro
 */
#include "Ficha.h"
#include "string.h"
Ficha::Ficha()
{
    puntaje = cantidad = 0;
    letra = "";
}

Ficha::Ficha(int puntaje_, int cantidad_, std::string letra_)
{
    puntaje = puntaje_;
    cantidad = cantidad_;
    letra = letra_;
}

void Ficha::setCantidad(int cantidad_)
{
    cantidad = cantidad_;
}

int Ficha::getCantidad() { return cantidad; }
std::string Ficha::getLetra() { return letra; }
int Ficha::getPuntaje() { return puntaje; }

Ficha::~Ficha()
{
}