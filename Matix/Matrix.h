#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>


class Matrix
{
public:
    Matrix(int nRows,int nCols);
    Matrix(const Matrix &other);
    Matrix &operator =(const Matrix &other);
    Matrix(Matrix &&other);
    Matrix &operator =(Matrix &&other);
    double &At(int i,int j);
    ~Matrix();
    void Display();
private:
    int nRows;
    int nCols;
    double *values;
};

#endif // MATRIX_H
