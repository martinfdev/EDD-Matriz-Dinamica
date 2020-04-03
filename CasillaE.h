/* 
 * File:   CasillaE.h
 * Author: pedro
 */

#ifndef CASILLAE_H
#define CASILLAE_H

class CasillaE
{
private:
    int x, y, puntaje;
public:
    CasillaE();
    CasillaE(int, int, int);
    int getX();
    int getY();
    int getPuntaje();
    ~CasillaE();
};
#endif //CASILLA_H