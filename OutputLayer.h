
#pragma once
#include <iostream>
#include "Layer.h"

class OutputLayer : public Layer
{
public:
    OutputLayer() = default;
    ~OutputLayer() override = default;

    void initLayer();
    void printLayer() const override;
};

inline void OutputLayer::initLayer()
{
    for (size_t i = 0; i < numberOfNeuronsInLayer; i++)
    {
        Neuron* neuron = new Neuron();

        neuron->listOfWeightsOut.push_back(neuron->initNeuron());

        listOfNeurons.push_back(neuron);
    }
}

inline void OutputLayer::printLayer() const
{
    std::cout << "### OUTPUT LAYER ###" << std::endl;

    int n = 1;

    for (const Neuron* neuron : listOfNeurons)
    {
        std::cout << "Neuron #" << n++ << ":" << std::endl;
        std::cout << "Output Weights:" << std::endl;

        for (double weight : neuron->listOfWeightsOut)
        {
            std::cout << weight << std::endl;
        }
    }
}
