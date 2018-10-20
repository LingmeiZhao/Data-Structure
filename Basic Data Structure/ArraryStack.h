#ifndef ARRARYSTACK_H
#define ARRARYSTACK_H

class ArraryStack
{
public:
    int capacity;
    double *values;
    int size;
    ArraryStack();
    ~ArraryStack();

    void Push(double value);
    void Pop();
    double Peek();

    void Expend();


};

#endif // ARRARYSTACK_H
