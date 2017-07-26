#ifndef NEURAL_NETWORK_NEURON_HPP
#define NEURAL_NETWORK_NEURON_HPP

#include <vector>
#include "Utils.hpp"

class Neuron {
public:
    Neuron(Synapce* outp);
    Neuron();
    virtual ~Neuron() {};

    void addOutputSynapce(Synapce* new_synapce);
    virtual float getOut() = 0;

protected:
    Synapce* outputSynapce;
};

class BiasNeuron: protected Neuron {
public:
    BiasNeuron(Synapce* outp);
    BiasNeuron() {};
    ~BiasNeuron() {};

    float getOut() { return 1.0f; };
};

class InputNeuron: protected Neuron {
public:
    InputNeuron(Synapce* outp);
    InputNeuron() {};
    ~InputNeuron() {};

    void setInput(float data);
    float getOut();
private:
    float input_data;
};

class HiddenNeuron: protected Neuron {
public:
    HiddenNeuron(Synapce* outp);
    HiddenNeuron() {};
    ~HiddenNeuron() {};

    void calculate();
    float getOut();
    void addInputSynapce(Synapce* new_synapce);

private:
    void sumSynapces();
    void activate();

    std::vector<Synapce*> inputSynapces;
    float sum;
    float out;
};

#endif //NEURAL_NETWORK_NEURON_HPP
