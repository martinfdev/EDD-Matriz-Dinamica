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


Init::Init()
{ 
    MatrizDispersa* matriz = new MatrizDispersa();
    matriz->insertMatrix(5,3,"H");
    matriz->insertMatrix(3,4,"P");
    matriz->insertMatrix(4,4,"R");
    //matriz->insertMatrix(5,4,"O");
    matriz->insertMatrix(6,4,"Y");
    matriz->insertMatrix(7,4,"E");
    matriz->insertMatrix(8,4,"C");
    matriz->insertMatrix(9,4,"T");
    matriz->insertMatrix(10,4,"O");
    matriz->insertMatrix(5,5,"L");
    matriz->insertMatrix(5,6,"A");
    matriz->insertMatrix(5,4,"O");
    //matriz->insertMatrix(0,0,"0A0");
    //matriz->insertMatrix(0,1,"0A1");
    //matriz->insertMatrix(0,2,"0A2");
    //matriz->insertMatrix(0,3,"0A3");
    //matriz->insertMatrix(0,4,"0A4");
    //matriz->insertMatrix(1,0,"1A0");
    //matriz->insertMatrix(1,1,"1A1");
    //matriz->insertMatrix(1,2,"1A2");
    //matriz->insertMatrix(1,3,"1A3");
    //matriz->insertMatrix(1,4,"1A4");
    //matriz->insertMatrix(2,0,"2A0");
    //matriz->insertMatrix(2,1,"2A1");
    //matriz->insertMatrix(2,2,"2A2");
    //matriz->insertMatrix(2,3,"2A2");
    //matriz->insertMatrix(2,4,"2A4");
    //matriz->insertMatrix(3,0,"3A0");
    //matriz->insertMatrix(3,1,"3A1");
    //matriz->insertMatrix(3,2,"3A2");
    //matriz->insertMatrix(3,3,"3A3");
    //matriz->insertMatrix(3,4,"3A4");
    //matriz->insertMatrix(4,0,"4A0");
    //matriz->insertMatrix(4,1,"4A1");
    //matriz->insertMatrix(4,2,"4A2");
    //matriz->insertMatrix(4,3,"4A3");
    //matriz->insertMatrix(4,4,"4A4"); 
       //matriz->showMatrix();
    matriz->report();

}
Init::~Init() {}