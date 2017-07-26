#include <iostream>
#include "NeuralNetwork.hpp"

using namespace std;

int main() {

    NeuralNetwork network(2, 10, 1, false);
    for (int i = 0; i < 10; ++i) {
        network.Learning({{1, 1}, {1, 0}, {0, 1}, {0, 0}},
                         {{0}, {1}, {1}, {0}}, 2, 10);

        network.Learning({{0, 0}, {1, 1}, {0, 1}, {1, 0}},
                         {{0}, {0}, {1}, {1}}, 2, 10);

        network.Learning({{1, 1}, {0, 1}, {1, 0}, {0, 0}},
                         {{0}, {1}, {1}, {0}}, 2, 10);

        network.Learning({{0, 0}, {1, 0}, {1, 1}, {0, 1}},
                         {{0}, {1}, {0}, {1}}, 2, 10);
    }

    cout << (int)(network.getResult({1, 1})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({1, 0})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({0, 1})[0] + 0.5f) << endl;
    cout << (int)(network.getResult({0, 0})[0] + 0.5f) << endl;


    return 0;
}