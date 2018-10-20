#include "LinkedQueue.h"
#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

LinkedQueue::LinkedQueue()
{
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedQueue::~LinkedQueue()
{
    SinglyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        SinglyLinkedNode *next = current->next;
        delete current;
        current = next;
    }
}

void LinkedQueue::EnQueue(double value)
{
    SinglyLinkedNode *new_node = new SinglyLinkedNode(value, nullptr);
    if (IsEmpty())
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        this->tail->next = new_node;
        this->tail		 = new_node;
    }
}

void LinkedQueue::peek()
{
    cout << this->head->value;
}

bool LinkedQueue::IsEmpty()
{
    return this->head == nullptr;
}
