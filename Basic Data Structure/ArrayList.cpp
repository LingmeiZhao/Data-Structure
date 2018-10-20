#include "ArrayList.h"
#include <iostream>
using namespace std;

ArrayList::ArrayList()
{
    constexpr int initial_size = 4;
    this->capacity			   = initial_size;
    this->size				   = 0;
    this->values			   = new double[this->capacity];
}

void ArrayList::Add(double value)
{
    if (this->capacity == this->size)
    {
        this->Expend();
    }

    this->values[this->size] = value;
    this->size++;
}

double ArrayList::Get(int index)
{
    return this->values[index];
}

void ArrayList::Set(int index, double value)
{
    this->values[index] = value;
}

void ArrayList::InsertAt(int index, double value)
{
    if (this->capacity == this->size)
    {
        this->Expend();
    }

    for (int i = this->size; i > index; i--)
    {
        this->values[i] = this->values[i - 1];
    }

    this->values[index] = value;
    this->size++;
}

void ArrayList::RemoveAt(int index)
{
    for (int i = 0; i < this->size; i++)
    {
        if (i == index)
        {
            this->values[i] = this->values[i + 1];
        }
    }
    this->size--;
}

int ArrayList::Find(double value)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->values[i] == value)
        {
            return i;
        }
    }
}

void ArrayList::Expend()
{
    constexpr int factor = 2;
    int new_capacity	 = this->capacity * factor;
    double *new_values   = new double[new_capacity];
    for (int i = 0; i < this->size; i++)
    {
        new_values[i] = this->values[i];
    }
    delete[] this->values;
    this->values=new_values;
    this->capacity=new_capacity;
}

void ArrayList::Display()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << this->values[i] << " ";
    }
    cout << endl;
}
