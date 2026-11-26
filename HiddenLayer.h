#pragma once
#include "Layer.h"

class HiddenLayer : public Layer
{
public:
    void initLayer(size_t numberOfNeurons, const Layer& previousLayer)
    {
        // Neuron 0 is the bias: no weights in, and its output is always 1.
        addNeurons(1, 0);
        listOfNeurons[0]->outputValue = 1.0;

        // Every other neuron connects to ALL neurons of the previous layer (bias included).
        addNeurons(numberOfNeurons, previousLayer.listOfNeurons.size());
    }
};
