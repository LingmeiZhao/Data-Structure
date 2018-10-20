#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix m(2,3);
    m.At(0,1)=2;
    m.At(1,1)=4;
    m.At(1,2)=7;
    m.Display();

    Matrix m1=m;
    m1.Display();

    cout << "Hello World!" << endl;
    return 0;
}
