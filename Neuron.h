#pragma once
#include <cstdlib>
#include <vector>

class Neuron
{
public:
    // Random starting weight in [-1, 1]; positive and negative values let neurons learn different things.
    double initNeuron()
    {
        return 2.0 * static_cast<double>(std::rand()) / RAND_MAX - 1.0;
    }

    // One weight per neuron of the previous layer (empty for input and bias neurons).
    std::vector<double> listOfWeightsIn;
    // The neurons result after the activation function.
    double outputValue = 0.0;
    // The error signal (delta) will be used by backpropagation.
    double error = 0.0;
};
