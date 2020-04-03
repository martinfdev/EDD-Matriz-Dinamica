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
    Graphviz *graph;

public:
    Reporte(/* args */);
    void ReporteFichas(Lista<Ficha *> *listaFichas);
    ~Reporte();
};
#endif //REPORTE_H