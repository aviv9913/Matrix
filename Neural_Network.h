//
// Created by Aviv9 on 27-Jul-19.
//
#ifndef MATRIX_NEURAL_NETWORK_H
#define MATRIX_NEURAL_NETWORK_H

#include "Matrix.h"

class Neural_Network {
    Matrix weights = Matrix(1,1);
public:
    Neural_Network() = default;
    ~Neural_Network() = default;
    void train(Matrix inputs, Matrix outputs, int num);
    double think(Matrix inputs);
    friend ostream& operator<<(ostream& os, const Neural_Network& nw);
};


#endif //MATRIX_NEURAL_NETWORK_H
