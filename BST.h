/* 
 * File:   BTS.h
 * Author: pedro
 */
#ifndef BST_H
#define BST_H
#include <string>
#include "NodeT.h"
#include "Jugador.h"
#include "Graphviz.h"
#include "Lista.h"

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
    Jugador *search(string);
    void report();
    int getSize();
    bool dataExist();
    Lista<Jugador *> *listaU();

private:
    bool repeatData;
    int sizeU;
    Lista<string> *lista;
    Lista<Jugador *> *ListaCuser;
    Graphviz *graph;
    NodeT<Jugador *> *root;
    NodeT<Jugador *> *insertRec(NodeT<Jugador *> *, string); //insercion de forma recursiva
    NodeT<Jugador *> *deleteRec(NodeT<Jugador *> *, string); //elimina de forma recursiva
    NodeT<Jugador *> *searchIn(NodeT<Jugador *> *, string);
    void inorderRec(NodeT<Jugador *> *);
    void postorderRec(NodeT<Jugador *> *);
    void preorderRec(NodeT<Jugador *> *);
    void reportRe(NodeT<Jugador *> *);
};
#endif //BST_H