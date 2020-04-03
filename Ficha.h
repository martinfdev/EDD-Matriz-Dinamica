/* 
 * File:   Ficha.h
 * Author: pedro
 */
#ifndef FICHA_H
#define FICHA_H
#include <string>

class Ficha
{
private:
    int puntaje, cantidad;
    std::string letra;
public:
    Ficha();
    Ficha(int, int, std::string);
    void setCantidad(int);
    int getPuntaje();
    int getCantidad(); 
    std::string getLetra();
    ~Ficha();
};
#endif //FICHA_H