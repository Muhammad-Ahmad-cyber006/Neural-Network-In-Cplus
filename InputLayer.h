
#pragma once
#include <iostream>
#include "Layer.h"

class InputLayer : public Layer
{
public:
    InputLayer() = default;
    ~InputLayer() override = default;

    void initLayer();
    void printLayer() const override;
};

inline void InputLayer::initLayer()
{
    for (size_t i = 0; i < numberOfNeuronsInLayer; i++)
    {
        Neuron* neuron = new Neuron();

        neuron->listOfWeightsIn.push_back(neuron->initNeuron());

        listOfNeurons.push_back(neuron);
    }
}

inline void InputLayer::printLayer() const
{
    std::cout << "### INPUT LAYER ###" << std::endl;

    int n = 1;

    for (const Neuron* neuron : listOfNeurons)
    {
        std::cout << "Neuron #" << n++ << ":" << std::endl;
        std::cout << "Input Weights:" << std::endl;

        for (double weight : neuron->listOfWeightsIn)
        {
            std::cout << weight << std::endl;
        }
    }
}
