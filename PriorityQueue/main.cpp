#include "BinaryHeap.h"
#include "priorityQueue.h"
#include <iostream>

using namespace std;

int main()
{
    /*priorityQueue<int> queue;
    queue.Insert(12);
    queue.Insert(27);
    queue.Insert(45);
    queue.Insert(33);
    queue.Insert(10);
    queue.Insert(2);
    queue.Insert(19);
    queue.Insert(89);
    queue.Insert(78);
    queue.Insert(34);
    queue.Insert(66);
    cout << queue.delMax() << endl;*/
    BinaryHeap<int> queue(11);
    queue.Insert(12);
    queue.Insert(27);
    queue.Insert(45);
    queue.Insert(33);
    queue.Insert(10);
    queue.Insert(2);
    queue.Insert(19);
    queue.Insert(89);
    queue.Insert(78);
    queue.Insert(34);
    queue.Insert(66);
    cout << queue.delMax() << endl;

    cout << "Hello World!" << endl;
    return 0;
}
