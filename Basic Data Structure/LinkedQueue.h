#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "SinglyLinkedList.h"


class LinkedQueue
{
public:
    SinglyLinkedNode *head;
    SinglyLinkedNode *tail;
    LinkedQueue();
    ~LinkedQueue();

    void EnQueue(double value);
    void DeQueue();
    void peek();

    bool IsEmpty();



};

#endif // LINKEDQUEUE_H
