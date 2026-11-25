#pragma once
#include <cstdlib>
#include <vector>

class Neuron
{
public:
    Neuron() = default;
    ~Neuron() = default;

    double initNeuron()
    {
        return static_cast<double>(std::rand()) / RAND_MAX;
    }

    std::vector<double> listOfWeightsIn;
    std::vector<double> listOfWeightsOut;
    double outputValue = 0.0;
    double error = 0.0;
    double sensibility = 0.0;
};