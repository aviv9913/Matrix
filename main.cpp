
#include "Matrix.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<double>> a = {{1.1,1.2,1.3,1.4},{2.1,2.2,2.3,2.4}};
    for(vector<double> row : a){
        for(double num : row){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    Matrix mtx({{1,1,1,1},{2,2,2}});
    cout<<mtx<<endl;
    mtx.T();
    cout<<mtx<<endl;
    return 0;
}