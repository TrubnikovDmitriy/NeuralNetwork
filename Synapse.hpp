#ifndef NEURAL_NETWORK_SYNAPCE_HPP
#define NEURAL_NETWORK_SYNAPCE_HPP

#include "Utils.hpp"

class Synapse {
public:
    Synapse(Neuron* _in, Neuron* _out);
    Synapse();
    ~Synapse() {};

    float getOutput();
    float getPrevDelta();
    void addWeight(float dw);
    float getWeight();

private:
    float output;
    float weight;
    float last_dw;
    Neuron* in;
    Neuron* out; // возможно стоит убрать out
};

#endif //NEURAL_NETWORK_SYNAPCE_HPP
