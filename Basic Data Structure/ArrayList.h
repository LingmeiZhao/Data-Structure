#ifndef ARRARYLIST_H
#define ARRARYLIST_H


class ArrayList
{
public:
    int capacity;
    int size;
    double *values;
    ArrayList();

    void Add(double value);
    double Get(int index);
    void Set(int index,double value);

    void InsertAt(int index,double value);
    void RemoveAt(int index);
    int Find(double value);

    void Expend();

    void Display();
};

#endif // ARRARYLIST_H
