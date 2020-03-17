/* 
 * File:   BTS.h
 * Author: pedro
 */
#include <stdlib.h>
#include <string>
#include <iostream>
#include "BST.h"


using namespace std;

//constructor por defecto del ABB
template <typename T>
BST<T>::BST()
{
}

//metodo para busacar en el arbol
template <typename T>
NodeT<T> *BST<T>::searchIn(NodeT<T> *root, T data)
{
    //caso base la raiz es nula o el dato esta presente
    if (root==nullptr || root->getData()==data)
    {
        return root;
    }
    // el valor de del rado de la raiz es mayor que el dato buscado
    if (root->getData()>data)
    {
        return search(root->getLeft(), data);
    }
    return search(root->getRight(), data);
}

//metodo privado para insertar un nodo de forma recursiva
template <typename T>
NodeT<T> *BST<T>::insertRec(NodeT<T> *root, T data)
{
    /*si el arbol esta vacio retorna un nuevo nodo*/
    if (root == nullptr)
    {
        root = new NodeT<T>(data);
    } /*de lo contrario, recorrer el arbol*/
    else if (data < root->getData())
    {
        root->setLeft(insertRec(root->getLeft(), data));
    }
    else if (data >root->getData())
    {
        root->setRight(insertRec(root->getRight(), data));
    }else{
        cout<<data<<" este dato esta repetido\n";
       // throw new exception_ptr;
    } 
    
    /*Retorna el nodo puntero*/
    return root;
}

//metodo para eliminar de forma recursiva
template <typename T>
NodeT<T> *BST<T>::deleteRec(NodeT<T> *root, T data)
{
    //caso base el arbol esta vacio
    if (root == nullptr)
        return root;
    //de lo contrario recorrer el arbol
    if (data < root->getData())
    {
        root->setLeft(deleteRec(root->getLeft(), data));
    }
    else if (data > root->getData())
    {
        root->setRight(root->getRight(), data);
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
template <typename T>
void BST<T>::inorderRec(NodeT<T> *root)
{
    if (root != nullptr)
    {
        inorderRec(root->getLeft());
        cout << root->getData() << "-->";
        inorderRec(root->getRight());
    }
}

//metodo privado recorrido de forma pre-orden
template<typename T>
void BST<T>::preorderRec(NodeT<T>* root){
    if (root!=nullptr)
    {
        cout<<root->getData()<<"-->";
        preorderRec(root->getLeft());
        preorderRec(root->getRight());
    }
}

//metodo privado recorrido de forma pos-torden
template<typename T>
void BST<T>::postorderRec(NodeT<T>* root){
    if (root!=nullptr)
    {
        postorderRec(root->getLeft());
        postorderRec(root->getRight());
        cout<<root->getData()<<"-->";
    }
}

//metodo publico para insertar 
template<typename T>
void BST<T>::insert(T data){
    root = insertRec(root, data);
}

//metodo publico para buscar
template<typename T>
NodeT<T>* BST<T>::search(T data){
    return searchIn(root, data);
}

//metodo publico para recorrido ipre-orden
template<typename T>
void BST<T>::preorder(){
    preorderRec(root);
    cout<<"\n";//salto de linea cuando se sale recorrido
}

//metodo publico para recorrido inorder
template<typename T>
void BST<T>::inorder(){
    inorderRec(root);
    cout<<"\n";//salto de linea cuando se recorrido
}

//metodo publico para recorrido inorder
template<typename T>
void BST<T>::postorder(){
    postorderRec(root);
    cout<<"\n";//salto de linea cuando se sale del recorrido
}

//destructor
template <typename T>
BST<T>::~BST() {}