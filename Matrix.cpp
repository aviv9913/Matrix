//
// Created by Aviv9 on 13-Jun-19.
//
#include "Matrix.h"


void Matrix::checkSize(int rows, int cols) {
    if(rows==0)
        if(cols<=0){
            cerr<<"ERROR:invalid size - no values"<<endl;
            exit(0);
        }

    if(cols==0)
        if(rows<=0){
            cerr<<"ERROR:invalid size - no values"<<endl;
            exit(0);
        }
    if(rows<0||cols<0){
        cerr<<"ERROR:invalid size - negative number"<<endl;
        exit(0);
    }
}

Matrix::Matrix(int rows, int cols){
    checkSize(rows, cols);
    this->rows = rows;
    this->cols = cols;
    data = new double*[rows];
    for(int i=0;i<rows;i++){
        data[i] = new double[cols];
        for(int j=0;j<cols;j++){
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows, int cols, double min, double max){
    checkSize(rows, cols);
    this->rows = rows;
    this->cols = cols;
    data = new double*[rows];
    double rand_num = fRand(min, max);
    for(int i=0;i<rows;i++){
        data[i] = new double[cols];
        for(int j=0;j<cols;j++){
            data[i][j] = rand_num;
            rand_num = fRand(min, max);
        }
    }
}

Matrix::~Matrix() {
    for(int i=0;i<rows;i++){
        delete[] data[i];
    }
    delete[] data;
}

int Matrix::getCols() const {
    return cols;
}

int Matrix::getRows() const {
    return rows;
}

void Matrix::changeValue(int row, int col, double value) {
    if(row>=rows||col>=cols){
        throw InvalidIndex();
    }
    this->data[row][col] = value;
}

Matrix& Matrix::operator-() {
    for(int i = 0; i<rows ; i++){
        for(int j=0; j<cols ; j++){
            changeValue(i,j,-data[i][j]);
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix &mtx) {
    int new_rows = mtx.cols;
    int new_cols = mtx.rows;
    if(new_rows!=rows||new_cols!=cols){
        cerr<<"ERROR:trying to add a "<<new_rows<<"X"<<new_cols
            <<" matrix to "<<rows<<"X"<<cols<<" matrix"<<endl;
    }
    for(int i=0;i<new_cols;i++){
        for(int j=0;j<new_rows;j++){
            data[i][j] += mtx.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix &mtx) {
    -(*this);
    *this+=mtx;
    return -(*this);
}

double Matrix::operator()(int row, int col) const {
    return data[col][row];
}

Matrix& Matrix::T() {
    Matrix trans(cols, rows);
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            trans.changeValue(i ,j, data[i][j]);
        }
    }
    *this = trans;
    return *this;
}

ostream& operator<<(ostream& os, const Matrix& mtx){
    int new_rows = mtx.cols;
    int new_cols = mtx.rows;
    os<<new_rows<<"X"<<new_cols<<"\n";
    for(int i=0;i<new_rows;i++){
        os<<"( ";
        for(int j=0;j<new_cols;j++){
            os<<mtx.data[i][j]<<" ";
        }
        os<<")\n";
    }
    return os;
}

Matrix& operator+(const Matrix& mtx1 , const Matrix& mtx2){
    return Matrix(mtx1)+=mtx2;
}

Matrix& operator-(const Matrix& mtx1 , const Matrix& mtx2){
    return Matrix(mtx1)-=mtx2;
}

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

#include "Matrix.h"
