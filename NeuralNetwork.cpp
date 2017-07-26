#include "NeuralNetwork.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cassert>
#include <ctime>
#include <random>

using std::cout;
using std::endl;


NeuralNetwork::NeuralNetwork(int inpNeurons, int hidNeurons, int outNeurons, bool bias) {

    srand((u_int)time(0));

    // Создание нейронов
    for (int i = 0; i < inpNeurons; ++i)
        inputNeurons.push_back(new InputNeuron());
    for (int i = 0; i < hidNeurons; ++i)
        hiddenNeurons.push_back(new HiddenNeuron());
    for (int i = 0; i < outNeurons; ++i)
        outputNeurons.push_back(new HiddenNeuron());

    // Создание связей между нейронами
    // input <---> hidden
    int count_synapces = 0;
    Synapse* synapce = nullptr;
    for (auto inputNeuron: inputNeurons) {
        for(auto hiddenNeuron: hiddenNeurons) {
            synapce = new Synapse(inputNeuron, hiddenNeuron);
            hiddenNeuron->addInputSynapce(synapce);
            inputNeuron->addOutputSynapce(synapce);
            ++count_synapces;
        }
    }
    // hidden <---> output
    for (auto hiddenNeuron: hiddenNeurons) {
        for(auto outputNeuron: outputNeurons) {
            synapce = new Synapse(hiddenNeuron, outputNeuron);
            outputNeuron->addInputSynapce(synapce);
            hiddenNeuron->addOutputSynapce(synapce);
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

//    delete bias;
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
void NeuralNetwork::Learning(std::vector<std::vector<float>> input_data,
                             std::vector<std::vector<float>> output_data,
                             float learning_rate, int cycles) {

    for (int j = 0; j < cycles; ++j) {
        for (int i = 0; i < input_data.size(); ++i) {
            getResult(input_data[i]);
            calculateMistake(output_data[i], true);
            dictionary neuronDelta = createDelta(learning_rate, output_data[i]);
            changesWeights(neuronDelta);
        }
        cout << endl;
    }
}
float NeuralNetwork::calculateMistake(std::vector<float> correct_output, bool print) {

    assert(correct_output.size() == outputNeurons.size());

    float sum = 0;
    float delta = 0;
    for (int i = 0; i < outputNeurons.size(); ++i) {
        delta = outputNeurons[i]->getOut() - correct_output[i];
        sum += delta * delta;
    }

    if (print)
        printf("Mistake: %6.2f %%\n", sum * 100);

    return (sum / outputNeurons.size());
}

dictionary NeuralNetwork::createDelta(float learning_rate, std::vector<float> correct_output) {

    assert(outputNeurons.size() == correct_output.size());

    dictionary neuronDelta;
    float temp;

    // Формула, по которой вычисляются дельты:
    // δ = f' * [ Σ(k ∈ Children) Wk*δk ]

    // Формируем дельты для выходного слоя нейронов и записываем их в словарь
    for (int i = 0; i < outputNeurons.size(); ++i) {
        temp = outputNeurons[i]->getOut() - correct_output[i];
        temp = 2 * learning_rate * temp * diffActivate(outputNeurons[i]->getOut());
        neuronDelta.insert(dic_pair(outputNeurons[i], temp));
    }

    // Формируем дельты для внутреннего слоя нейронов и записываем их в словарь
    std::vector<Synapse*> synapses;
    for (auto hiddenNeuron: hiddenNeurons) {

        synapses = hiddenNeuron->getOutputSynapses();
        temp = 0;

        for (auto synapse: synapses) // Σ Wk*δk
            temp += synapse->getWeight() * neuronDelta[(HiddenNeuron *) synapse->getOutputNeuron()];

        temp *= diffActivate(hiddenNeuron->getOut()); // f' * Σ
        neuronDelta.insert(dic_pair(hiddenNeuron, temp));
    }

    // TODO bias

    return neuronDelta;
}
void NeuralNetwork::changesWeights(dictionary &neuronDelta) {

    const float moment = 0.2;
    float delta, dw, q;

    // В словаре хранится недосчитанный градиент для каждого узла,
    // чтобы узнать в какую сторону нужно сдвинуть вес для уменьшения ошибки
    // надо домножить ее на входящее значение соответсвующего синапса, т.е.
    // Δw = δ * q, где q - входящее в текущий синапс значение

    std::vector<Synapse*> synapses;
    for(auto neuron: neuronDelta) {
        delta = neuron.second;
        synapses = neuron.first->getInputSynapses();
        for (auto synapse: synapses) {
            q = synapse->getInputNeuron()->getOut();
            dw = delta * q;
            dw = -(dw + moment * synapse->getPrevDelta());
            synapse->addWeight(dw);
        }
    }
}