#include "NeuralNetwork.hpp"
#include <iostream>
#include <cassert>
#include <ctime>
#include <random>

using std::cout;
using std::endl;


NeuralNetwork::NeuralNetwork(int inpNeurons, int hidNeurons, int outNeurons, bool bias) {

//    srand((u_int)time(0));

    // Создание нейронов
    for (int i = 0; i < inpNeurons; ++i)
        inputNeurons.push_back(new InputNeuron());
    for (int i = 0; i < hidNeurons; ++i)
        hiddenNeurons.push_back(new HiddenNeuron());
    for (int i = 0; i < outNeurons; ++i)
        outputNeurons.push_back(new HiddenNeuron());

    // Создание связей между нейронами
    int count_synapces = 0;
    Synapse* synapce = nullptr;
    for (auto inputNeuron: inputNeurons) {
        for(auto hiddenNeuron: hiddenNeurons) {
            synapce = new Synapse(inputNeuron, hiddenNeuron);
            hiddenNeuron->addInputSynapce(synapce);
            ++count_synapces;
        }
    }
    for (auto hiddenNeuron: hiddenNeurons) {
        for(auto outputNeuron: outputNeurons) {
            synapce = new Synapse(hiddenNeuron, outputNeuron);
            outputNeuron->addInputSynapce(synapce);
            ++count_synapces;
        }
    }

    // TODO bias
    std::cout << "Создано " << count_synapces << " синапсов" << endl;
}
NeuralNetwork::~NeuralNetwork() {

    std::vector<Synapse *> synapses;
    for (auto outputNeuron: outputNeurons) {
        synapses = outputNeuron->getInputSynapses();
        deleteSynapses(synapses);
        delete outputNeuron;
    }
    for (auto hiddenNeuron: hiddenNeurons) {
        synapses = hiddenNeuron->getInputSynapses();
        deleteSynapses(synapses);
        delete hiddenNeuron;
    }
    for (auto inputNeuron: inputNeurons)
        delete inputNeuron;

    // TODO bias
}
void NeuralNetwork::deleteSynapses(std::vector<Synapse*> &synapses) {

    for (auto synapce: synapses)
        delete synapce;
}

std::vector<float> NeuralNetwork::getResult(std::vector<float> input_data) {

    assert(input_data.size() == inputNeurons.size());
    for (int i = 0; i < inputNeurons.size(); ++i)
        inputNeurons[i]->setInput(input_data[i]);

    std::vector<float> result;
    for (auto hiddenNeuron: hiddenNeurons)
        hiddenNeuron->calculate();
    for (auto outputNeuron: outputNeurons) {
        outputNeuron->calculate();
        result.push_back(outputNeuron->getOut());
    }
    return result;
}