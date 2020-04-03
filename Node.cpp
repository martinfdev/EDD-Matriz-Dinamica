/* 
 * File:   Node.cpp
 * Author: pedro
 */

#include <string>
#include "Node.h"

//constructor por defecto
template<typename T>
Node<T>::Node(){

}

//constuctor con parametro
template<typename T>
Node<T>::Node(T data){
    this->data = data;
    next = behind = nullptr;
}

//setters
template<typename T>
void  Node<T>::setNext(Node<T>* next){
    this->next = next;
}
template<typename T>
void Node<T>::setBehind(Node<T>* behind){
    this->behind = behind;
}
//getters
template<typename T>
Node<T>* Node<T>::getNext(){
    return next;
}

template<typename T>
Node<T>* Node<T>::getBehind(){
    return behind;
}

template<typename T>
T Node<T>::getData(){
    return data;
}

//delete
template<typename T>
Node<T>::~Node(){}