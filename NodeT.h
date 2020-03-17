/* 
 * File:   NodeT.h
 * Author: pedro
 */
#ifndef NODET_H
#define NODET_H
#include <iostream>
#include <string>

using namespace std;

template<class T>
class NodeT
{
private:
    T data;
    NodeT* left;
    NodeT* right;

public:
    NodeT();
    NodeT(T);
    void setLeft(NodeT<T>*);
    void setRight(NodeT<T>*);
    void setData(T);
    NodeT<T>* getRight();
    NodeT<T>* getLeft();
    T getData();
    ~NodeT();
};
#endif //NODE_H