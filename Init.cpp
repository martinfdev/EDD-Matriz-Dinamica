/* 
 * File:   Init.cpp
 * Author: pedro
 */
#include <iostream>
#include "Init.h"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
#include "Lista.h"
#include "ncurses.h"
//#include "Lista.cpp"
//#include "MatrizDispersa.h"
#include "Jugador.h"
#include "Jugador.cpp"
#include "BST.h"
#include "BST.cpp"
//#include "Ficha.hpp"
#include "Reporte.hpp"
#include "Ventana.h"
#include "Ventana.cpp"

Init::Init()
{
    //BST *jugadores = new BST();
    //jugadores->insert("Heidy");
    //jugadores->insert("Carlos");
    //jugadores->insert("Rodrigo");
    //jugadores->insert("Antonio");
    //jugadores->insert("Eduardo");
    //jugadores->insert("Pamela");
    //jugadores->insert("User80");
    //jugadores->insert("Juan");
    //jugadores->insert("Cascabel");
    //jugadores->insert("Endoriano");
    //jugadores->insert("Pau");
    //jugadores->insert("Lety");
    //jugadores->insert("Andres");
    //jugadores->insert("Boruto");
    //jugadores->insert("Ximena");
    //jugadores->preorder();
    //jugadores->inorder();
    //jugadores->postorder();
    //jugadores->report();
    //cout<<jugadores->search("Eduardo")->getData()->getName()<<"\n";

    //ListaDoble<string> *diccionario = new ListaDoble<string>();
    //File * readJson = new File(diccionario);
    //readJson->readJson(readJson->ReadFile("configGame.json"));
    //diccionario->reportStringC("Rdiccionario");
    //for (int i = 0; i < diccionario->getSize(); i++)
    //{
    //    cout<<diccionario->getDataC()<<"\n";
    //}

    //Lista<Ficha *> *listaFicha = new Lista<Ficha *>();
    //listaFicha->add_endS(new Ficha(1, 12, "A"));
    //listaFicha->add_endS(new Ficha(3, 2, "B"));
    //listaFicha->add_endS(new Ficha(3, 4, "C"));
    //listaFicha->add_endS(new Ficha(2, 5, "D"));
    //listaFicha->add_endS(new Ficha(1, 12, "E"));
    //listaFicha->add_endS(new Ficha(4, 1, "F"));
    //listaFicha->add_endS(new Ficha(2, 2, "G"));
    //listaFicha->add_endS(new Ficha(4, 2, "H"));
    //listaFicha->add_endS(new Ficha(1, 6, "I"));
    //listaFicha->add_endS(new Ficha(8, 1, "J"));
    //listaFicha->add_endS(new Ficha(1, 12, "K"));
    //listaFicha->add_endS(new Ficha(1, 4, "L"));
    //listaFicha->add_endS(new Ficha(3, 2, "M"));
    //listaFicha->add_endS(new Ficha(1, 5, "N"));
    //listaFicha->add_endS(new Ficha(8, 1, "Ñ"));
    //listaFicha->add_endS(new Ficha(1, 9, "O"));
    //listaFicha->add_endS(new Ficha(3, 2, "P"));
    //listaFicha->add_endS(new Ficha(5, 1, "Q"));
    //listaFicha->add_endS(new Ficha(1, 5, "R"));
    //listaFicha->add_endS(new Ficha(1, 6, "S"));
    //listaFicha->add_endS(new Ficha(1, 4, "T"));
    //listaFicha->add_endS(new Ficha(1, 5, "U"));
    //listaFicha->add_endS(new Ficha(4, 1, "V"));
    //listaFicha->add_endS(new Ficha(1, 12, "W"));
    //listaFicha->add_endS(new Ficha(8, 1, "X"));
    //listaFicha->add_endS(new Ficha(4, 1, "Y"));
    //listaFicha->add_endS(new Ficha(10, 1, "Z"));
    //

    //Reporte *repor = new Reporte();
    //repor->ReporteFichas(listaFicha);

    Ventana *ventan = new Ventana();
    ventan->menuGame();
}

Init::~Init() {}