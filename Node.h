/* 
 * File:   Node.h
 * Author: pedro
 */
#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
#include <stdlib.h> 

using namespace std;

template<class T>
class Node
{
public:
    Node();
    Node(T);
    void setNext(Node*);
    void setBehind(Node*);
    Node* getNext();
    Node* getBehind();
    T getData();
    ~Node();
    private:
    T data;
    Node* next;
    Node* behind;
};

#endif /*NODE H*/