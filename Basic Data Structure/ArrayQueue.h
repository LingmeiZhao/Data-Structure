#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H


class ArrayQueue
{
public:
    int capacity;
    double *values;
    int size;

    int front;
    int rear;
    ArrayQueue();

    void Enqueue(double value);
    void Dequeue();
    double Peek();

    void Expand();
    bool IsFull();
};

#endif // ARRAYQUEUE_H
