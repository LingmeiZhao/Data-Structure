#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int nRows, int nCols)
{
    this->nRows  = nRows;
    this->nCols  = nCols;
    this->values = new double[nRows * nCols];
    for (int i = 0; i < nRows * nCols; i++)
    {
        values[i] = 0.0;
    }
}

Matrix::Matrix(const Matrix &other)
{
    this->nRows  = other.nRows;
    this->nCols  = other.nCols;
    int n		 = other.nRows * other.nCols;
    this->values = new double[n];
    for (int i = 0; i < n; i++)
    {
        this->values[i] = other.values[i];
    }
}

Matrix &Matrix::operator=(const Matrix &other)
{
    delete[] values;
    this->nRows  = other.nRows;
    this->nCols  = other.nCols;
    int n		 = other.nRows * other.nCols;
    this->values = new double[n];
    for (int i = 0; i < n; i++)
    {
        this->values[i] = other.values[i];
    }
    return *this;
}

Matrix::Matrix(Matrix &&other)
{
    this->nRows  = other.nRows;
    this->nCols  = other.nCols;
    this->values = other.values;
    other.nRows  = 0;
    other.nCols  = 0;
    other.values = nullptr;
}

Matrix &Matrix::operator=(Matrix &&other)
{
    delete[] values;
    this->nRows  = other.nRows;
    this->nCols  = other.nCols;
    this->values = other.values;
    other.nRows  = 0;
    other.nCols  = 0;
    other.values = nullptr;
    return *this;
}

double &Matrix::At(int i, int j)
{
    if (i >= 0 && j >= 00 && i < nRows && j < nCols)
    {
        return values[i * nCols + j];
    }
    else
    {
        cout << "error" << endl;
    }
}

Matrix::~Matrix()
{
    delete[] values;
}

void Matrix::Display()
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            cout << At(i, j) << "\t";
        }
        cout << endl;
    }
}
