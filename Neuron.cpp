#include "Neuron.hpp"
#include "Synapse.hpp"
#include <cassert>

Neuron::Neuron(Synapse* outp) {
    outputSynapce = outp;
}
Neuron::Neuron() {
    outputSynapce = nullptr;
}

//void Neuron::setOutputSynapce(Synapse *new_synapce) {
//
//    assert(new_synapce != nullptr);
//    outputSynapce = new_synapce;
//}

BiasNeuron::BiasNeuron(Synapse *outp): Neuron(outp) {}
InputNeuron::InputNeuron(Synapse *outp): Neuron(outp), input_data(0.0f) {}
HiddenNeuron::HiddenNeuron(Synapse *outp): Neuron(outp) {}

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
    sumSynapses();
    activate();
}

void HiddenNeuron::sumSynapses() {

    sum = 0;
    for(auto inputSynapce: inputSynapces)
        sum += inputSynapce->getOutput();
}
void HiddenNeuron::activate() {

    out = activateFunction(sum);
}

void HiddenNeuron::addInputSynapce(Synapse *new_synapse) {

    assert(new_synapse != nullptr);
    inputSynapces.push_back(new_synapse);
}
std::vector<Synapse*> HiddenNeuron::getInputSynapses() {
    return inputSynapces;
}