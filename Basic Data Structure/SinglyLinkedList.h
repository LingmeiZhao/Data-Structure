#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class SinglyLinkedNode
{
public:
    double value;
    SinglyLinkedNode *next;
    SinglyLinkedNode(double value, SinglyLinkedNode *next);
};

class SinglyLinkedList
{
public:
    SinglyLinkedNode *head;
    SinglyLinkedNode *tail;
    SinglyLinkedList();
    ~SinglyLinkedList();

    void AddLast(double value);
    void AddFirst(double value);
    void InsertAt(double value,int index);

    SinglyLinkedNode *Find(double value);

    void RemoveFirst();
    void RemoveAt(int index);

    bool IsEmpty();
    void Display();


};

#endif // SINGLYLINKEDLIST_H
