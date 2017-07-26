#include "Neuron.hpp"
#include "Synapce.hpp"

Neuron::Neuron(Synapce* outp) {
    outputSynapce = outp;
}
Neuron::Neuron() {
    outputSynapce = nullptr;
}

BiasNeuron::BiasNeuron(Synapce *outp): Neuron(outp) {}
HiddenNeuron::HiddenNeuron(std::vector<Synapce*> inp, Synapce *outp): Neuron(outp) {
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