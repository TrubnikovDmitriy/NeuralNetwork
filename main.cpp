#include <iostream>
#include <fstream>

#include "NeuralNetwork.hpp"

using namespace std;


int main() {

    // For ANN XOR: 2 input, 5 hidden, 1 bias, 1 output;
    // learning_ratio: 1.0, iteration: 1800, moment: 0.3;

    const float learning_ratio = 1.0f;
    NeuralNetwork network(2, 5, 1, true);

    for (int i = 0; i < 30; ++i) {
        network.Learning({{1, 1}, {1, 0}, {0, 1}, {0, 0}},
                         {{0}, {1}, {1}, {0}}, learning_ratio, 10);

        network.Learning({{0, 0}, {1, 1}, {0, 1}, {1, 0}},
                         {{0}, {0}, {1}, {1}}, learning_ratio, 10);

        network.Learning({{0, 1}, {1, 0}, {0, 0}, {1, 1}},
                         {{1}, {1}, {0}, {0}}, learning_ratio, 10);

        network.Learning({{1, 1}, {0, 1}, {1, 0}, {0, 0}},
                         {{0}, {1}, {1}, {0}}, learning_ratio, 10);

        network.Learning({{0, 0}, {1, 0}, {1, 1}, {0, 1}},
                         {{0}, {1}, {0}, {1}}, learning_ratio, 10);

        network.Learning({{1, 0}, {1, 1}, {0, 0}, {0, 1}},
                         {{1}, {0}, {0}, {1}}, learning_ratio, 10);
    }

    cout << (int)(network.getResult({1, 1})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({1, 0})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({0, 1})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({0, 0})[0] + 0.5f) << endl;


    return 0;
}