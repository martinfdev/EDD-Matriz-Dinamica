/* 
 * File:   Jugador.hpp
 * Author: pedro
 */
#include "Lista.h"
#include "Lista.cpp"
using namespace std;

class Jugador
{
private:
    Lista<int> *score;
    string name;

public:
    Jugador();
    Jugador(string);
    //void insertScore(int);
    void setName(string);
    string getName();
    Lista<int> *getScore();
    ~Jugador();
};
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
