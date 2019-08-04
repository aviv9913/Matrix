
#include "Neural_Network.h"
#include <iostream>
#include <vector>

/*TODO: create Neural network class:
 *
 * TODO: test Neura lnetwork class
 */
using namespace std;

int main() {
    Neural_Network nw;
    Matrix inputs({{1,2},{0,1},{3,1}});
    Matrix outputs({{11,4,13}});
    cout<<inputs<<endl;
    cout<<outputs<<endl;
    nw.train(inputs, outputs.T(), 1000);
    Matrix test({{1,1}});
    cout<<nw<<endl;
    cout<<nw.think(test)<<endl;
    return 0;
}