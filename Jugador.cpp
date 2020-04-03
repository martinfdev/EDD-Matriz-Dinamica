/* 
 * File:   Jugador.cpp
 * Author: pedro
 */
#include "Jugador.h"
//constructor por defecto
Jugador::Jugador()
{
   score = Lista<int>();
   score.add_sortInvert(0);
}
//constructor con parametro
Jugador::Jugador(string name_)
{
    name = name_;
    score = Lista<int>();
    score.add_sortInvert(0);
}

void Jugador::setName(string name_)
{
    name = name_;
}

//agregar sus puntos a la lista
void Jugador::setScore(int score_){
    score.add_sortInvert(score_);
}

string Jugador::getName() { return name; }

Lista<int> Jugador::getScore() { return score; }

int Jugador::getScoreMax(){return score.getDataFirst(); }

Jugador::~Jugador()
{
}
