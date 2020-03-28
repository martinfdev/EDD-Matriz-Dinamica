/* 
 * File:   Jugador.h
 * Author: pedro
 */
#ifndef JUGADOR_H
#define JUGADOR_H
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
#endif //JUGADOR_H