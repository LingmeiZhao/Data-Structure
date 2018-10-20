#ifndef HASHTABLE_H
#define HASHTABLE_H

class KeyValuePair
{
public:
    int key;
    double value;
    KeyValuePair *next;
    KeyValuePair(int key,double value,KeyValuePair *next);
};

using KeyValuePairPtr = KeyValuePair*;

class HashTable
{ 
public:
    int capacity;
    KeyValuePairPtr *items;
    int size;
    HashTable (int capacity);

    bool Search(int key,double &value);
    bool Insert(int key,double value);

    bool Remove(int key);

    void Display();
};

int IntHash(int key);

#endif // HASHTABLE_H
