#ifndef NEURAL_NETWORK_UTILS_HPP
#define NEURAL_NETWORK_UTILS_HPP

#include <cmath>

class Neuron;
class Synapse;

inline float activateFunction(float x) {

    return (float)(1 / (1 + exp(-x)));
}
inline float diffActivate(float out) {

    return (1 - out) * out;
}

#endif //NEURAL_NETWORK_UTILS_HPP
