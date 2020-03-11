/* 
 * File:   Init.cpp
 * Author: pedro
 */
#include <iostream>
#include "Init.h"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
 
using namespace std;

Init::Init(){
   
    ListaDoble<string>* diccionario =  new ListaDoble<string>();
    file = new File(diccionario);
    //file->readJson(file->ReadFile("configGame.json"));
    //string dot = "digraph A { rankdir=LR; 1 -> 2 [label=""\"5/8/6\"""];1 -> 3 [label=""\"3/9/4\"""];2 -> 4 [label=""\"6/6/6\"""];2 -> 3 [label=""\"0/3/4\"""];3 -> 5 [label=""\"2/4/5\"""];3 -> 4 [label=""\"1/8/4\"""];4 -> 5 [label=""\"1/4/9\""", style=dashed];1 [style=bold];5 [style=bold];}";
    //file->dotGraphGenerator("arbol", dot);
    diccionario->show();


    //std::cout<<cola.getSize()<<"\n";



}
Init::~Init(){}