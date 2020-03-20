/* 
 * File:   Init.cpp
 * Author: pedro
 */
#include <iostream>
#include "Init.h"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
#include "Lista.h"
#include "Lista.cpp"
#include "MatrizDispersa.h"
#include "Graphviz.h"
#include "Graphviz.cpp"


Init::Init()
{
    //Graphviz *grafica = new Graphviz();
    //grafica->addln(grafica->start_graph());
    //grafica->addln("rankdir=TB;");
    //grafica->addln("node[]");
    //grafica->addln("2->1");
    //grafica->addln("2->3");
    //grafica->addln("3->4");
    //grafica->addln("4->3");
    //grafica->addln("4->5");
    //grafica->addln(grafica->end());
    //grafica->dotGraphGenerator("lista", grafica->getDotSource());

    

    MatrizDispersa* matriz = new MatrizDispersa();
    matriz->insertMatrix(0,0,"0,0");
    matriz->insertMatrix(2,1,"2,1");
    matriz->insertMatrix(5,0,"5,0");
    matriz->insertMatrix(5,5,"5,5");
    matriz->insertMatrix(2,3,"2,3");
    matriz->insertMatrix(3,3,"3,3");
    matriz->insertMatrix(3,2,"3,2");
    //matriz->showMatrix();
    matriz->report();

}
Init::~Init() {}