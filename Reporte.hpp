/* 
 * File:  Reporte.hpp
 * Author: pedro
 */
#include <string>
#include "Lista.h"
#include "Ficha.hpp"
#include "Graphviz.h"

using namespace std;

class Reporte
{
private:
    Graphviz *graph;

public:
    Reporte(/* args */);
    void ReporteFichas(Lista<Ficha *> *listaFichas);
    ~Reporte();
};

Reporte::Reporte(/* args */)
{
    graph = new Graphviz();
}

//metodo para hacer reporte de las fichas
void Reporte::ReporteFichas(Lista<Ficha *> *listaFicha)
{
    graph->addln(graph->start_graph());
    graph->addln("node[shape=record]");
    string node = "struct [label=\"{";
    int tamanioLista = listaFicha->size();
    for (int i = 0; i < tamanioLista; i++)
    {
        Ficha *temp = listaFicha->getData();
        if (i == 0)
        {
            node = node + " " + temp->getLetra() + " x " + to_string(temp->getPuntaje()) +"pts";
        }
        else
        {
            node = node + " |" + temp->getLetra() + " x " + to_string(temp->getPuntaje()) + "pts";
        }
    }
    node = node + "}\"];";
    graph->addln(node);
    graph->addln(graph->end());
    graph->dotGraphGenerator("ColaFichas", graph->getDotSource());
}

Reporte::~Reporte()
{
}
