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
    //lista vacia
    if (primero == NULL)
    {
        primero = ultimo = nuevo;
        size++;
    }
    //insertar al inicio
    else if (n == primero)
    {
        nuevo->setNext(primero);
        primero->setBehind(nuevo);
        primero = nuevo;
        size++;
    }
    //insertar antes de un nodo dado
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
    //lista esta vacia
    if (ultimo == nullptr)
    {
        primero = ultimo = nuevo;
        size++;
    }
    //insertar al final
    else if (n == ultimo)
    {
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

//metodo privado que inserta de forma cicular al inicio recibe como parametro Un nodo, dato y un bool si es verdadero inserta al inicio falso inserta al final
template <typename T>
void ListaDoble<T>::insertarC(Node<T> *n, T data, bool inicio)
{
    Node<T> *nuevo = new Node<T>(data);
    //inserta un elemento a final de la lista
    if (primero == NULL)
    {
        primero = nuevo;
        primero->setNext(nuevo);
        primero->setBehind(nuevo);
    }
    else
    {
        //insertar antes de un nodo dado
        n->getBehind()->setNext(nuevo);
        nuevo->setBehind(n->getBehind());
        n->setBehind(nuevo);
        nuevo->setNext(n);
    }
    //inicio verdadeto inserta al principio de la lista
    if (inicio)
    {
        primero = nuevo;
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
    insertarC(primero, data, true);
    size++;
}

//metodo publico que insertar al final de la lista tipo circular
template <typename T>
void ListaDoble<T>::insertarUltimoC(T data)
{
    insertarC(primero, data, false);
    size++;
}

//metodo privado que espera como parameto un nodo n para eliminarlo de la lista
template <typename T>
void ListaDoble<T>::borrarNodo(Node<T> *n)
{
    //la lista esta vacia
    if (isEmpty())
    {
        //list is empty
    }
    //solo existe un nodo
    else if (primero == ultimo)
    {
        primero = NULL;
        ultimo = NULL;
        size--;
    }
    //eliminar al inicio
    else if (primero == n)
    {
        primero = primero->getNext();
        primero->setBehind(NULL);
        size--;
    }
    //eliminar al final
    else if (ultimo == n)
    {
        ultimo = ultimo->getBehind();
        ultimo->setNext(NULL);
        size--;
    }
    else
    {
        //eliminar en medio
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

//metodo para graficar un reporte de la lista doble en graphviz
template <typename T>
void ListaDoble<T>::reportS()
{
}

//metodo que genera una grafica de la lista doble circular enteros o double o float
template <typename T>
void ListaDoble<T>::reportIntC(string nameDot)
{
    Graphviz *graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("rankdir=LR;");
    graph->addln("node [shape=record, color=blue, width=0.5, height=0.5]; ");
    // graph->addln("edge [tailclip=false];");
    // graph->addln("graph[ nodesep = 0.5]; ");
    graph->addln();
    int contador = 0;
    string nodos, enlaces, enlacesIverso;
    if (!isEmpty())
    {
        Node<T> *aux = primero;
        do
        {
            if (contador < size - 1)
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + to_string(aux->getData()) + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(contador + 1) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(contador + 1) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            else
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + to_string(aux->getData()) + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(0) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(0) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            contador++;
            aux = aux->getNext();
        } while (aux != primero);
    }
    graph->addln(nodos);
    graph->addln(enlaces);
    graph->addln(enlacesIverso);
    graph->addln(graph->end());
    graph->dotGraphGenerator(nameDot, graph->getDotSource());
}

//metodo que genera grafica de lista doble circular de string
template <typename T>
void ListaDoble<T>::reportStringC(string nameDot)
{
    Graphviz *graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("rankdir=LR;");
    graph->addln("node [shape=record, color=blue, width=0.5, height=0.5]; ");
    // graph->addln("edge [tailclip=false];");
    // graph->addln("graph[ nodesep = 0.5]; ");
    graph->addln();
    int contador = 0;
    string nodos, enlaces, enlacesIverso;
    if (!isEmpty())
    {
        Node<T> *aux = primero;
        do
        {
            if (contador < size - 1)
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + aux->getData() + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(contador + 1) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(contador + 1) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            else
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + aux->getData() + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(0) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(0) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            contador++;
            aux = aux->getNext();
        } while (aux != primero);
    }
    graph->addln(nodos);
    graph->addln(enlaces);
    graph->addln(enlacesIverso);
    graph->addln(graph->end());
    graph->dotGraphGenerator(nameDot, graph->getDotSource());
}

//metodo para graficar lista doble enlazada simple de int, double, o float
template <typename T>
void ListaDoble<T>::reportIntS(string nameDot)
{
    Graphviz *graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("rankdir=LR;");
    graph->addln("node [shape=record, color=blue, width=0.5, height=0.5]; ");
    graph->addln();
    int contador = 0;
    string nodos, enlaces, enlacesIverso;
    if (!isEmpty())
    {
        Node<T> *aux = primero;
        while (aux != nullptr)
        {
            if (contador < size - 1)
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + to_string(aux->getData()) + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(contador + 1) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(contador + 1) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            else
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + to_string(aux->getData()) + "|<b>}\"];\n";
            }
            contador++;
            aux = aux->getNext();
        }
    }
    graph->addln(nodos);
    graph->addln(enlaces);
    graph->addln(enlacesIverso);
    graph->addln(graph->end());
    graph->dotGraphGenerator("LitaDoble", graph->getDotSource());
}

//metodo para grafica lista doble enlazada simple de strings
template <typename T>
void ListaDoble<T>::reportStringS(string nameDot)
{
    Graphviz *graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("rankdir=LR;");
    graph->addln("node [shape=record, color=blue, width=0.5, height=0.5]; "); 
    graph->addln();
    int contador = 0;
    string nodos, enlaces, enlacesIverso;
    if (!isEmpty())
    {
        Node<T> *aux = primero;
        while (aux != nullptr)
        {
            if (contador < size - 1)
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + aux->getData() + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(contador + 1) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(contador + 1) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            else
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + aux->getData() + "|<b>}\"];\n";
            }
            contador++;
            aux = aux->getNext();
        }
    }
    graph->addln(nodos);
    graph->addln(enlaces);
    graph->addln(enlacesIverso);
    graph->addln(graph->end());
    graph->dotGraphGenerator("LitaDoble", graph->getDotSource());
}

//destructor de la lista
template <typename T>
ListaDoble<T>::~ListaDoble()
{
}