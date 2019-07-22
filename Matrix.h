//
// Created by Aviv9 on 13-Jun-19.
//
#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <iostream>
using namespace std;

class Matrix{
    int rows;
    int cols;
    double** data;
    void checkSize(int rows, int cols);
    void changeValue(int row, int col, double value);

public:
    Matrix(int rows, int cols);
    //Matrix(int rows, int cols, double** data);
    Matrix(int rows, int cols, double min, double max);
    ~Matrix();
    int getRows() const;
    int getCols() const;
    double operator()(int row, int col) const;
    Matrix& operator-();
    Matrix& operator+=(const Matrix& mtx);
    Matrix& operator-=(const Matrix& mtx);
    Matrix& T();
    //void convertToEchlon();
    friend ostream& operator<<(ostream& os, const Matrix& mtx);
    class InvalidIndex:public exception{};
};

Matrix& operator+(const Matrix& mtx1 , const Matrix& mtx2);
Matrix& operator-(const Matrix& mtx1 , const Matrix& mtx2);
Matrix& operator*(const Matrix& mtx1 , const Matrix& mtx2);
double fRand(double fMin, double fMax);

#endif //MATRIX_MATRIX_H
