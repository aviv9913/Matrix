//
// Created by Aviv9 on 27-Jul-19.
//
#ifndef MATRIX_NEURAL_NETWORK_H
#define MATRIX_NEURAL_NETWORK_H

#include "Matrix.h"

class Neural_Network {
    Matrix weights;
public:
    Neural_Network();
    ~Neural_Network();
    void train(Matrix inputs, Matrix outputs, int num);
    double think(Matrix inputs);
};


#endif //MATRIX_NEURAL_NETWORK_H
