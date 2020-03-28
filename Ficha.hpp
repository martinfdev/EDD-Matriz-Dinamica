/* 
 * File:   Ficha.hpp
 * Author: pedro
 */
class Ficha
{
private:
    int puntaje, cantidad;
    char letra;
public:
    Ficha();
    Ficha(int, int, char);
    void setCantidad(int);
    int getPuntaje();
    int getCantidad(); 
    char getLetra();
    ~Ficha();
};

Ficha::Ficha(){}

Ficha::Ficha(int puntaje_, int cantidad_, char letra_)
{
    puntaje = puntaje_;
    cantidad = cantidad_;
    letra = letra_;    
}

void Ficha::setCantidad(int cantidad_){
    cantidad =cantidad_;
}

int Ficha::getCantidad(){return cantidad;}
char Ficha::getLetra(){return letra;}
int Ficha::getPuntaje(){return puntaje;}


Ficha::~Ficha()
{
}



