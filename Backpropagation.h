#pragma once
#include <vector>
#include "Layer.h"
#include "Activation.h"

class Backpropagation
{
public:
    // Output error: delta = (output - target) * sigmoid (output), from loss = 0.5 * (output - target)^2.
    static void calculateOutputErrors(Layer& outputLayer, const std::vector<double>& targets)
    {
        for (size_t i = 0; i < outputLayer.listOfNeurons.size(); i++)
        {
            Neuron* neuron = outputLayer.listOfNeurons[i];
            neuron->error = (neuron->outputValue - targets[i]) * Activation::sigmoidDerivative(neuron->outputValue);
        }
    }

    // Hidden error: delta = (sum of next delta * connecting weight) * relu (output).
    static void calculateHiddenErrors(Layer& currentLayer, const Layer& nextLayer)
    {
        for (size_t i = 0; i < currentLayer.listOfNeurons.size(); i++)
        {
            Neuron* neuron = currentLayer.listOfNeurons[i];
            double errorSum = 0.0;

            for (const Neuron* next : nextLayer.listOfNeurons)
            {
                // A bias neuron in the next layer has no weights, so it passes back nothing.
                if (next->listOfWeightsIn.empty())
                    continue;

                // Weight i in the next neuron is the connection coming from this neuron.
                errorSum += next->error * next->listOfWeightsIn[i];
            }

            neuron->error = errorSum * Activation::reluDerivative(neuron->outputValue);
        }
    }

    // Gradient descent: weight = weight - learningRate * delta * input.
    static void updateWeights(Layer& currentLayer, const Layer& previousLayer, double learningRate)
    {
        for (Neuron* neuron : currentLayer.listOfNeurons)
        {
            // A bias neuron has no weights, so this loop does nothing for it.
            for (size_t j = 0; j < neuron->listOfWeightsIn.size(); j++)
                neuron->listOfWeightsIn[j] -= learningRate * neuron->error * previousLayer.listOfNeurons[j]->outputValue;
        }
    }
};
