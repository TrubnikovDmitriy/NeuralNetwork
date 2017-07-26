#include <cassert>
#include <random>
#include "Synapce.hpp"

Synapce::Synapce(Neuron *_in, Neuron *_out) {

    in = _in;
    out = _out;
    output = 0;
    weight = random() % 100;
}
Synapce::Synapce() {

    in = nullptr;
    out = nullptr;
    output = 0;
    weight = random() % 100;
}

float Synapce::getOutput() {
    return output;
}
void Synapce::setInput(float input) {
    output = input * weight;
}

float Synapce::getPrevDelta() {
    return last_dw;
}
void Synapce::addWeight(float dw) {

    last_dw = dw;
    weight += dw;
}

float Synapce::getWeight() {
    return weight;
}
