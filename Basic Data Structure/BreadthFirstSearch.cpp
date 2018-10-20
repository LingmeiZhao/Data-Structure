#include "BreadthFirstSearch.h"
#include "UndirectedGraph.h"
#include <queue>
#include <vector>

using std::vector;
using std::queue;
BreadthFirstSearch::BreadthFirstSearch(UndirectedGraph G, int source)
{
    marked.reserve(G.vertex);
    edgeTo.reserve(G.vertex);
    for (int i = 0; i < G.vertex; i++)
    {
        marked.push_back(false);
        edgeTo.push_back(-1);
    }
    this->source = source;
    bfs(G,source);
}

void BreadthFirstSearch::bfs(UndirectedGraph G, int s)
{
    queue<int> *Queue = new queue<int>();
    marked.at(s)	  = true;
    Queue->push(s);
    while (!Queue->empty())
    {
        int v = Queue->front();
        Queue->pop();
        for (int item : *(G.adj.at(v)))
        {
            if (!marked.at(item))
            {
                edgeTo.at(item) = v;
                marked.at(item) = true;
                Queue->push(item);
            }
        }
    }
}

bool BreadthFirstSearch::hasPathTo(int v)
{
    return marked.at(v);
}

stack<int> BreadthFirstSearch::pathTo(int v)
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
