//
// Created by Aviv9 on 13-Jun-19.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>
using namespace std;

class Matrix{
    int* size;
    double** data;
    void checkSize(int* size);

public:
    Matrix(int rows, int cols);
    Matrix(int* new_size, double** data);
    ~Matrix();
    void changeValue(int row, int col, double value);
    Matrix& operator+=(const Matrix& mtx);
    friend ostream& operator<<(ostream& os, const Matrix& mtx);
};

Matrix operator+(const Matrix& mtx1 , const Matrix& mtx2);

#endif //MATRIX_MATRIX_H
