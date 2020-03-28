/* 
 * File:   Jugador.cpp
 * Author: pedro
 */
#include "Jugador.h"
//constructor por defecto
Jugador::Jugador()
{
    score = new Lista<int>();
}
//constructor con parametro
Jugador::Jugador(string name_)
{
    name = name_;
    score = new Lista<int>();
}

void Jugador::setName(string name_)
{
    name = name_;
}

string Jugador::getName() { return name; }

Lista<int> *Jugador::getScore() { return score; }

Jugador::~Jugador()
{
}
