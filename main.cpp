#include <iostream>
#include "NeuralNetwork.hpp"

using namespace std;

int main() {

    NeuralNetwork network(2, 2, 1, false);
    cout << network.getResult({1, 1})[0] << endl;

    return 0;
}