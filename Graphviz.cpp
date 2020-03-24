/* 
 * File:   Graphviz.cpp
 * Author: pedro
 */

#include "File.h"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "Graphviz.h"

using namespace std;

//constructor por defecto
Graphviz::Graphviz()
{
}

//retorna codigo graphviz en formato string
string Graphviz::getDotSource()
{
    return dotSource;
}

//agrega un salto de linea
void Graphviz::addln()
{
    dotSource = dotSource + "\n";
}

//agrea codigo del lenguaje graphviz + salto de linaea
void Graphviz::addln(string line){
    dotSource = dotSource +line+"\n";
}

//agrega codigo dot sin salto de linea
void Graphviz::add(string codeDot){
    dotSource = dotSource+codeDot;
}

//retorna el encabezado para la grafica;
string Graphviz::start_graph()
{
    return "digraph G {";
}

//agrega el final de la grafica
string Graphviz::end()
{
    return "}";
}

//genera la agraifaca y la abre automaticamente
bool Graphviz::dotGraphGenerator(string nameFile, string sourceDot)
{
    string stringTmp = "dot -Tpng " + nameFile + ".dot -o " + nameFile + ".png";
    string comandDisplay = "display " + nameFile + ".png &";

    if (createOrWriteFile(nameFile + ".dot", sourceDot))
    {
        char *dot = new char[stringTmp.size() + 1];
        strcpy(dot, stringTmp.c_str());
        char *displayOpen = new char[comandDisplay.size() + 1];
        strcpy(displayOpen, comandDisplay.c_str());
        //std::cout << dot << "\n";
        //std::cout << displayOpen << "\n";
        system(dot);
        system(displayOpen);
    }
}

//crea el archivo .dot
bool Graphviz::createOrWriteFile(string nameFile, string textGraph)
{
    ofstream filOut;
    filOut.open(nameFile, ios::out);
    if (filOut.fail())
    {
        std::cout << "Error al crear o modifiar el archivo\n";
        return false;
    }
    else
    {

        filOut << textGraph << std::endl;
        filOut.close();
    }
}

Graphviz::~Graphviz()
{
}
