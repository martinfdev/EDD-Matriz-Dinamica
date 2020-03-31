/* 
 * File:   Lista.h
 * Author: pedro
 */
#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Node.h"
#include "Graphviz.h"

using namespace std;

template <class T>
class Lista
{
    public:
        Lista();
        void add_headS(T); //S al final significa simple pa una lista simplemente enlazada
        void add_endS(T);
        void add_sort(T);
        void add_endC(T);
        void del_headS();
        void del_all();
        void graphStringS(string);
        void graphStringC(string);
        Node<T>* search(T);
        int size(){return sizeL;}
        bool isEmptyS();
        bool isEmptyC();
        void add_sortInvert(T);
        T getData();
        ~Lista();

    private:
        Graphviz *graph;
        Node<T> *m_head;
        Node<T> *m_last;
        int sizeL;
        Node<T>* searchAll(Node<T>*, T);
};
#endif // LISTA_H