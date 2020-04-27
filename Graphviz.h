/* 
 * File:   Graphviz.h
 * Author: pedro
 */
#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H
#include <iostream>
#include <string>
using namespace std;

class Graphviz
{
private:
    string dotSource;
    bool createOrWriteFile(string, string);
public:
    Graphviz();
    string getDotSource();
    string start_graph();
    string end();
    void addln();
    void addln(string);
    void add(string);
    bool dotGraphGenerator(string, string);
    void setDotSource();
    ~Graphviz();
};
#endif //GRAPHVIZ.H