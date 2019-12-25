
#include "Neural_Network.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Neural_Network nw;
    Matrix inputs({{1,1},{2,2},{3,1}});
    Matrix outputs({{3,6,5}});
    nw.train(inputs, outputs.T(), 2000);
    Matrix test({{5,5}});
    cout<<nw<<endl;
    cout<<nw.think(test)<<endl;

    return 0;
}
