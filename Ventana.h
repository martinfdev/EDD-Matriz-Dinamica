/* 
 * File:   Ventana.h
 * Author: pedro
 */
#ifndef VENTANA_H
#define VENTANA_H
#define WELL_HEIGHT 22
#define WELL_WIDTH 32
#define NO_LEVELS 10
#define NEXT_HEIGHT 10
#define NEXT_WIDTH 20
#define SCORE_HEIGHT 14
#define SCORE_WIDTH 32

#define CONTROL_UP 'i'
#define CONTROL_DOWN 'k'
#define CONTROL_LEFT 'j'
#define CONTROL_RIGHT 'l'
#define CONTROL_NEXT 's'
#define CONTROL_BACK 'a'

#define NITEMS 6
#define NO_LEVELS 10
#include <ncurses.h>
#include <string>

class Ventana
{
private:
    int GAME_HEIGHT = WELL_HEIGHT + 4, GAME_WIDTH = WELL_WIDTH + NEXT_WIDTH + 4 + 20;
    WINDOW *menuw, *miw, *titlew;
    WINDOW *gamew, *wellw, *statw, *nextw, *instw, *lastw, *scorew;
    void print_menu(WINDOW *);
    void disp_score(char *message);
    int menu();
    void initialise_colors();
    void init_windows();
public:
    Ventana(/* args */);
    void menuGame();
    ~Ventana();
};
#endif //VENTANA_H
