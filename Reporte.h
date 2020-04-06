/* 
 * File:  Reporte.h
 * Author: pedro
 */

#ifndef REPORTE_H
#define REPORTE_H
#include <string>
#include "Lista.h"
#include "Ficha.h"
#include "Graphviz.h"

using namespace std;

class Reporte
{
private:
    int iterador;
    Graphviz *graph;

public:
    Reporte(/* args */);
    void ReporteFichasCola(Lista<Ficha *> *listaFichas);
    void ReporteFichasUsuario(ListaDoble<Ficha *> *lisFichasUsuario, string);
    ~Reporte();
};
#endif //REPORTE_H