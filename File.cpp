#include "File.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>

using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

File::File(/* args */)
{
}

bool File::createOrWriteFile(string nameFile, string textoAescribir)
{
    ofstream filOut;
    filOut.open(nameFile, ios::out | ios::app);
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
    const Json::Value& dimension = objJson["dimension"];
    std::cout<<"Dimension\t"<<dimension<<"\n";
    const Json::Value& casillas = objJson["casillas"];
    std::cout<<"casillas"<<"\n";    
    const Json::Value& dobles = casillas["dobles"];
    std::cout<<"dobles"<<"\n";
    for (int i = 0; i < dobles.size(); i++)
    {
        std::cout << "\nposcion x: " << dobles[i]["x"].asString()<<"\t";
        std::cout << "\nposcion y: " << dobles[i]["y"].asString()<<"\n";
    }
    const Json::Value& triples = casillas["triples"];
    std::cout<<"triples"<<"\n";
    for (int i = 0; i < triples.size(); i++)
    {
        std::cout << "\nposcion x: " << triples[i]["x"].asString()<<"\t";
        std::cout << "\nposcion y: " << triples[i]["y"].asString()<<"\n";
    }
}

File::~File()
{
}
