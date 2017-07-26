#ifndef NEURAL_NETWORK_NEURON_HPP
#define NEURAL_NETWORK_NEURON_HPP

#include <vector>
#include "Utils.hpp"

class Neuron {
public:
    Neuron() {};
    virtual ~Neuron() {};
    virtual float getOut() = 0;
};

class BiasNeuron: public Neuron {
public:
    BiasNeuron() {};
    ~BiasNeuron() {};

    float getOut() { return 1.0f; };
};

class InputNeuron: public Neuron {
public:
    InputNeuron(): input_data(0.0f) {};
    ~InputNeuron() {};

    void setInput(float data);
    float getOut();
private:
    float input_data;
};

class HiddenNeuron: public Neuron {
public:
    HiddenNeuron() {};
    ~HiddenNeuron() {};

    void calculate();
    float getOut();
    void addInputSynapce(Synapse* new_synapse);
    std::vector<Synapse*> getInputSynapses();

private:
    std::vector<Synapse*> inputSynapces;
    float sum;
    float out;
};

#endif //NEURAL_NETWORK_NEURON_HPP
