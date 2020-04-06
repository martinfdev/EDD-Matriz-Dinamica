/* 
 * File:   Ventana.h
 * Author: pedro
 */

#ifndef VENTANA_H
#define VENTANA_H
#include <ncurses.h>
#include <cstring>
#include <string>
#include "Lista.h"
#include "BST.h"
#include "Jugador.h"
#include "ListaDoble.h"
#include "Config.h"
#include "Ficha.h"
#include "MatrizDispersa.h"
#include "alldefine.h"
#include "Reporte.h"

class Ventana
{
private:
    MatrizDispersa *matriz;
    int pointsP1, pointsP2;
    Config *conf;
    Lista<Jugador *> *lscoreJugador;
    Lista<int> *listaScoreGeneral;
    Lista<Ficha *> *colaFicha;
    WINDOW *menuw, *miw, *titlew;
    WINDOW *gamew, *wellw, *statw, *nextw, *wp2, *wp1, *addpw;
    ListaDoble<string> *diccionario; //lista doblemente ciruclar enlazada para el diccionario de palabra de la entrad
    BST *arbolJugadores;
    Jugador *player1, *player2;
    int GAME_HEIGHT = WELL_HEIGHT + 4, GAME_WIDTH = WELL_WIDTH + NEXT_WIDTH + 4 + 20;
    void print_menu(WINDOW *);
    void score_general(char *message);
    int menu();
    void initialise_colors();
    void init_windows();
    int addPlayer();
    void play_game();
    void update_next();
    void update_stat();
    void update_wp2();
    void update_wp1();
    void update_well();
    void draw_block(WINDOW *win, int y, int x, int type, int orient, char);
    void draw_grid();
    void random();
    void asignar_fichas();

public:
    Ventana(/* args */);
    Ventana(ListaDoble<string> *, BST *jugador, Config *, Lista<Ficha *> *, MatrizDispersa *);
    void menuGame();
    ~Ventana();
};
#endif //VENTANA_H