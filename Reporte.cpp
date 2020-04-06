/* 
 * File:  Reporte.cpp
 * Author: pedro
 */
#include "Reporte.h"

Reporte::Reporte(/* args */)
{
    graph = new Graphviz();
}

//metodo para hacer reporte de las fichas
void Reporte::ReporteFichasCola(Lista<Ficha *> *listaFicha)
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
            node = node + " " + temp->getLetra() + " x " + to_string(temp->getPuntaje()) + "pts";
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

//reporte de fichas de usuario en el juego
void Reporte::ReporteFichasUsuario(ListaDoble<Ficha *> *lisfichasUsuario, string nombre)
{   
    iterador++;
    graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("rankdir=LR;");
    graph->addln("node [shape=record, color=blue, width=0.5, height=0.5]; ");
    graph->addln();
    graph->addln(nombre);
    string nodos, enlaces, enlacesIverso;
    for (int i = 0; i < lisfichasUsuario->getSize(); i++)
    {
        Ficha *tempF = lisfichasUsuario->getDataNext();
        if (i < lisfichasUsuario->getSize() - 1)
        {
            nodos = nodos + "node" + to_string(i) + " [label=\"{<a>|" + tempF->getLetra() + "|<b>}\"];\n";
            enlaces = enlaces + "node" + to_string(i) + ":b:c -> node" + to_string(i + 1) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
            enlacesIverso = enlacesIverso + "node" + to_string(i + 1) + ":a:c -> node" + to_string(i) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
        }
        else
        {
            nodos = nodos + "node" + to_string(i) + " [label=\"{<a>|" + tempF->getLetra() + "|<b>}\"];\n";
        }
    }
    graph->addln(nodos);
    graph->addln(enlaces);
    graph->addln(enlacesIverso);
    graph->addln(graph->end());
    graph->dotGraphGenerator("ListaDobleFichasUsuario"+to_string(iterador), graph->getDotSource());
    delete graph;
}

Reporte::~Reporte()
{
}
