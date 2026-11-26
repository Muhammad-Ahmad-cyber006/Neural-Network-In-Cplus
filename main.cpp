#include <iostream>
#include <vector>
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include "Training.h"

int main()
{
    // Build the network: 2 inputs -> 4 hidden neurons (+ bias) -> 1 output.
    InputLayer inputLayer;
    inputLayer.initLayer(2);

    HiddenLayer hiddenLayer;
    hiddenLayer.initLayer(4, inputLayer);

    OutputLayer outputLayer;
    outputLayer.initLayer(1, hiddenLayer);

    std::vector<Layer*> hiddenLayers = { &hiddenLayer };

    // XOR training inputs.
    std::vector<std::vector<double>> inputs = { {0,0}, {0,1}, {1,0}, {1,1} };

    // Expected XOR outputs.
    std::vector<std::vector<double>> targets = { {0}, {1}, {1}, {0} };

    // Train the network.
    Training::train(inputLayer, hiddenLayers, outputLayer, inputs, targets, 10000, 0.5);

    // Test the trained network: outputs close to 0 or 1 means it learned XOR.
    for (const auto& sample : inputs)
    {
        ForwardPropagation::setInputs(inputLayer, sample);
        ForwardPropagation::calculateNetwork(inputLayer, hiddenLayers, outputLayer);

        std::cout << sample[0] << " XOR " << sample[1] << " = " << outputLayer.listOfNeurons[0]->outputValue << std::endl;
    }

    return 0;
}
