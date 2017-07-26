#include <cassert>
#include <random>
#include "Synapse.hpp"


Synapse::Synapse(Neuron *_in, Neuron *_out) {

    in = _in;
    out = _out;
    output = 0;
    weight = random() % 10;
}
Synapse::Synapse() {

    in = nullptr;
    out = nullptr;
    output = 0;
    weight = random() % 100;
}

float Synapse::getOutput() {
    return output;
}
void Synapse::setInput(float input) {
    output = input * weight;
}

float Synapse::getPrevDelta() {
    return last_dw;
}
void Synapse::addWeight(float dw) {

    last_dw = dw;
    weight += dw;
}

float Synapse::getWeight() {
    return weight;
}