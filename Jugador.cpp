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
    lfichas = nullptr;
    estado = false;
}
//constructor con parametro
Jugador::Jugador(string name_)
{
    name = name_;
    score = Lista<int>();
    score.add_sortInvert(0);
    lfichas = nullptr;
    // lfichas->insertarUltimo(new Ficha(0,0,"_"));
}

void Jugador::setName(string name_)
{
    name = name_;
}

//agregar sus puntos a la lista
void Jugador::setScore(int score_)
{
    score.add_sortInvert(score_);
}

//agregar fichas a la lista
void Jugador::setFicha(ListaDoble<Ficha*> *listaFichas)
{
    lfichas = listaFichas;
}

//retorna la lista de la s fichas
ListaDoble<Ficha *> *Jugador::getFicha() { return lfichas; }

string Jugador::getName() { return name; }

Lista<int> Jugador::getScore() { return score; }

int Jugador::getScoreMax() { return score.getDataFirst(); }

//booleano para el estado del jugador
bool Jugador::getEstado() { return estado; }

//establece el estado del jugador
void Jugador::setEstado(bool estado_)
{
    estado = estado_;
}

Jugador::~Jugador()
{
}
