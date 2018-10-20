#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H
#include <iostream>
#include <vector>

using std::vector;
using vecint=std::vector<int>;

class UndirectedGraph
{
public:
    int vertex;
    int edge;
    vector<vecint* > adj;
    UndirectedGraph(int v);

    void AddEdge(int from,int to);
    void Display();
};

#endif // UNDIRECTEDGRAPH_H
