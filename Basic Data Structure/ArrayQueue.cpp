#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
    this->capacity = 4;
    this->values   = new double[this->capacity];
    this->size	 = 0;
    this->front	= 0;
    this->rear	 = -1;
}

void ArrayQueue::Enqueue(double value)
{
    if (this->IsFull())
    {
        this->Expand();
    };
    this->rear				 = (this->rear + 1) % this->capacity;
    this->values[this->rear] = value;
    this->size++;
}

void ArrayQueue::Dequeue()
{
    this->front = (this->front + 1) % this->capacity;
    this->size--;
}

double ArrayQueue::Peek()
{
    return this->values[this -> front];
}

void ArrayQueue::Expand()
{
    constexpr int factor = 2;
    int new_capacity	 = this->capacity * factor;
    double *new_values   = new double[new_capacity];
    for (int i = 0; i < this->size; i++)
    {
        new_values[i] = this->values[i];
    }
    delete[] this->values;
    this->values   = new_values;
    this->capacity = new_capacity;
}

bool ArrayQueue::IsFull()
{
    return this->capacity == this->size;
}
