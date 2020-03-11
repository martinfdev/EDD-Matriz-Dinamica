/* 
 * File:   ListaDoble.cpp
 * Author: pedro
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include "ListaDoble.h"

using namespace std;

//constructor por defecto
template <typename T>
ListaDoble<T>::ListaDoble()
{
}
//metodo privado que espera como parametro un nodo n y el dato insertando al inicio de la lista
template <typename T>
void ListaDoble<T>::insertarInicio(Node<T> *n, T data)
{
    Node<T> *nuevo = new Node<T>(data);
    if (primero == NULL)
    {
        primero = ultimo = nuevo;
        size++;
    }
    else if (n == primero)
    {
        nuevo->setNext(nuevo);
        primero->setBehind(nuevo);
        primero = nuevo;
        size++;
    }
    else
    {
        n->getBehind()->setNext(nuevo);
        nuevo->setBehind(n->getBehind());
        n->setBehind(nuevo);
        nuevo->setNext(n);
        size++;
    }
}

//metodo privado que espera como parametro un nodo n y el dato insertando al final de la lista
template <typename T>
void ListaDoble<T>::insertarFinal(Node<T> *n, T data)
{
    Node<T> *nuevo = new Node<T>(data);
    if (ultimo == nullptr)
    {
        //cout<<(ultimo==nullptr)<<"\n";
        ultimo = nuevo;
        primero = nuevo;
        size++;
    }
    else if (ultimo == n)
    {
        //cout<<data<<"\n";
        nuevo->setBehind(ultimo);
        ultimo->setNext(nuevo);
        ultimo = nuevo;
        size++;
    }
    else
    {
        n->getNext()->setBehind(nuevo);
        nuevo->setNext(n->getNext());
        n->setNext(nuevo);
        nuevo->setBehind(n);
        size++;
    }
}

//metodo privado que insertar de forma cicular al inicio recibe como parametro Un nodo y un dato
template <typename T>
void ListaDoble<T>::insertarInicioC(Node<T> *n, T data, bool inicio)
{
    Node<T> *nuevo = new Node<T>(data);
    if (primero == NULL)
    {
        primero = nuevo;
        primero->setNext(nuevo);
        primero->setBehind(nuevo);
        size++;
    }
    else
    {
        n->getBehind()->setNext(nuevo);
        nuevo->setBehind(n->getBehind());
        n->setBehind(nuevo);
        nuevo->setNext(n);
        size++;
    }
    if (inicio)
    {
        primero = nuevo;
        size++;
    }
}

//metodo publico que inserta al inicio pide como parametro unicamente el dato a insertar en la lista
template <typename T>
void ListaDoble<T>::insertarPrimero(T data)
{
    insertarInicio(primero, data);
}

//metodo publico que inserta al final pide como parametro unicamente el dato a insertar en la lista
template <typename T>
void ListaDoble<T>::insertarUltimo(T data)
{
    insertarFinal(ultimo, data);
}

//metodo publico que insertar al principio de la lista tipo circular
template <typename T>
void ListaDoble<T>::InsertarPrimeroC(T data)
{
    insertarInicioC(primero, data, true);
}

//metodo publico que insertar al final de la lista tipo circular
template <typename T>
void ListaDoble<T>::insertarUltimoC(T data)
{
    insertarInicioC(primero, data, true);
}

//metodo privado que espera como parameto un nodo n para eliminarlo de la lista
template <typename T>
void ListaDoble<T>::borrarNodo(Node<T> *n)
{
    if (isEmpty())
    {
        //list is empty
    }
    else if (primero == ultimo)
    {
        primero = NULL;
        ultimo = NULL;
        size--;
    }
    else if (primero == n)
    {
        primero = primero->getNext();
        primero->setBehind(NULL);
        size--;
    }
    else if (ultimo == n)
    {
        ultimo = ultimo->getBehind();
        ultimo->setNext(NULL);
        size--;
    }
    else
    {
        n->getBehind()->setNext(n->getNext());
        n->getNext()->setBehind(n->getBehind());
        size--;
    }
}

/*metodo publico que espera como parameto el dato, llama al metodo puscar el cual devuelve
 el nodo para eliminarlo de la lista
*/
template <typename T>
void ListaDoble<T>::borrarParametro(T data)
{
    borrarNodo(buscar(data));
}

/*metodo publico que elimina al inicio de la lista*/
template <typename T>
void ListaDoble<T>::borrarInicio()
{
    borrarNodo(primero);
}

/*metodo publico que elimina al final de la lista*/
template <typename T>
void ListaDoble<T>::borrarFinal()
{
    borrarNodo(ultimo);
}

//meto que busca en la lista por parametro y devuelve un nodo
template <typename T>
Node<T> *ListaDoble<T>::buscar(T data)
{
    if (isEmpty())
    {
        std::cout << "Lista vacia\n";
    }
    else
    {
        Node<T> *aux = primero;
        while (aux != NULL)
        {
            if (aux->getData() == data)
            {
                return aux;
            }
            aux = aux->getNext();
        }
    }
}

//metodo publico que devuelve un booleano si la lista esta vacia
template <typename T>
bool ListaDoble<T>::isEmpty()
{
    if (primero == NULL)
    {
        return true;
    }
    return false;
}

//metodo publico que devuelve el tamanio actual de la lista
template <typename T>
int ListaDoble<T>::getSize()
{
    return size;
}

//metodo publico que imprime la lista
template <typename T>
void ListaDoble<T>::show()
{
    if (isEmpty())
    {
        std::cout << "Lista vacia\n";
    }
    else
    {

        Node<T> *aux = primero;
        while (aux != NULL)
        {
            std::cout << aux->getData() << "->";
            aux = aux->getNext();
        }
        std::cout << "\n";
    }
}

//metodo de la lista que imprime la lista tipo circular
template <typename T>
void ListaDoble<T>::showC()
{
    if (isEmpty())
    {
        std::cout << "Lista vacia\n";
    }
    else
    {
        Node<T> *aux = primero;
        do
        {
            std::cout << aux->getData() << "->";
            aux = aux->getNext();
        } while (aux != primero);
         std::cout << "\n";
    }
}

//destructor de la lista
template <typename T>
ListaDoble<T>::~ListaDoble()
{
}