#include "Neuron.hpp"
#include "Synapce.hpp"
#include <cassert>

Neuron::Neuron(Synapce* outp) {
    outputSynapce = outp;
}
Neuron::Neuron() {
    outputSynapce = nullptr;
}

void Neuron::addOutputSynapce(Synapce *new_synapce) {

    assert(new_synapce != nullptr);
    outputSynapce = new_synapce;
}

BiasNeuron::BiasNeuron(Synapce *outp): Neuron(outp) {}
HiddenNeuron::HiddenNeuron(Synapce *outp): Neuron(outp) {
    inputSynapces = inp;
}

float HiddenNeuron::getOut() {

    return out;
}
void HiddenNeuron::calculate() {
    sumSynapces();
    activate();
}

void HiddenNeuron::sumSynapces() {

    sum = 0;
    for(auto inputSynapce: inputSynapces)
        sum += inputSynapce->getOutput();
}
void HiddenNeuron::activate() {

    out = activateFunction(sum);
}

void HiddenNeuron::addInputSynapce(Synapce *new_synapce) {

    assert(new_synapce != nullptr);
    inputSynapces.push_back(new_synapce);
}