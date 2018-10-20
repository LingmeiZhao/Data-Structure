#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "SinglyLinkedList.h"

class LinkedStack
{
public:
    SinglyLinkedNode *head;
    SinglyLinkedNode *tail;
    LinkedStack();
    ~LinkedStack();

    void push(double value);
    void pop();
    void peek();

    bool IsEmpty();


};

#endif // LINKEDSTACK_H
