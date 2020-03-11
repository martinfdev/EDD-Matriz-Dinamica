/* 
 * File:   File.cpp
 * Author: pedro
 */
#include "File.h"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <jsoncpp/json/json.h>
#include "ListaDoble.h"
#include "ListaDoble.cpp"

using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

File::File(){

}

File::File(ListaDoble<string>* diccionario)
{
    this->dicionario = diccionario;
}

bool File::createOrWriteFile(string nameFile, string textoAescribir)
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

        filOut << textoAescribir << std::endl;
        filOut.close();
    }
}

string File::ReadFile(string pathFile)
{
    string texto, aux;
    ifstream fileIn;
    fileIn.open(pathFile, ios::in);
    if (fileIn.fail())
    {
        std::cout << "Error en la lectura del archivo\n";
        return 0;
    }
    else
    {
        while (!fileIn.eof())
        {
            getline(fileIn, aux);
            texto = texto + aux + "\n";
        }
        fileIn.close();
        return texto;
    }
    return texto;
}

void File::readJson(string json)
{
    Json::Reader r;
    Json::Value objJson;
    r.parse(json, objJson);
    // std::cout<<objJson;
    const Json::Value &dimension = objJson["dimension"];
    // std::cout<<"Dimension\t"<<dimension<<"\n";
    const Json::Value &casillas = objJson["casillas"];
    // std::cout<<"casillas"<<"\n";
    const Json::Value &dobles = casillas["dobles"];
    //std::cout<<"dobles"<<"\n";
    for (int i = 0; i < dobles.size(); i++)
    {
        //   std::cout << "\nposcion x: " << dobles[i]["x"].asString()<<"\t";
        //   std::cout << "\nposcion y: " << dobles[i]["y"].asString()<<"\n";
    }
    const Json::Value &triples = casillas["triples"];
    // std::cout<<"triples"<<"\n";
    for (int i = 0; i < triples.size(); i++)
    {
        //  std::cout << "\nposcion x: " << triples[i]["x"].asString()<<"\t";
        //  std::cout << "\nposcion y: " << triples[i]["y"].asString()<<"\n";
    }
    const Json::Value &diccionario = objJson["diccionario"];
    for (int i = 0; i < diccionario.size(); i++)
    {
        //std::cout << "\nposcion x: " << triples[i]["x"].asString()<<"\t";
        
    }
}

bool File::dotGraphGenerator(string namefile, string textGraphviz)
{
    string stringTmp = "dot -Tpng " + namefile +".dot -o " + namefile + ".png";
    string comandDisplay = "display " + namefile + ".png &";

    if (createOrWriteFile(namefile + ".dot", textGraphviz))
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

File::~File()
{
}