/* 
 * File:   NodeT.cpp
 * Author: pedro
 */
#include <iostream>
#include <stdlib.h>
#include <string>
#include "NodeT.h"

using namespace std;

//constructor sin paramentros
template<typename T>
NodeT<T>::NodeT(){
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}

//constructor que pide un parametro T
template<typename T>
NodeT<T>::NodeT(T data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

//setters an getter metods
template<typename T>
void NodeT<T>::setLeft(NodeT<T>* left){
    this->left = left;
}

template<typename T>
void NodeT<T>::setRight(NodeT<T>* right){
    this->right = right;
}

template<typename T>
void NodeT<T>::setData(T data){this->data = data;}

template<typename T>
NodeT<T>* NodeT<T>::getLeft(){return left;}

template<typename T>
NodeT<T>* NodeT<T>::getRight(){return right;}

template<typename T>
T NodeT<T>::getData(){return data;}

//destructor
template<typename T>
NodeT<T>::~NodeT()
{
}
