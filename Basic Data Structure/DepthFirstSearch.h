#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H
#include"UndirectedGraph.h"
#include<iostream>
#include<vector>
#include<stack>

using std::vector;
using std::stack;

class DepthFirstSearch
{
public:
    vector<bool> marked;
    vector<int> edgeTo;
    int source;
    DepthFirstSearch(UndirectedGraph G, int s);

    void dfs(UndirectedGraph G, int v);
    bool hasPathTo(int v);
    stack<int> pathTo(int v);
};

#endif // DEPTHFIRSTSEARCH_H
