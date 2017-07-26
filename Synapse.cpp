#include <cassert>
#include <random>
#include "Synapse.hpp"
#include "Neuron.hpp"


Synapse::Synapse(Neuron *_in, Neuron *_out) {

    in = _in;
    out = _out;
    output = 0;
    weight = random() % 20 - 10;
}
Synapse::Synapse() {

    in = nullptr;
    out = nullptr;
    output = 0;
    weight = random() % 100;
}

float Synapse::getOutput() {
    // Дергаем синапсы - заставляем их получать
    // значения из предыдущего слоя нейронов.
    return weight * in->getOut();
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