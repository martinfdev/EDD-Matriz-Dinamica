/* 
 * File:   Ficha.hpp
 * Author: pedro
 */
#include <string>
class Ficha
{
private:
    int puntaje, cantidad;
    string letra;
public:
    Ficha();
    Ficha(int, int, string);
    void setCantidad(int);
    int getPuntaje();
    int getCantidad(); 
    string getLetra();
    ~Ficha();
};

Ficha::Ficha(){}

Ficha::Ficha(int puntaje_, int cantidad_, string letra_)
{
    puntaje = puntaje_;
    cantidad = cantidad_;
    letra = letra_;    
}

void Ficha::setCantidad(int cantidad_){
    cantidad =cantidad_;
}

int Ficha::getCantidad(){return cantidad;}
string Ficha::getLetra(){return letra;}
int Ficha::getPuntaje(){return puntaje;}


Ficha::~Ficha()
{
}



