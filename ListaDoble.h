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
#include "Node.cpp"
#include "Graphviz.h"

using std::string;

template <class T>
class ListaDoble
{
public:
    ListaDoble();
    void insertarPrimero(T);
    void insertarUltimo(T);
    void insertarUltimoC(T);
    void InsertarPrimeroC(T);
    void borrarParametro(T);
    void insertarPorPosicion(); //pendiente de impelementar
    void eliminarPorPosicion(); //pendiente de implementar
    int getSize();
    void borrarInicio();
    void borrarFinal();
    void showC();
    Node<T>* buscarC(T);
    Node<T> *buscar(T);
    void show();
    bool isEmpty();
    void reportS();
    void reportIntC(string);
    void reportStringC(string);
    void reportStringS(string);
    void reportIntS(string);
    virtual ~ListaDoble();

private:
    int size;
    Node<T> *primero;
    Node<T> *ultimo;
    void insertarInicio(Node<T> *, T);
    void insertarFinal(Node<T> *, T);
    void borrarNodo(Node<T> *);
    void insertarC(Node<T> *, T, bool);
};

#endif /* LISTADOBLE_H */
