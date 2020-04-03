/* 
 * File.cpp
 * Author: pedro
 */
#include "File.h"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <jsoncpp/json/json.h>

using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

File::File()
{
}

File::File(ListaDoble<string>* dictionary_, Config *configI_){
    dictionary = dictionary_;
    configI = configI_;
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
        return "";
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

bool File::readJson(string json)
{
    
    Json::Reader r;
    Json::Value objJson;
    r.parse(json, objJson);
    // std::cout<<objJson;
    //botiene el valor de dimension
    int dimension = objJson["dimension"].asInt();
    configI->setDimension(dimension);
    
    //obtiene el valor de las casillas
    const Json::Value &casillas = objJson["casillas"];
    // std::cout<<"casillas"<<"\n";
    //obtiene el valor de las casillas dobles
    const Json::Value &dobles = casillas["dobles"];
    //std::cout<<"dobles"<<"\n";
    for (int i = 0; i < dobles.size(); i++)
    {
        int x = dobles[i]["x"].asInt();
        int y = dobles[i]["y"].asInt();
        configI->setCasillaE(x, y, 2);
        //   std::cout << "\nposcion x: " << dobles[i]["x"].asString()<<"\t";
        //   std::cout << "\nposcion y: " << dobles[i]["y"].asString()<<"\n";
    }
    //obtiene el valor de las casillas triples
    const Json::Value &triples = casillas["triples"];
    // std::cout<<"triples"<<"\n";
    for (int i = 0; i < triples.size(); i++)
    {
        int x = triples[i]["x"].asInt();
        int y = triples[i]["y"].asInt();
        configI->setCasillaE(x,y,3);
        //  std::cout << "\nposcion x: " << triples[i]["x"].asString()<<"\t";
        //  std::cout << "\nposcion y: " << triples[i]["y"].asString()<<"\n";
    }
    const Json::Value &diccionario = objJson["diccionario"];
    for (int i = 0; i < diccionario.size(); i++)
    {
        //std::cout << "\nposcion x: " << triples[i]["x"].asString()<<"\t";
        //std::cout << "\npalabra: " << diccionario[i]["palabra"].asString() << "\n";
        dictionary->insertarUltimoC(diccionario[i]["palabra"].asString());
    }
    return r.good();
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