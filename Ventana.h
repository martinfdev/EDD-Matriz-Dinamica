/* 
 * File:   Ventana.h
 * Author: pedro
 */

#ifndef VENTANA_H
#define VENTANA_H
#include <cstring>
#include <string>
#include "Lista.h"
#include "BST.h"
#include "Jugador.h"
#include "ListaDoble.h"
#include "Config.h"
#include "Ficha.h"
#include "MatrizDispersa.h"
#include "Reporte.h"
#include "Play.h"

class Ventana
{
private:
    MatrizDispersa *matriz;
    Config *conf;
    Lista<Jugador *> *lscoreJugador;
    Lista<int> *listaScoreGeneral;
    Lista<Ficha *> *lfichas;
    ListaDoble<string> *diccionario; //lista doblemente ciruclar enlazada para el diccionario de palabra de la entrad
    BST *arbolJugadores;
    Jugador *player1, *player2;
    void clean_display();
    int add_player();
    void init_windows();
    void play_game();
    void random();
    void asignar_fichas();
    void report();
    void select_player();
    void report_f_p1();
    void report_f_p2();
    void rplayer();

public:
    Ventana(/* args */);
    Ventana(ListaDoble<string> *, BST *jugador, Config *, Lista<Ficha *> *, MatrizDispersa *);
    void menuGame();
    ~Ventana();
};
#endif //VENTANA_H