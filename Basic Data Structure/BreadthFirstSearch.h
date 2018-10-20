#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H
#include "UndirectedGraph.h"
#include<vector>
#include<stack>

using std::vector;
using std::stack;
class BreadthFirstSearch
{
public:
    vector<bool> marked;
    vector<int> edgeTo;
    int source;
    BreadthFirstSearch(UndirectedGraph G,int source);
    void bfs(UndirectedGraph G, int s);
    bool hasPathTo(int v);
    stack<int> pathTo(int v);
};

#endif // BREADTHFIRSTSEARCH_H
