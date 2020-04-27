/* 
 * File:   BST.h
 * Author: pedro
 */
#include "BST.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//constructor por defecto del ABB
//template <typename T>
BST::BST()
{
    graph = new Graphviz();
    sizeU = 0;
    ListaCuser = new Lista<Jugador*>();
    repeatData = false;
}

//metodo para busacar en el arbol privado
//template <typename T>
NodeT<Jugador *> *BST::searchIn(NodeT<Jugador *> *root, string data)
{
    //caso base la raiz es nula o el dato esta presente
    if (root == nullptr || root->getData()->getName() == data)
    {
        return root;
    }
    // el valor de del rado de la raiz es mayor que el dato buscado
    if (root->getData()->getName() > data)
    {
        return searchIn(root->getLeft(), data);
    }
    return searchIn(root->getRight(), data);
}

//metodo privado para insertar un nodo de forma recursiva
//template <typename T>
NodeT<Jugador*> *BST::insertRec(NodeT<Jugador *> *root, string data)
{
    /*si el arbol esta vacio retorna un nuevo nodo*/
    if (root == nullptr)
    {
        Jugador *tempData = new Jugador(data);
        root = new NodeT<Jugador *>(tempData);
        ListaCuser->add_endC(tempData);
        sizeU++;
    } /*de lo contrario, recorrer el arbol*/
    else if (data < root->getData()->getName())
    {
        root->setLeft(insertRec(root->getLeft(), data));
    }
    else if (data > root->getData()->getName())
    {
        root->setRight(insertRec(root->getRight(), data));
    }
    else
    {
        repeatData = true;
        //cout << data << " este dato esta repetido\n";
        // throw new exception_ptr;
    }

    /*Retorna el nodo puntero*/
    return root;
}

//metodo para eliminar de forma recursiva
//template <typename T>
NodeT<Jugador *> *BST::deleteRec(NodeT<Jugador *> *root, string data)
{
    //caso base el arbol esta vacio
    if (root == nullptr)
        return root;
    //de lo contrario recorrer el arbol
    if (data < root->getData()->getName())
    {
        root->setLeft(deleteRec(root->getLeft(), data));
    }
    else if (data > root->getData()->getName())
    {
        root->setRight(deleteRec(root->getRight(), data));
    }
    else
    {
        //si la llave es la misma que la raiz eliminar
        if (root->getLeft() == nullptr)
        {
            return root->getRight();
        }
        else if (root->getRight() == nullptr)
        {
            return root->getLeft();
        }
        else
        {
            //nodo con dos hijos: obtener con inorder el sucesor (pequeno)
            //en el lado derecho del arbol)
            root->getData(); //pendiente de hacer........
        }
    }
    return root;
}

//metodo privado recorrido de forma inorder
//template <typename T>
void BST::inorderRec(NodeT<Jugador *> *root)
{
    if (root != nullptr)
    {
        inorderRec(root->getLeft());
        lista->add_endS(root->getData()->getName());        
        inorderRec(root->getRight());
    }
}

//metodo privado recorrido de forma pre-orden
//template<typename T>
void BST::preorderRec(NodeT<Jugador *> *root)
{
    if (root != nullptr)
    {
        //cout << root->getData()->getName() << "-->";
        lista->add_endS(root->getData()->getName());
        preorderRec(root->getLeft());
        preorderRec(root->getRight());
    }
}

//metodo privado recorrido de forma pos-torden
//template<typename T>
void BST::postorderRec(NodeT<Jugador *> *root)
{
    if (root != nullptr)
    {
        postorderRec(root->getLeft());
        postorderRec(root->getRight());
        lista->add_endS(root->getData()->getName());
    }
}

//metodo publico para insertar
//template<typename T>
void BST::insert(string data)
{
    repeatData = false;
    root = insertRec(root, data);
}

//metodo publico para buscar
//template<typename T>
Jugador *BST::search(string data)
{
    return searchIn(root, data)->getData();
}

//metodo publico para recorrido pre-orden
//template<typename T>
void BST::preorder()
{   lista = new Lista<string>();
    preorderRec(root);
    lista->graphStringS("PreOrden"); 
}

//metodo publico para recorrido inorder
//template<typename T>
void BST::inorder()
{
    lista = new Lista<string>();
    inorderRec(root);
    lista->graphStringS("Inorden");
}

//metodo publico para recorrido inorder
//emplate<typename T>
void BST::postorder()
{
    lista = new Lista<string>();
    postorderRec(root);
    lista->graphStringS("PostOrden");
   
}

//metodo privado para graficar el arbol
void BST::reportRe(NodeT<Jugador *> *root)
{
    static int count = 0;
    if (root != nullptr)
    {
        if (root->getLeft())
        {
            graph->addln(root->getData()->getName() + " -> " + root->getLeft()->getData()->getName()+";");
            reportRe(root->getLeft());
        }
        else
        {
            graph->addln("null"+to_string(count)+" [shape=point];");
            graph->addln(root->getData()->getName()+ "-> null"+to_string(count)+";");
            count++;
        }
        if (root->getRight())
        {
            graph->addln(root->getData()->getName() + " -> " + root->getRight()->getData()->getName());
            reportRe(root->getRight());
        }
        else
        {
            graph->addln("null"+to_string(count)+" [shape=point];");
            graph->addln(root->getData()->getName() +" -> null"+to_string(count)+";");
            count++;
        }
    }
}

//metodo publico para graficar el arbol
void BST::report()
{
    graph->addln(graph->start_graph());
    graph->addln("node[fontname=\"Arial\", color=\"blue\"]");
    graph->addln("edge [color=\"green\"]");
    reportRe(root);
    graph->addln(graph->end());
    graph->dotGraphGenerator("Arbol", graph->getDotSource());
}

//metodo que devuelve el tamanio de los nodos en el arbol
int BST::getSize(){return sizeU;}

//metodo que devuelve una lista simple circular de jugadores
Lista<Jugador*> *BST::listaU(){
    return ListaCuser;
}

//devuelve un true si el dato esta repetido
bool BST::dataExist(){return repeatData;}

//destructor
//template <typename T>
BST::~BST() {}