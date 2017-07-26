#ifndef NEURAL_NETWORK_NEURON_HPP
#define NEURAL_NETWORK_NEURON_HPP

#include <vector>
#include "Utils.hpp"

class Neuron {
public:
    Neuron(Synapse* outp);
    Neuron();
    virtual ~Neuron() {};

//    void setOutputSynapce(Synapse *new_synapce);
//    void addInputSynapce(Synapse* new_synapce) {}; ???
    virtual float getOut() = 0;

protected:
    Synapse* outputSynapce;
};

class BiasNeuron: public Neuron {
public:
    BiasNeuron(Synapse* outp);
    BiasNeuron() {};
    ~BiasNeuron() {};

    float getOut() { return 1.0f; };
};

class InputNeuron: public Neuron {
public:
    InputNeuron(Synapse* outp);
    InputNeuron() {};
    ~InputNeuron() {};

    void setInput(float data);
    float getOut();
private:
    float input_data;
};

class HiddenNeuron: public Neuron {
public:
    HiddenNeuron(Synapse* outp);
    HiddenNeuron() {};
    ~HiddenNeuron() {};

    void calculate();
    float getOut();
    void addInputSynapce(Synapse* new_synapse);
    std::vector<Synapse*> getInputSynapses();

private:
    void sumSynapses();
    void activate();

    std::vector<Synapse*> inputSynapces;
    float sum;
    float out;
};

#endif //NEURAL_NETWORK_NEURON_HPP
