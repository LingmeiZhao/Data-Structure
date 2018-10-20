#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    this->items	= new KeyValuePairPtr[capacity];
    this->size	 = 0;
    for (int i = 0; i < this->capacity; i++)
    {
        this->items[i] = nullptr;
    }
}

bool HashTable::Search(int key, double &value)
{
    int index = IntHash(key) % this->capacity;
    if (this->items[index] == nullptr)
    {
        return false;
    }
    else
    {
        KeyValuePair *current = this->items[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                value = current->value;
                return true;
            }
            else
            {
                current = current->next;
            }
        }
        return false;
    }
}

bool HashTable::Insert(int key, double value)
{
    int index = IntHash(key) % this->capacity;
    if (this->items[index] == nullptr)
    {
        this->items[index] = new KeyValuePair(key, value, nullptr);
        this->size++;
        return true;
    }
    else
    {
        KeyValuePair *current = this->items[index];
        while (current->next != nullptr)
        {
            if (current->key == key)
            {
                return false;
            }
            else
            {
                current = current->next;
            }
        }
        current->next = new KeyValuePair(key, value, nullptr);
        this->size++;
        return true;
    }
}

bool HashTable::Remove(int key)
{
    int index = IntHash(key) % this->capacity;
    if (this->items[index] == nullptr)
    {
        return false;
    }
    else
    {
        KeyValuePair *current = this->items[index];
        if (current->key == key)
        {
            KeyValuePair* next = current->next;
            delete current;
            this->items[index] = next;
            return false;
        }
        else
        {
            while (current->next != nullptr)
            {
                if (current->next->key == key)
                {
                    KeyValuePair *next = current->next->next;
                    delete current->next;
                    current->next = next;
                    return true;
                }
            }
            return false;
        }
    }
}

void HashTable::Display()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << i << ": ";
        KeyValuePair *current = this->items[i];
        while (current != nullptr)
        {
            cout << "[" << current->key << ", " << current->value << "]";
            current = current->next;
        }
        cout << endl;
    }
}

KeyValuePair::KeyValuePair(int key, double value, KeyValuePair *next)
{
    this->key   = key;
    this->value = value;
    this->next  = next;
}

int IntHash(int key)
{
    return key;
}
