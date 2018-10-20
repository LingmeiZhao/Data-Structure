#include "DepthFirstSearch.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>

using namespace std;
DepthFirstSearch::DepthFirstSearch(UndirectedGraph G, int s)
{
    marked.reserve(G.vertex);
    edgeTo.reserve(G.vertex);
    this->source = s;
    for (int i = 0; i < G.vertex; i++)
    {
        marked.push_back(false);
        edgeTo.push_back(-1);
    }
    dfs(G, s);
}

void DepthFirstSearch::dfs(UndirectedGraph G, int v)
{
    marked.at(v) = true;
    for (int item : *(G.adj.at(v)))
    {
        if (!marked.at(item))
        {
            edgeTo.at(item) = v;
            dfs(G, item);
        }
    }
}

bool DepthFirstSearch::hasPathTo(int v)
{
    return marked.at(v);
}

stack<int> DepthFirstSearch::pathTo(int v)
{
    if (!hasPathTo(v))
    {
        return stack<int>();
    }
    stack<int> *path = new stack<int>();
    for (int i = v; i != this->source; i = edgeTo.at(i))
    {
        path->push(i);
    }
    path->push(this->source);
    return *path;
}
