#pragma once
#include "Layer.h"

class InputLayer : public Layer
{
public:
    // Input neurons just hold the data, so they have no weights.
    void initLayer(size_t numberOfInputs)
    {
        addNeurons(numberOfInputs, 0);
    }
};