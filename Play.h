/* 
 * File:   Play.h
 * Author: pedro
 */

#ifndef PLAY_H
#define PLAY_H
#include "MatrizDispersa.h"
#include "Config.h"
#include "CasillaE.h"
#include "Jugador.h"
#include "Ficha.h"
#include <string>
#include <ctype.h>

using namespace std;

class Play
{
private:
    int socorep1, socorep2;
    MatrizDispersa * matriz, tmpmatriz;
    Jugador* player1, *player2;
    ListaDoble<string> *dictionary;
    Lista<Ficha *> *colaFichas;
    Config *conf;
    Lista<CasillaE*> *tmpCasillas;
    int dimension = 0;
    void generate_grid();
    void print_line();
    void print_grid();
    void clean_display();
    int  special_box(int, int);
    int turn(Jugador*, string);
    bool word_dictionary(string);
    void print_dictionary();
    void reverse();
    void fill_f_p1();
    void fill_f_p2();
    void show_f_player(Jugador*);
    void swap_tokens(Jugador*);
    void random_f();
    void swap_f(Jugador*);
    bool f_true(Jugador*, string, int, int);
    void reportM();
public:
    Play(Config*, MatrizDispersa*, ListaDoble<string>*, Jugador *j1, Jugador *j2, Lista<Ficha*>*);
    void play_game();
    ~Play();
};
#endif //PLAY_H