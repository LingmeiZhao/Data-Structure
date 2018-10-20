#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList()
{
    SinglyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        SinglyLinkedNode *next = current->next;
        delete current;
        current = next;
    }
}

void SinglyLinkedList::AddLast(double value)
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

void SinglyLinkedList::Display()
{
    SinglyLinkedNode *current = this->head;
    while (current != nullptr)
    {
        cout << current->value;
        cout << " --> ";
        current = current->next;
    }
    cout << endl;
}

void SinglyLinkedList::AddFirst(double value)
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

SinglyLinkedNode *SinglyLinkedList::Find(double value)
{
    SinglyLinkedNode *current = this->head;
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

void SinglyLinkedList::InsertAt(double value, int index)
{
    SinglyLinkedNode *new_node = new SinglyLinkedNode(value, nullptr);
    SinglyLinkedNode *current  = this->head;
    SinglyLinkedNode *temp	 = nullptr;
    for (int i = 0; i < index; i++)
    {
        temp	= current;
        current = current->next;
    }
    temp->next	 = new_node;
    new_node->next = current;
}

void SinglyLinkedList::RemoveFirst()
{
    if (IsEmpty())
    {
        cout << "It is empty!";
    }else if(this->head->next==nullptr)
    {
        delete this->head;
    }
    else
    {
        SinglyLinkedNode* next = this->head->next;
        delete this->head;
        this->head = next;
    }
}

void SinglyLinkedList::RemoveAt(int index)
{
    SinglyLinkedNode *current = this->head;
    SinglyLinkedNode *temp	= nullptr;
    for (int i = 0; i < index; i++)
    {
        temp	= current;
        current = current->next;
    }
    temp->next = current->next;
    delete current;
}

bool SinglyLinkedList::IsEmpty()
{
    return this->head == nullptr;
}

SinglyLinkedNode::SinglyLinkedNode(double value, SinglyLinkedNode *next)
{
    this->value = value;
    this->next  = next;
}
