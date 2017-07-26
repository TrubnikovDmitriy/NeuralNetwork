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
InputNeuron::InputNeuron(Synapce *outp): Neuron(outp), input_data(0.0f) {}
HiddenNeuron::HiddenNeuron(Synapce *outp): Neuron(outp) {}

float InputNeuron::getOut() {
    return input_data;
}
void InputNeuron::setInput(float data) {
    input_data = data;
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