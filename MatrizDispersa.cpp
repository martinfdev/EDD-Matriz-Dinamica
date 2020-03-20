#include <stdlib.h>
#include <string>
#include <iostream>
#include "MatrizDispersa.h"

using std::string;
MatrizDispersa::MatrizDispersa()
{
    root = new NodeM(-1, -1, "Nodo raiz no incluido");
    graph = new Graphviz();
}

void MatrizDispersa::insertMatrix(int x, int y, string cadena)
{
    //nodos temporales para comprobaciones e insercion
    NodeM *tmpY = search_Row_Column(root->getDown(), y);
    NodeM *tmpX = search_Row_Column(root->getRight(), x);

    //nuevo nodo de dato
    NodeM *new_node = new NodeM(x, y, cadena);

    if (tmpY == nullptr && tmpX == nullptr)
    {
        NodeM *newX = new NodeM(x, 0, "");
        NodeM *newY = new NodeM(0, y, "");
        insertSortRow(newY, y);
        insertSortColumn(newX, x);
        insertNode(newX, newY, new_node);
    }
    else if (tmpY == nullptr && tmpX != nullptr)
    {
        NodeM *newY = new NodeM(0, y, "");
        insertSortRow(newY, y);
        insertNode(tmpX, newY, new_node);
    }
    else if (tmpY != nullptr && tmpX == nullptr)
    {
        NodeM *newX = new NodeM(x, 0, "");
        insertSortColumn(newX, x);
        insertNode(newX, tmpY, new_node);
    }
    else if (tmpY != nullptr && tmpX != nullptr)
    {
        insertNode(tmpX, tmpY, new_node);
    }
}

//metodo privado insertar de forma ordenada en la columna
void MatrizDispersa::insertSortColumn(NodeM *newX, int x)
{
    //  NodeM* newX = new NodeM(x,0,"");
    NodeM *tmp = root;
    if (isEmpty())
    {
        tmp->setRight(newX);
        newX->setLeft(tmp);
        sizeX++;
    }
    else
    {
        while (tmp->getRight() != nullptr && tmp->getRight()->getX() < x)
        {
            tmp = tmp->getRight();
        }
        if (tmp->getRight() != nullptr)
        {
            newX->setRight(tmp->getRight());
            tmp->getRight()->setLeft(newX);
            tmp->setRight(newX);
            newX->setLeft(tmp);
            sizeX++;
        }
        else
        {
            tmp->setRight(newX);
            newX->setLeft(tmp);
            sizeX++;
        }
    }
}

//metodo privado para insertar ordenado en y
void MatrizDispersa::insertSortRow(NodeM *newY, int y)
{
    //  NodeM* newY = new NodeM(0,y,"");
    NodeM *tmp = root;
    if (isEmpty())
    {
        tmp->setDown(newY);
        newY->setUp(tmp);
        sizeY++;
    }
    else
    {
        while (tmp->getDown() != nullptr && tmp->getDown()->getY() < y)
        {
            tmp = tmp->getDown();
        }
        if (tmp->getDown() != nullptr)
        {
            newY->setDown(tmp->getDown());
            tmp->getDown()->setUp(newY);
            tmp->setDown(newY);
            newY->setUp(tmp);
            sizeY++;
        }
        else
        {
            tmp->setDown(newY);
            newY->setUp(tmp);
            sizeY++;
        }
    }
}

//devuelve un bool cuando la matriz no tiene comlumnas ni filas
bool MatrizDispersa::isEmpty()
{
    if (root->getRight() == nullptr && root->getDown() == nullptr)
    {
        return true;
    }
    return false;
}

//metodo privado para imprimir la matriz
void MatrizDispersa::show(NodeM *n)
{
    if (isEmpty())
    {
        std::cout << "matriz vacia\n";
    }
    else
    {
        if (n == root->getRight())
        {
            while (n != nullptr)
            {
                std::cout << n->getX() << "\n";
                n = n->getRight();
            }
        }
        else if (n == root->getDown())
        {
            while (n != nullptr)
            {
                std::cout << n->getY() << "\n";
                n = n->getDown();
            }
        }
    }
}

//metodo publico para imprimir columnaX temporal para debug
void MatrizDispersa::showX()
{
    if (!isEmpty())
    {
        show(root->getRight());
    }
}
//metodo publico para imprimir filaY temporal para debug
void MatrizDispersa::showY()
{
    if (!isEmpty())
    {
        show(root->getDown());
    }
}

//devuelve booleano verdadero si la columna o fila ya existe para no crearse de nuevo
NodeM *MatrizDispersa::search_Row_Column(NodeM *n, int position)
{
    if (root->getRight() == n)
    {
        while (n != nullptr)
        {
            if (n->getX() == position)
            {
                return n;
            }
            n = n->getRight();
        }
        return nullptr;
    }
    else if (root->getDown() == n)
    {
        while (n != nullptr)
        {
            if (n->getY() == position)
            {
                return n;
            }
            n = n->getDown();
        }
        return nullptr;
    }
}

//insertar en el indice indicado
void MatrizDispersa::insertNode(NodeM *x, NodeM *y, NodeM *dato)
{
    if (x->getDown() == nullptr && y->getRight() == nullptr)
    {
        x->setDown(dato);
        dato->setUp(x);
        y->setRight(dato);
        dato->setLeft(y);
        // std::cout <<x->getDown()->getY()<<" "<<x->getDown()->getX()<<"\n";
    }
    else if (x->getDown() != nullptr && y->getRight() == nullptr)
    {
        NodeM *tmpXposition = lastNodeColumn(x);
        dato->setUp(tmpXposition);
        tmpXposition->setDown(dato);
        y->setRight(dato);
        dato->setLeft(y);
        // std::cout << tmpXposition->getX() << " " << tmpXposition->getY() <<"\t"<<tmpXposition->getData()<< "\n";
    }
    else if (x->getDown() == nullptr && y->getRight() != nullptr)
    {
        NodeM *tmpYposition = lastNodeRow(y);
        dato->setLeft(tmpYposition);
        tmpYposition->setRight(dato);
        x->setDown(dato);
        dato->setUp(x);
        // std::cout << tmpYposition->getX() << " " << tmpYposition->getY() <<"\t"<<tmpYposition->getData()<< "\n";
    }
    else if (x->getDown() != nullptr && y->getRight() != nullptr)
    {
        NodeM *tmpXposition = lastNodeColumn(x);
        NodeM *tmpYposition = lastNodeRow(y);

        if (tmpXposition->getDown() == nullptr && tmpYposition->getRight() == nullptr)
        {
            dato->setUp(tmpXposition);
            tmpXposition->setDown(dato);
            dato->setLeft(tmpYposition);
            tmpYposition->setRight(dato);

            std::cout << tmpYposition->getX() << " " << tmpYposition->getY() << "\t" << tmpYposition->getData() << "\n";
        }
    }
}

//metodo recursivo que devuelve el ultimo nodo en columna por posicion
NodeM *MatrizDispersa::lastNodeColumn(NodeM *n)
{
    while (n->getDown() != nullptr)
    {
        n = n->getDown();
    }
    return n;
}

//metodo que devuelve el ultimo nodo en la fila por posicion
NodeM *MatrizDispersa::lastNodeRow(NodeM *n)
{
    while (n->getRight() != nullptr)
    {
        n = n->getRight();
    }
    return n;
}
//metodo que devuelven el tamanio de filas y columnas
int MatrizDispersa::getSizeX() { return sizeX; }
int MatrizDispersa::getSizeY() { return sizeY; }

//mostrar cotenido de la matriz
void MatrizDispersa::showMatrix()
{
    NodeM *tempY = root->getDown();
    NodeM *tempX;
    if (!isEmpty())
    {
        while (tempY != NULL)
        {
            tempX = tempY->getRight();
            while (tempX != NULL)
            {
                std::cout << tempX->getData() << "->";
                tempX = tempX->getRight();
            }
            std::cout << "\n";
            tempY = tempY->getDown();
        }
    }
}

//genera un reporte en graphviz
void MatrizDispersa::report()
{
    graph->addln(graph->start_graph());
    graph->addln("rankdir = TB;");
    graph->addln("node [shape=rectangle, color=blue, height=0.5, width=0.5];");
    graph->addln("edge [color= red];");
    graph->addln("graph[ nodesep = 0.5];");
    graph->addln("nodeXY [label=\"y\\\\x\"];");
    NodeM *tempY = root->getDown();
    NodeM *tempX = root->getRight();
    if (!isEmpty())
    {
        //recorrer encabezado X para porder agregarlos al dot
        string rankSameX = "{ rank=same; nodeXY; ";
        graph->addln("nodeXY -> nodeX" + to_string(tempX->getX()) + " [dir=both];");
        while (tempX != nullptr)
        {
            graph->addln("nodeX" + to_string(tempX->getX()) + " [label=\"X =" + to_string(tempX->getX()) + "\"];");
            rankSameX = rankSameX + "nodeX" + to_string(tempX->getX()) + "; ";
            if (tempX->getRight() != nullptr)
            {
                graph->addln("nodeX" + to_string(tempX->getX()) + " -> nodeX" + to_string(tempX->getRight()->getX()) + " [dir = both];");
            }
            tempX = tempX->getRight();
        }
        rankSameX = rankSameX + "}";
        graph->addln(rankSameX);

        //recorrer encabezado Y para porder agregarlos al dot
        graph->addln("nodeXY -> nodeY" + to_string(tempY->getY()) + " [dir=both];");
        while (tempY != nullptr)
        {
            graph->addln("nodeY" + to_string(tempY->getY()) + " [label=\"Y =" + to_string(tempY->getY()) + "\"];");
            if (tempY->getDown() != nullptr)
            {
                graph->addln("nodeY" + to_string(tempY->getY()) + " -> nodeY" + to_string(tempY->getDown()->getY()) + " [dir = both];");
            }
            tempY = tempY->getDown();
        }

        //recorrer para hacer los nodos de los datos
        //while (tempY != NULL)
        //{
        //    tempX = tempY->getRight();
        //    while (tempX != NULL)
        //    {
        //        graph->addln("nodeX"+to_string(tempX->getX())+" [label=\"X = "+to_string(tempX->getX())+"\"];");
        //        if (tempX->getRight()!= nullptr){
        //
        //
        //            graph->addln("nodeX"+to_string(tempX->getX())+" -> nodeX"+to_string(tempX->getRight()->getX())+" [dir = both];");
        //        }
        //        tempX = tempX->getRight();
        //    }
        //    graph->addln("nodeY"+to_string(tempY->getY())+" [label=\"Y ="+to_string(tempY->getY())+"\"];");
        //    tempY = tempY->getDown();
        //}
    }

    graph->addln(graph->end());
    graph->dotGraphGenerator("matriz", graph->getDotSource());
}

//destructor
MatrizDispersa::~MatrizDispersa()
{
}
