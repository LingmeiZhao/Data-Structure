#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedNode
{
public:
    double value;
    DoublyLinkedNode *previous;
    DoublyLinkedNode *next;
    DoublyLinkedNode(double value,DoublyLinkedNode *previous,DoublyLinkedNode *next );
};

class DoublyLinkedList
{
public:
    DoublyLinkedNode *head;
    DoublyLinkedNode *tail;
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddFirst(double value);
    void AddLast(double value);
    void InsertAt(double value, int index);

    void RemoveFirst();
    void RemoveAt(int index);
    DoublyLinkedNode *Find(double value);

    void Display();
    bool IsEmpty();

};

#endif // DOUBLYLINKEDLIST_H
