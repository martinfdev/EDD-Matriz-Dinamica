/* 
 * File:   BTS.h
 * Author: pedro
 */
#ifndef BST_H
#define BST_H
#include <string>
#include "NodeT.h"
#include "NodeT.cpp"
#include "Jugador.h"
#include "Graphviz.h"


using namespace std;

//template <class >
class BST
{
public:
    BST();
    ~BST();
    void insert(string);
    void preorder();
    void inorder();
    void postorder();
    NodeT<Jugador*>* search(string);
    void report();

private:
    Graphviz *graph;
    NodeT<Jugador*>* root;
    NodeT<Jugador*>* insertRec(NodeT<Jugador*>*, string);//insercion de forma recursiva
    NodeT<Jugador*>* deleteRec(NodeT<Jugador*>*, string);//elimina de forma recursiva
    NodeT<Jugador*>* searchIn(NodeT<Jugador*>*, string);
    void inorderRec(NodeT<Jugador*>*);
    void postorderRec(NodeT<Jugador*>*);
    void preorderRec(NodeT<Jugador*>*);
    void reportRe(NodeT<Jugador*>*);
};
#endif //BST_H