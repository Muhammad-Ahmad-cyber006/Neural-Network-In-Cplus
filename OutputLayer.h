#pragma once
#include "Layer.h"

class OutputLayer : public Layer
{
public:
    // The output layer has no bias neuron, so every neuron here has weights in.
    void initLayer(size_t numberOfNeurons, const Layer& previousLayer)
    {
        addNeurons(numberOfNeurons, previousLayer.listOfNeurons.size());
    }
};
