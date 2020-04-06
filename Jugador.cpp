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
   lfichas =new  ListaDoble<Ficha*>();
}
//constructor con parametro
Jugador::Jugador(string name_)
{
    name = name_;
    score = Lista<int>();
    score.add_sortInvert(0);
    lfichas = new ListaDoble<Ficha*>();
    lfichas->insertarUltimo(new Ficha(0,0,"_"));
}

void Jugador::setName(string name_)
{
    name = name_;
}

//agregar sus puntos a la lista
void Jugador::setScore(int score_){
    score.add_sortInvert(score_);
}

//agregar fichas a la lista
void Jugador::setFicha(Ficha *ficha){
    lfichas->insertarUltimo(ficha);
}

//retorna la lista de la s fichas
ListaDoble<Ficha*> *Jugador::getFicha(){return lfichas;}

string Jugador::getName() { return name; }

Lista<int> Jugador::getScore() { return score; }

int Jugador::getScoreMax(){return score.getDataFirst(); }

Jugador::~Jugador()
{
}
