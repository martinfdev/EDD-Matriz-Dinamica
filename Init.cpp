/* 
 * File:   Init.cpp
 * Author: pedro
 */
#include <iostream>
#include "Init.h"
#include "NodeT.h"
#include "NodeT.cpp"
#include "NodeM.h"
#include "NodeM.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Config.h"
#include "Lista.h"
#include "Lista.cpp"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
#include "MatrizDispersa.h"
#include "MatrizDispersa.cpp"
#include "Graphviz.h"
#include "Graphviz.cpp"
#include "BST.h"
#include "BST.cpp"
#include "Jugador.h"
#include "Jugador.cpp"
#include "CasillaE.h"
#include "CasillaE.cpp"
#include "Config.h"
#include "Config.cpp"
#include "File.h"
#include "File.cpp"
#include "Ventana.h"
#include "Ventana.cpp"
#include "Ficha.h"
#include "Ficha.cpp"
#include "Reporte.h"
#include "Reporte.cpp"
#include <stdlib.h>
#include <time.h>
#include "Play.h"
#include "Play.cpp"


Init::Init()
{
    Config *conf = new Config();
    BST *jugadores = new BST();
    ListaDoble<string> *diccionario = new ListaDoble<string>();
    MatrizDispersa *matriz = new MatrizDispersa();
    lFichas = new Lista<Ficha *>();
    generarFichas();
    f = new File(diccionario, conf);
    path_config_json();
    Ventana win = Ventana(diccionario, jugadores, conf, lFichas, matriz);
    win.menuGame();
    //Play *play = new Play(conf, matriz, diccionario);
   //  play->play_game();
    //matriz->report();
    
    
    
    //Jugador j1 = Jugador("Juan");
    //Jugador j2 = Jugador("Pedro");
    //int x = lFichas->size();
    //for (int  i = 0; i < x; i++)
    //{
    //    if (i<7)
    //    {
    //        Ficha *tmp =lFichas->del_headS();
    //        //cout<<tmp->getLetra()<<"\n";
    //        j1.setFicha(tmp);
//
    //    }else
    //        break;
    //}
    //int k = lFichas->size();
    //
    //for (int i = 0; i < k; i++)
    //{
    //    if (i<7)
    //    {
    //        Ficha *tmp =lFichas->del_headS();
    //        //cout<<tmp->getLetra()<<"\n";
    //        j2.setFicha(tmp);
    //        
    //    }else
    //        break; 
    //}
//
    //ListaDoble<Ficha* > tm = *j1.getFicha();
    //for (int i = 0; i < tm.getSize(); i++)
    //{
    //    Ficha *tmp = tm.getDataNext();
    //    cout<<tmp->getLetra()<<"\n";
    //}
    //
}

//carga el archivo de configuracion antes empezar
void Init::path_config_json()
{

    cout << "Escriba la ruta del Archivo de configuracion :\n\n";
    string path;
    cin >> path;
    if (f->readJson(f->ReadFile(path)))
    {
        return;
    }
    else
        path_config_json();
}

//genera las fichas predeterminandas del juego
void Init::generarFichas()
{
    lFichas->add_endS(new Ficha(1, 12, "A"));
    lFichas->add_endS(new Ficha(3, 2, "B"));
    lFichas->add_endS(new Ficha(3, 4, "C"));
    lFichas->add_endS(new Ficha(2, 5, "D"));
    lFichas->add_endS(new Ficha(1, 12, "E"));
    lFichas->add_endS(new Ficha(4, 1, "F"));
    lFichas->add_endS(new Ficha(2, 2, "G"));
    lFichas->add_endS(new Ficha(4, 2, "H"));
    lFichas->add_endS(new Ficha(1, 6, "I"));
    lFichas->add_endS(new Ficha(8, 1, "J"));
    lFichas->add_endS(new Ficha(1, 12, "K"));
    lFichas->add_endS(new Ficha(1, 4, "L"));
    lFichas->add_endS(new Ficha(3, 2, "M"));
    lFichas->add_endS(new Ficha(1, 5, "N"));
    lFichas->add_endS(new Ficha(8, 1, "Ñ"));
    lFichas->add_endS(new Ficha(1, 9, "O"));
    lFichas->add_endS(new Ficha(3, 2, "P"));
    lFichas->add_endS(new Ficha(5, 1, "Q"));
    lFichas->add_endS(new Ficha(1, 5, "R"));
    lFichas->add_endS(new Ficha(1, 6, "S"));
    lFichas->add_endS(new Ficha(1, 4, "T"));
    lFichas->add_endS(new Ficha(1, 5, "U"));
    lFichas->add_endS(new Ficha(4, 1, "V"));
    lFichas->add_endS(new Ficha(1, 12, "W"));
    lFichas->add_endS(new Ficha(8, 1, "X"));
    lFichas->add_endS(new Ficha(4, 1, "Y"));
    lFichas->add_endS(new Ficha(10, 1, "Z"));
}

//destructor
Init::~Init() {}