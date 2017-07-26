#ifndef NEURAL_NETWORK_UTILS_HPP
#define NEURAL_NETWORK_UTILS_HPP

#include <cmath>

class Neuron;
class Synapce;

float activateFunction(float x) {

    return (float)(1 / (1 + exp(-x)));
}

#endif //NEURAL_NETWORK_UTILS_HPP
