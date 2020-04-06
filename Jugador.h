/* 
 * File:   Jugador.h
 * Author: pedro
 */
#ifndef JUGADOR_H
#define JUGADOR_H
#include "Lista.h"
#include "Ficha.h"
#include "ListaDoble.h"

using namespace std;

class Jugador
{
private:
    Lista<int> score;
    string name;
    ListaDoble<Ficha *> *lfichas;

public:
    Jugador();
    Jugador(string);
    void setName(string);
    string getName();
    Lista<int> getScore();
    void setScore(int);
    int getScoreMax();
    void setFicha(Ficha *);
    ListaDoble<Ficha *> *getFicha();
    ~Jugador();
};
#endif //JUGADOR_H