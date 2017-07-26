#include "Neuron.hpp"
#include "Synapse.hpp"
#include <cassert>

//void Neuron::setOutputSynapce(Synapse *new_synapce) {
//
//    assert(new_synapce != nullptr);
//    outputSynapce = new_synapce;
//}

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

    // Суммируем все входные сигналы от синапсов
    sum = 0;
    for(auto inputSynapce: inputSynapces)
        sum += inputSynapce->getOutput();

    // Используем логистическую функцию
    // для формирования выходного сигнала
    out = activateFunction(sum);
}

void HiddenNeuron::addInputSynapce(Synapse *new_synapse) {

    assert(new_synapse != nullptr);
    inputSynapces.push_back(new_synapse);
}
std::vector<Synapse*> HiddenNeuron::getInputSynapses() {
    return inputSynapces;
}