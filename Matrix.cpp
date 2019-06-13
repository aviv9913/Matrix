//
// Created by Aviv9 on 13-Jun-19.
//
#include "Matrix.h"


Matrix operator+(const Matrix& mtx1 , const Matrix& mtx2){
    return Matrix(mtx1)+=mtx2;
}

void Matrix::checkSize(int *size) {
    int rows,cols;
    rows = size[0];
    cols = size[1];
    if(rows==0)
        if(cols<=0){
            cerr<<"invalid size - no values"<<endl;
            exit(0);
        }

    if(cols==0)
        if(rows<=0){
            cerr<<"invalid size - no values"<<endl;
            exit(0);
        }
    if(rows<0||cols<0){
        cerr<<"invalid size - negative number"<<endl;
        exit(0);
    }
}

Matrix::Matrix(int rows, int cols){
    size = new int[2];
    size[0] = rows;
    size[1] = cols;
    checkSize(size);
    data = new double*[rows];
    for(int i=0;i<cols;i++){
        data[i] = new double[cols];
        for(int j=0;j<cols;j++){
            data[i][j] = 0;
        }
    }
}
Matrix::Matrix(int *new_size, double **new_data) {
    Matrix::checkSize(new_size);
    size = new int[2];
    int rows,cols;
    rows = new_size[0];
    cols = new_size[1];
    size[0] = new_size[0];
    size[1] = new_size[1];
    data = new double*[rows];
    for(int i=0;i<cols;i++){
        data[i] = new double[cols];
        for(int j=0;j<cols;j++){
            data[i][j] = new_data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for(int i=0;i<size[0];i++){
        delete[] data[i];
    }
    delete[] size;
    delete[] data;
}

void Matrix::changeValue(int row, int col, double value) {
    this->data[row][col] = value;
}

Matrix& Matrix::operator+=(const Matrix &mtx) {
    int rows = mtx.size[0];
    int cols = mtx.size[1];
    if(rows!=size[0]||cols!=size[1]){
        cerr<<"sum error, trying to add a "<<rows<<"X"<<cols
            <<" matrix to "<<size[0]<<"X"<<size[1]<<" matrix"<<endl;
    }
    for(int i=0;i<cols;i++){
        for(int j=0;j<cols;j++){
            data[i][j] += mtx.data[i][j];
        }
    }
}

ostream& operator<<(ostream& os, const Matrix& mtx){
    int rows = mtx.size[0];
    int cols = mtx.size[1];
    os<<mtx.size[0]<<"X"<<mtx.size[1]<<"\n";
    for(int i=0;i<rows;i++){
        os<<"( ";
        for(int j=0;j<cols;j++){
            os<<mtx.data[i][j]<<" ";
        }
        os<<")\n";
    }
    return os;
}
#include "Matrix.h"
