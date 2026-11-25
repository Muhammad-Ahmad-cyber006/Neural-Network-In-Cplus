
#pragma once
#include <iostream>
#include <vector>
#include "Layer.h"
#include "InputLayer.h"
#include "OutputLayer.h"

class HiddenLayer : public Layer
{
public:
    HiddenLayer() = default;
    ~HiddenLayer() override = default;

    static void initLayer(
        std::vector<HiddenLayer*>& listOfHiddenLayer,
        const InputLayer& inputLayer,
        const OutputLayer& outputLayer
    );

    void printLayer(
        const std::vector<HiddenLayer*>& listOfHiddenLayer
    ) const;
};

inline void HiddenLayer::initLayer(
    std::vector<HiddenLayer*>& listOfHiddenLayer,
    const InputLayer& inputLayer,
    const OutputLayer& outputLayer
)
{
    size_t numberOfHiddenLayers = listOfHiddenLayer.size();

    for (size_t i = 0; i < numberOfHiddenLayers; i++)
    {
        HiddenLayer* currentLayer = listOfHiddenLayer[i];

        size_t limitIn;
        size_t limitOut;

        // Determine previous layer neuron count
        if (i == 0)
        {
            limitIn = inputLayer.numberOfNeuronsInLayer;
        }
        else
        {
            limitIn = listOfHiddenLayer[i - 1]->numberOfNeuronsInLayer - 1;
        }

        // Determine next layer neuron count
        if (i == numberOfHiddenLayers - 1)
        {
            limitOut = outputLayer.numberOfNeuronsInLayer;
        }
        else
        {
            limitOut = listOfHiddenLayer[i + 1]->numberOfNeuronsInLayer - 1;
        }

        for (size_t j = 0; j < currentLayer->numberOfNeuronsInLayer; j++)
        {
            Neuron* neuron = new Neuron();

            // Bias neuron does not receive input weights
            if (j != 0)
            {
                for (size_t k = 0; k < limitIn; k++)
                {
                    neuron->listOfWeightsIn.push_back(
                        neuron->initNeuron()
                    );
                }
            }

            // Initialize outgoing weights
            for (size_t k = 0; k < limitOut; k++)
            {
                neuron->listOfWeightsOut.push_back(
                    neuron->initNeuron()
                );
            }

            currentLayer->listOfNeurons.push_back(neuron);
        }
    }
}

inline void HiddenLayer::printLayer(
    const std::vector<HiddenLayer*>& listOfHiddenLayer
) const
{
    std::cout << "### HIDDEN LAYERS ###" << std::endl;

    int h = 1;

    for (const HiddenLayer* hiddenLayer : listOfHiddenLayer)
    {
        std::cout << "Hidden Layer #" << h++ << std::endl;

        int n = 1;

        for (const Neuron* neuron : hiddenLayer->listOfNeurons)
        {
            std::cout << "Neuron #" << n++ << std::endl;

            std::cout << "Input Weights:" << std::endl;

            for (double weight : neuron->listOfWeightsIn)
            {
                std::cout << weight << " ";
            }

            std::cout << std::endl;
            std::cout << "Output Weights:" << std::endl;

            for (double weight : neuron->listOfWeightsOut)
            {
                std::cout << weight << " ";
            }

            std::cout << std::endl;
        }
    }
}
