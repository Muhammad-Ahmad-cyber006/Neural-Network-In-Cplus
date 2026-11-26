#pragma once
#include <vector>
#include "Layer.h"
#include "Activation.h"

class ForwardPropagation
{
public:
    // Copy one training sample into the input neurons.
    static void setInputs(Layer& inputLayer, const std::vector<double>& sample)
    {
        for (size_t i = 0; i < inputLayer.listOfNeurons.size(); i++)
            inputLayer.listOfNeurons[i]->outputValue = sample[i];
    }

    // Compute a layer's outputs: activation(sum of previous output * weight).
    static void calculateLayer(Layer& currentLayer, const Layer& previousLayer, bool isOutputLayer)
    {
        for (Neuron* neuron : currentLayer.listOfNeurons)
        {
            // A bias neuron has no weights and must keep its output of 1.
            if (neuron->listOfWeightsIn.empty())
                continue;

            // Weighted sum: z = w0*x0 + w1*x1 + ...
            double sum = 0.0;

            for (size_t j = 0; j < previousLayer.listOfNeurons.size(); j++)
                sum += previousLayer.listOfNeurons[j]->outputValue * neuron->listOfWeightsIn[j];

            // Hidden layers use ReLU; the output layer uses sigmoid to give a value in (0, 1).
            neuron->outputValue = isOutputLayer ? Activation::sigmoid(sum) : Activation::relu(sum);
        }
    }

    // Run the whole network: input -> hidden layers -> output.
    static void calculateNetwork(
        const Layer& inputLayer,
        const std::vector<Layer*>& hiddenLayers,
        Layer& outputLayer)
    {
        const Layer* previousLayer = &inputLayer;

        for (Layer* hiddenLayer : hiddenLayers)
        {
            calculateLayer(*hiddenLayer, *previousLayer, false);
            previousLayer = hiddenLayer;
        }

        calculateLayer(outputLayer, *previousLayer, true);
    }
};
