/* 
 * File:   ListaDobleC.cpp
 * Author: pedro
 */
#include <iostream>
#include <string>
#include "ListaDobleC.h"

using std::string;

ListaDobleC::ListaDobleC() {
}

void ListaDobleC::insertarInicio(Nodo* n, string palabra) {
    Nodo* nuevo = new Nodo(palabra);
    
    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
        primero->setAntrior(ultimo);
        ultimo->setSiguiente(primero);
        size++;
    }else if (n==primero) {
        aux->setSiguiente(primero);
        primero->setAntrior(aux);
        primero = aux;
        size++;
    }else{
        n->getAnterior()->setSiguiente(aux);
        aux->setAntrior(n->getAnterior());
        n->setAntrior(aux);
        aux->setSiguiente(n);
        size++;
    }
}

void ListaDobleC::insertarFinal(Nodo* n, string palabra) {
     Nodo* aux = new Nodo(palabra);
    if (ultimo==NULL) {
        ultimo=aux;
        primero=aux;
        size++;
    }else if (ultimo == n) {
        aux->setAntrior(ultimo);
        ultimo->setSiguiente(aux);
        ultimo=aux;
        size++;
    }else{
        n->getSiguiente()->setAntrior(aux);
        aux->setSiguiente(n->getSiguiente());
        n->setSiguiente(aux);
        aux->setAntrior(n);
        size++;
    }
}

void ListaDobleC::insertarPrimero(string palabra) {
    insertarInicio(primero, palabra);
}

void ListaDobleC::insertarUltimo(string palabra) {
    insertarFinal(ultimo, palabra);
}

void ListaDobleC::borrarNodo(Nodo* n) {
    
    if (isEmpty()) {
        //list is empty
    }else if (primero==ultimo) {
        primero=NULL;
        ultimo=NULL;
        size--;
    }else if (primero==n) {
        primero = primero->getSiguiente();
        primero->setAntrior(NULL);
        size--;
    }else if (ultimo == n) {
        ultimo = ultimo->getAnterior();
        ultimo->setSiguiente(NULL);
        size--;
    }else{
        n->getAnterior()->setSiguiente(n->getSiguiente());
        n->getSiguiente()->setAntrior(n->getAnterior());
        size--;
    }
}

void ListaDobleC::borrarParametro(string palabra) {
    borrarNodo(buscar(palabra));
}

void ListaDobleC::borrarInicio() {
    borrarNodo(primero);
}

void ListaDobleC::borrarFinal() {
    borrarNodo(ultimo);
}

ListaDobleC::Nodo* ListaDobleC::buscar(string palabra) {
    if (isEmpty()) {
        std::cout<<"Lista vacia\n";
    }else{
        Nodo* aux= primero;
        while (aux!= NULL) {
            if (aux->getpalabra()==palabra) {
                return aux;
            }
            aux = aux->getSiguiente();
        }
        std::cout<<"\n";
    }
}

bool ListaDobleC::isEmpty() {
    if (primero==NULL) {
        return  true;
    }else if (ultimo ==NULL) {
        return true;
    }
    return false;
}

int ListaDobleC::getSize() {
    return size;
}


void ListaDobleC::show() {
    if (isEmpty()) {
        std::cout<<"Lista vacia\n";
    }else{
       
        Nodo* aux= primero;
        while (aux!=NULL) {
           std::cout<<aux->getpalabra()<<"->";
           aux = aux->getSiguiente(); 
        }
        std::cout<<"\n";
    }
}

ListaDobleC::~ListaDobleC() {
}



