#include "UndirectedGraph.h"
#include <iostream>

using std::cout;
using namespace std;
UndirectedGraph::UndirectedGraph(int v)
{
    this->vertex = v;
    this->edge   = 0;
    adj.reserve(v);
    for (int i = 0; i < v; i++)
    {
        adj.push_back(new vecint());
    }
}

void UndirectedGraph::AddEdge(int from, int to)
{

    adj[from]->push_back(to);
    adj[to]->push_back(from);
    edge++;
}

void UndirectedGraph::Display()
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << ": ";
        for (int item : *(adj.at(i)))
        {
            cout << item<< " ";
        }
        cout << endl;
    }
}
