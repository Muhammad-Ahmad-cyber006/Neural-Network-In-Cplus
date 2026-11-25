
#pragma once
#include <vector>
#include "Neuron.h"

class Layer
{
public:
    Layer() = default;

    virtual ~Layer()
    {
        for (Neuron* neuron : listOfNeurons)
            delete neuron;
    }

    virtual void printLayer() const {}

    std::vector<Neuron*> listOfNeurons;
    size_t numberOfNeuronsInLayer = 0;
};
