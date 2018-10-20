#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include <vector>

using std::vector;

template <typename T>
class priorityQueue
{
private:
    vector<T> pq;
    int N;

public:
    priorityQueue();
    bool IsEmpty();
    void Insert(T x);
    T delMax();
};

template <typename T>
priorityQueue<T>::priorityQueue()
{
    this->N = 0;
}

template <typename T>
bool priorityQueue<T>::IsEmpty()
{

    return this->N == 0;
}

template <typename T>
void priorityQueue<T>::Insert(T x)
{
    this->pq.push_back(x);
    this->N++;
}

template <typename T>
T priorityQueue<T>::delMax()
{
    int max = 0;
    for (int i = 1; i < N; i++)
    {
        if (pq.at(max) < pq.at(i))
        {
            max = i;
        }
    }
    std::swap(pq.at(max), pq.at(N - 1));
    return pq.at(--N);
}

#endif // PRIORITYQUEUE_H
