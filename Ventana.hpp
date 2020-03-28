#include <stdio.h>
#include <ncurses.h>

class Ventana
{
private:
    int ch;
    WINDOW *my_root;
    int width, height;
public:
    Ventana(/* args */);
    void vP();
    ~Ventana();
};

//constructor por defecto
Ventana::Ventana()
{
}

//metodo para el menu de la opciones que se realizen
void Ventana::vP(){

}

//destructor 
Ventana::~Ventana()
{
}
