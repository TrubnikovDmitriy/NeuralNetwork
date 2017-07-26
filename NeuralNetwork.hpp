#ifndef NEURAL_NETWORK_NEURALNETWORK_HPP
#define NEURAL_NETWORK_NEURALNETWORK_HPP

#include <map>
#include "Synapse.hpp"
#include "Neuron.hpp"

typedef std::map<HiddenNeuron*, float> dictionary;
typedef std::pair<HiddenNeuron*, float> dic_pair;


class NeuralNetwork {
public:
    NeuralNetwork(int inpNeurons = 2, int hidNeurons = 3, int outNeurons = 1, bool bias = false);
    ~NeuralNetwork();

    std::vector<float> getResult(std::vector<float> input_data);
    void Learning(std::vector<std::vector<float>> input_data,
                  std::vector<std::vector<float>> output_data,
                  float learning_rate, int cycles);

private:
    dictionary createDelta(float learning_rate, std::vector<float> correct_output);
    float calculateMistake(std::vector<float> correct_output, bool print = false);
    void changesWeights(dictionary &neuronDelta);
    void deleteSynapses(std::vector<Synapse *> &synapses);

    std::vector<InputNeuron*> inputNeurons;
    std::vector<HiddenNeuron*> outputNeurons;
    std::vector<HiddenNeuron*> hiddenNeurons;
    BiasNeuron* bias;

};


#endif //NEURAL_NETWORK_NEURALNETWORK_HPP
