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
    T borrarParametro(T);
    void insertarPorPosicion(); //pendiente de impelementar
    void eliminarPorPosicion(); //pendiente de implementar
    int getSize();
    T borrarInicio();
    T borrarFinal();
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
    T getDataBack();
    T getDataNext();
    T getDataC();
    virtual ~ListaDoble();

private:
    int size;
    Node<T> *primero;
    Node<T> *ultimo;
    void insertarInicio(Node<T> *, T);
    void insertarFinal(Node<T> *, T);
    T borrarNodo(Node<T> *);
    void insertarC(Node<T> *, T, bool);
};

#endif /* LISTADOBLE_H */
