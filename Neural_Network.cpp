//
// Created by Aviv9 on 27-Jul-19.
//

#include "Neural_Network.h"

double Neural_Network::think(Matrix inputs) {
    return (inputs*weights)(1,1);
}

void Neural_Network::train(Matrix inputs, Matrix outputs, int num) {
    weights = Matrix(inputs.getCols(),1,0,1);
    cout<<"weights:\n"<<weights<<endl;
    for(int i=0;i<num;i++){
        Matrix output = inputs*weights;
        Matrix error = outputs - output;
        Matrix adjustment = 0.01*((inputs.T())*error);
        weights+=adjustment;
    }
}

ostream& operator<<(ostream &os, const Neural_Network &nw) {
    return os<<nw.weights;
}