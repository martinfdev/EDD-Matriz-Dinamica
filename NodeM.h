
#ifndef NODEM_H
#define NODEM_H
#include <stdlib.h>
#include <string>


class NodeM
{
private:
    NodeM *left;
    NodeM *right;
    NodeM *up;
    NodeM *down;
    std::string data;
    int x, y;

public:
    NodeM(std::string);
    NodeM(int, int, std::string);
    void setLeft(NodeM*);
    void setRight(NodeM *);
    void setUp(NodeM *);
    void setDown(NodeM *);
    NodeM *getLeft();
    NodeM *getRight();
    NodeM *getUp();
    NodeM *getDown();
    std::string getData();
    int getX();
    int getY();
    ~NodeM();
};
#endif //NODEM_H
