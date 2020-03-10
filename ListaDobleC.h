/* 
 * File:   ListaDobleC.h
 * Author: pedro
 */
#ifndef LISTADOBLEC_H
#define LISTADOBLEC_H
#include <iostream>

class ListaDobleC {

    class Nodo {
    public:
        Nodo(string palabra) {
            this->palabra = palabra;
        }

        void setSiguiente(Nodo* siguiente) {
            this->siguiente = siguiente;
        }

        Nodo* getSiguiente() {
            return siguiente;
        }

        void setAntrior(Nodo* anterior) {
            this->anterior = anterior;
        }

        Nodo* getAnterior() {
            return anterior;
        }

        void setpalabra(string palabra) {
            this->palabra = palabra;
        }

        string getpalabra() {
            return palabra;
        }

    private:
        string palabra;
        Nodo* siguiente;
        Nodo* anterior;
    };

public:
    ListaDobleC();
    void insertarPrimero(string);
    // void insertar(string);
    void insertarUltimo(string);
    //void insertarFinal(string);
    void borrarParametro(string);
    void insertarPorPosicion(); //pendiente de impelementar
    void eliminarPorPosicion(); //pendiente de implementar
    int getSize();
    void borrarInicio();
    void borrarFinal();
    Nodo* buscar(string);
    void show();
    bool isEmpty();
    virtual ~ListaDobleC();

private:
    long size;
    Nodo* primero;
    Nodo* ultimo;
    void insertarInicio(Nodo*, string);
    void insertarFinal(Nodo*, string);
    void borrarNodo(Nodo*);
};

#endif /* LISTADOBLEC_H */

