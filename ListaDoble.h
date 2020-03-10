/* 
 * File:   ListaDoble.h
 * Author: pedro
 */
#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Node.h"

using std::string;

template <class T>
class ListaDoble
{
public:
    ListaDoble();
    void insertarPrimero(T);
    void insertarUltimo(T);
    void borrarParametro(T);
    void insertarPorPosicion(); //pendiente de impelementar
    void eliminarPorPosicion(); //pendiente de implementar
    int getSize();
    void borrarInicio();
    void borrarFinal();
    Node<T> *buscar(T);
    void show();
    bool isEmpty();
    virtual ~ListaDoble();

private:
    int size;
    Node<T> *primero;
    Node<T> *ultimo;
    void insertarInicio(Node<T> *, T);
    void insertarFinal(Node<T> *, T);
    void borrarNodo(Node<T> *);
};

#endif /* LISTADOBLE_H */
