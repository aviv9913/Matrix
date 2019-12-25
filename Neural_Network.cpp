//
// Created by Aviv9 on 27-Jul-19.
//

#include "Neural_Network.h"

double Neural_Network::think(Matrix inputs) {
    inputs.addCol(Matrix(inputs.getRows(),1,1));
    return (inputs*weights)(1,1);
}

void Neural_Network::train(Matrix inputs, Matrix outputs, int num) {
    weights = Matrix(inputs.getCols()+1,1,0,1);
    inputs.addCol(Matrix(inputs.getRows(),1,1));
    cout<<"inputs = "<<inputs<<endl;
    for(int i=0;i<num;i++){
        Matrix output = inputs*weights;
        Matrix error = outputs - output;
        Matrix adjustment = 0.05*((inputs.T())*error);
        weights+=adjustment;
    }
}

ostream& operator<<(ostream &os, const Neural_Network &nw) {
    return os<<nw.weights;
}