#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;
void DoublyLinkedList::AddFirst(double value)
{
    DoublyLinkedNode *new_node = new DoublyLinkedNode(value, nullptr, nullptr);

    if (IsEmpty())
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        this->head->previous = new_node;
        new_node->next		 = this->head;
        new_node			 = this->head;
    }
}

void DoublyLinkedList::AddLast(double value)
{
    DoublyLinkedNode *new_node = new DoublyLinkedNode(value, nullptr, nullptr);
    if (IsEmpty())
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        this->tail->next   = new_node;
        new_node->previous = this->tail;
        this->tail		   = new_node;
    }
}

void DoublyLinkedList::InsertAt(double value, int index)
{
    DoublyLinkedNode *new_node = new DoublyLinkedNode(value, nullptr, nullptr);
    DoublyLinkedNode *current  = this->head;
    DoublyLinkedNode *temp	 = nullptr;
    for (int i = 0; i < index; i++)
    {
        temp	= current;
        current = current->next;
    }
    temp->next		   = new_node;
    new_node->previous = temp;
    new_node->next	 = current;
    current->previous  = new_node;
}

void DoublyLinkedList::RemoveFirst()
{
    if (IsEmpty())
    {
        cout << "It is empty!";
    }
    else if (this->head->next == nullptr)
    {
        delete this->head;
    }
    else
    {
        DoublyLinkedNode *next = this->head->next;
        delete this->head;
        this->head = next;
    }
}

void DoublyLinkedList::RemoveAt(int index)
{
    DoublyLinkedNode *current = this->head;
    DoublyLinkedNode *temp	= nullptr;
    for (int i = 0; i < index; i++)
    {
        temp	= current;
        current = current->next;
    }
    temp->next				= current->next;
    current->next->previous = temp;
    delete current;
}

DoublyLinkedNode *DoublyLinkedList::Find(double value)
{
    DoublyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            return current;
        }
        else
        {
            current = current->next;
        }
    }
    return nullptr;
}

void DoublyLinkedList::Display()
{
    DoublyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        cout << current->value;
        cout << " --> ";
        current = current->next;
    }
    cout << endl;
}

bool DoublyLinkedList::IsEmpty()
{
    return this->head == nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    DoublyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        DoublyLinkedNode *next = current->next;
        delete current;
        current = next;
    }
}

DoublyLinkedNode::DoublyLinkedNode(double value, DoublyLinkedNode *previous,
                                   DoublyLinkedNode *next)
{
    this->value	= value;
    this->previous = previous;
    this->next	 = next;
}
