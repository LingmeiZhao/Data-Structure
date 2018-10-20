#include "ArraryStack.h"

ArraryStack::ArraryStack()
{
    this->capacity = 4;
    this->size	 = 0;
    this->values   = new double[this->capacity];
}

ArraryStack::~ArraryStack()
{
    delete[] this->values;
}

void ArraryStack::Push(double value)
{
    if (this->capacity == this->size)
    {
        this->Expend();
    }

    this->values[this->size] = value;
    this->size++;
}

void ArraryStack::Pop()
{
    this->size--;
}

double ArraryStack::Peek()
{
    return this->values[this->size-1];
}

void ArraryStack::Expend()
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
