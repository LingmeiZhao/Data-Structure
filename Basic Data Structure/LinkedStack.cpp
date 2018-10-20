#include "LinkedStack.h"
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

LinkedStack::LinkedStack()
{
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedStack::~LinkedStack()
{
    SinglyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        SinglyLinkedNode *next = current->next;
        delete current;
        current = next;
    }
}

void LinkedStack::push(double value)
{
    SinglyLinkedNode *new_node = new SinglyLinkedNode(value, nullptr);
    if (IsEmpty())
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        new_node->next = this->head;
        this->head	 = new_node;
    }
}

void LinkedStack::pop()
{
    if (IsEmpty())
    {
        cout << "It is empty!" << endl;
    }
    else if (this->head->next == nullptr)
    {
        delete this->head;
    }
    else
    {
        SinglyLinkedNode *next = this->head->next;
        delete this->head;
        this->head = next;
    }
}

void LinkedStack::peek()
{
    cout << this->head->value;
}

bool LinkedStack::IsEmpty()
{
    return this->head == nullptr;
}
