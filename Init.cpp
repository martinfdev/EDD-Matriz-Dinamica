/* 
 * File:   Init.cpp
 * Author: pedro
 */
#include <iostream>
#include "Init.h"
//#include "ListaDoble.h"
//#include "ListaDoble.cpp"
//#include "Lista.h"
//#include "Lista.cpp"
//#include "MatrizDispersa.h"
#include "Jugador.h"
#include "Jugador.cpp"
#include "BST.h"
#include "BST.cpp"
#include "Ficha.hpp"


Init::Init()
{ 
    BST *jugadores = new BST();
    jugadores->insert("Heidy");
    jugadores->insert("Carlos");
    jugadores->insert("Rodrigo");
    jugadores->insert("Antonio");
    jugadores->insert("Eduardo");
    jugadores->insert("Pamela");
    jugadores->insert("User80");
    jugadores->insert("Juan");
    jugadores->insert("Cascabel");
    jugadores->insert("Endoriano");
    jugadores->insert("Pau");
    jugadores->insert("Lety");
    jugadores->insert("Andres");
    jugadores->insert("Boruto");
    jugadores->insert("Ximena");
    //jugadores->preorder();
    //jugadores->inorder();
    //jugadores->postorder();
    jugadores->report();
    //cout<<jugadores->search("Eduardo")->getData()->getName()<<"\n";


    
    
    //ListaDoble<string> *diccionario = new ListaDoble<string>();
    //File * readJson = new File(diccionario);
    //readJson->readJson(readJson->ReadFile("configGame.json"));
    //diccionario->reportStringC("Rdiccionario");
   

}
Init::~Init() {}