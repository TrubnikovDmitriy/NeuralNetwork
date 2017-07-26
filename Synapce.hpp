#ifndef NEURAL_NETWORK_SYNAPCE_HPP
#define NEURAL_NETWORK_SYNAPCE_HPP

#include "Utils.hpp"

class Synapce {
public:
    Synapce(Neuron* _in, Neuron* _out);
    Synapce();
    ~Synapce() {};

    float getOutput();
    void setInput(float input);
    float getPrevDelta();
    void addWeight(float dw);
    float getWeight();

private:
    float output;
    float weight;
    float last_dw;
    Neuron* in;
    Neuron* out;
};

#endif //NEURAL_NETWORK_SYNAPCE_HPP
