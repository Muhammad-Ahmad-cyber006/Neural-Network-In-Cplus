#pragma once
#include <stdlib.h>
#include <vector>
class Neuron
{
    public:
        Neuron(){}
        ~Neuron(){}
        double initNeuron(){return ((double)rand() / (RAND_MAX));}

    protected:
        std::vector<double> listOfWeightsIn;
        std::vector<double> listOfWeightsOut;
        double outputValue;
        double error;
        double sensibility;
};