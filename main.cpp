#include <iostream>
#include <fstream>

#include "NeuralNetwork.hpp"

using namespace std;


int main() {

    // Two-layer Artifical Neural Network (Input, Hidden, Output):
    // For ANN XOR: 2 input, 5 hidden, 1 bias, 1 output;
    // learning_ratio: 1.0, iteration: 30000, moment: 0.3;
    // weight random: [-5; 5];

    const float learning_ratio = 1.0f;
    NeuralNetwork network(2, 5, 1, true);

    cout << (network.getResult({1, 1})[0]) << endl;
    cout << (network.getResult({1, 0})[0]) << endl;
    cout << (network.getResult({0, 1})[0]) << endl;
    cout << (network.getResult({0, 0})[0]) << endl;

    network.Learning_BackPropgation({{1, 1}, {1, 0}, {0, 1}, {0, 0}},
                                    {{0},    {1},    {1},    {0}},
                                    learning_ratio, 30000, 0.3f);

    cout << (int)(network.getResult({1, 1})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({1, 0})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({0, 1})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({0, 0})[0] + 0.5f) << endl;

    return 0;
}