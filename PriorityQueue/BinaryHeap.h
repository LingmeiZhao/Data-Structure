#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>

using std::vector;

template <typename T>
class BinaryHeap
{
private:
    T **pq;
    int N;
    int capacity;
    void swim(int k);
    void sink(int k);

public:
    BinaryHeap(int capacity);
    ~BinaryHeap();
    bool IsEmpty();
    void Insert(T x);
    T delMax();
};

template <typename T>
void BinaryHeap<T>::swim(int k)
{
    while (k > 1 && *pq[k / 2] < *pq[k])
    {
        std::swap(*pq[k / 2], *pq[k]);
        k = k / 2;
    }
}

template <typename T>
void BinaryHeap<T>::sink(int k)
{
    while (2 * k <= N)
    {
        int j = 2 * k;
        if (j < N && *pq[j] < *pq[j + 1])
        {
            j++;
        }
        if (*pq[k] >= *pq[j])
        {
            break;
        }
        std::swap(*pq[k], *pq[j]);
        k = j;
    }
}

template <typename T>
BinaryHeap<T>::BinaryHeap(int capacity)
{
    this->N		   = 0;
    this->capacity = capacity;
    for (int i = 1; i <= capacity; i++)
    {
        pq[i] = nullptr;
    }
}

template <typename T>
BinaryHeap<T>::~BinaryHeap()
{
    for (int i = 1; i <= capacity; i++)
    {
        delete pq[i];
    }
    delete[] pq;
}

template <typename T>
bool BinaryHeap<T>::IsEmpty()
{
    return this->N == 0;
}

template <typename T>
void BinaryHeap<T>::Insert(T x)
{

    this->pq[++N] = new T(x);
    swim(N);
}

template <typename T>
T BinaryHeap<T>::delMax()
{
    T max = *pq[1];
    std::swap(pq[1], pq[N--]);
    sink(1);
    pq[N + 1] = nullptr;
    return max;
}

#endif // BINARYHEAP_H
