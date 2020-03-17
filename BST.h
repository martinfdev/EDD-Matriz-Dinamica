/* 
 * File:   BTS.h
 * Author: pedro
 */
#ifndef BST_H
#define BST_H
#include <string>
#include "NodeT.h"
#include "NodeT.cpp"

using namespace std;

template <class T>
class BST
{
public:
    BST();
    ~BST();
    void insert(T);
    void preorder();
    void inorder();
    void postorder();
    NodeT<T>* search(T);

private:
    NodeT<T>* root;
    NodeT<T>* insertRec(NodeT<T>*, T);//insercion de forma recursiva
    NodeT<T>* deleteRec(NodeT<T>*, T);//elimina de forma recursiva
    NodeT<T>* searchIn(NodeT<T>*, T);
    void inorderRec(NodeT<T>*);
    void postorderRec(NodeT<T>*);
    void preorderRec(NodeT<T>*);
};
#endif //BST_H