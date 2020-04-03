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


Init::Init()
{
    Config *conf = new Config();
    BST *jugadores = new BST();
    ListaDoble<string> *diccionario = new ListaDoble<string>();
    MatrizDispersa *matriz = new MatrizDispersa();
    lFichas = new Lista<Ficha *>();
    generarFichas();
    
    //f = new File(diccionario, conf);
    //path_config_json();
    //Ventana win = Ventana(diccionario, jugadores, conf, lFichas, matriz);
    //win.menuGame();
    
    

    //Reporte *repor = new Reporte();
    //repor->ReporteFichas(lFichas);

    //Ventana *ventan = new Ventana(diccionario, jugadores);
    //ventan->menuGame();
    //jugadores->report();

    //f->readJson(f->ReadFile("configG.json"));
    //cout << diccionario->getDataC() << "\n";
    //conf->setDimension(3);
    //cout << "Dimension: " << conf->getDimesion() << "\n";
    //conf->setCasillaE(0,0,2);
    //conf->setCasillaE(3,5,3);
    //Lista<CasillaE *> *temp = conf->getCasillaE();
    //for (int i = 0; i < temp->size(); i++)
    //{
    //    CasillaE *tmp = temp->getDataC();
    //    cout << "Casillas Especiales\t X : " << tmp->getX() << "\tY : " << tmp->getY() << "\tPuntaje: " << tmp->getPuntaje() << "\n";
    //}
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

Init::~Init() {}