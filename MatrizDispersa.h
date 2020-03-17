
#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "NodeM.h"
using std::string;

class MatrizDispersa
{
private:
    NodeM *root;
    int sizeX, sizeY;
    NodeM* search_Row_Column(NodeM *, int);
    void insertSortRow(NodeM*, int);
    void insertSortColumn(NodeM*, int);
    void show(NodeM*);
    void insertNode(NodeM*, NodeM*, NodeM*);
    NodeM* lastNodeColumn(NodeM*);
    NodeM* lastNodeRow(NodeM*);

public:
    MatrizDispersa(/* args */);
    void insertMatrix(int, int, string);
    bool isEmpty();
    int getSizeX();
    int getSizeY();  
    void showY();
    void showX();
    void showMatrix();
    NodeM *search(int);

    ~MatrizDispersa();
};
#endif
