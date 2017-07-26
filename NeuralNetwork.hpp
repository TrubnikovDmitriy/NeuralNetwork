#ifndef NEURAL_NETWORK_NEURALNETWORK_HPP
#define NEURAL_NETWORK_NEURALNETWORK_HPP

#include "Synapse.hpp"
#include "Neuron.hpp"


class NeuralNetwork {
public:
    NeuralNetwork(int inpNeurons = 2, int hidNeurons = 3, int outNeurons = 1, bool bias = false);
    ~NeuralNetwork();

    std::vector<float> getResult(std::vector<float> input_data);
    void Learning(std::vector<std::vector<float>> input_data,
                  std::vector<std::vector<float>> output_data);

private:
    void deleteSynapses(std::vector<Synapse *> &synapses);
    float calculateMistake(std::vector<float> correct_output);

    std::vector<InputNeuron*> inputNeurons;
    std::vector<HiddenNeuron*> outputNeurons;
    std::vector<HiddenNeuron*> hiddenNeurons;

};


#endif //NEURAL_NETWORK_NEURALNETWORK_HPP
