#include "ArraryStack.h"
#include "ArrayList.h"
#include "DoublyLinkedList.h"
#include "ArrayQueue.h"
#include "HashTable.h"
#include "SinglyLinkedList.h"
#include "BinaryTree.h"
#include "UndirectedGraph.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    UndirectedGraph *graph=new UndirectedGraph(13);
    graph->AddEdge(0,5);
    graph->AddEdge(4,3);
    graph->AddEdge(0,1);
    graph->AddEdge(9,12);
    graph->AddEdge(6,4);
    graph->AddEdge(5,4);
    graph->AddEdge(0,2);
    graph->AddEdge(11,12);
    graph->AddEdge(9,10);
    graph->AddEdge(0,6);
    graph->AddEdge(7,8);
    graph->AddEdge(9,11);
    graph->AddEdge(5,3);
    graph->Display();
    return 0;
}
