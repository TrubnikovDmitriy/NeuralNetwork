#include <iostream>
#include "NeuralNetwork.hpp"

using namespace std;

int main() {

    NeuralNetwork network(2, 2, 1, false);
    cout << network.getResult({0, 1})[0] << endl;
    network.Learning({{1, 1}, {1, 0}, {0, 1}, {0, 0}},
                     {{0}, {1}, {1}, {0}});

    return 0;
}