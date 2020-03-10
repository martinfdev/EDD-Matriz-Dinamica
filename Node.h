/* 
 * File:   LinkedDoubleList.h
 * Author: pedro
 */
#ifndef NODE_H
#define NODE_H
#include <string>

using std::string;

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
    ~Node();
    private:
    T data;
    Node* next;
    Node* behind;
};

#endif /*NODE H*/