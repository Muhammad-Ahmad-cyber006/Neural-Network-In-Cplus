#pragma once
#include <vector>
#include <iostream>
#include "ForwardPropagation.h"
#include "Backpropagation.h"

class Training
{
public:
    // Train the network on input samples and their target values.
    static void train(
        Layer& inputLayer,
        std::vector<Layer*>& hiddenLayers,
        Layer& outputLayer,
        const std::vector<std::vector<double>>& trainingInputs,
        const std::vector<std::vector<double>>& trainingTargets,
        int epochs,
        double learningRate)
    {
        int lastHidden = static_cast<int>(hiddenLayers.size()) - 1;

        for (int epoch = 0; epoch < epochs; epoch++)
        {
            double totalLoss = 0.0;

            for (size_t sample = 0; sample < trainingInputs.size(); sample++)
            {
                // Step 1: forward pass.
                ForwardPropagation::setInputs(inputLayer, trainingInputs[sample]);
                ForwardPropagation::calculateNetwork(inputLayer, hiddenLayers, outputLayer);

                // Loss = 0.5 * (output - target)^2, the same loss the output error formula uses.
                for (size_t i = 0; i < outputLayer.listOfNeurons.size(); i++)
                {
                    double difference = outputLayer.listOfNeurons[i]->outputValue - trainingTargets[sample][i];
                    totalLoss += 0.5 * difference * difference;
                }

                // Step 2: compute all errors first, from the output layer backwards.
                Backpropagation::calculateOutputErrors(outputLayer, trainingTargets[sample]);

                for (int i = lastHidden; i >= 0; i--)
                {
                    Layer& nextLayer = (i == lastHidden) ? outputLayer : *hiddenLayers[i + 1];
                    Backpropagation::calculateHiddenErrors(*hiddenLayers[i], nextLayer);
                }

                // Step 3: update weights only after every error is known.
                Layer* previousLayer = hiddenLayers.empty() ? &inputLayer : hiddenLayers.back();
                Backpropagation::updateWeights(outputLayer, *previousLayer, learningRate);

                for (int i = lastHidden; i >= 0; i--)
                {
                    previousLayer = (i == 0) ? &inputLayer : hiddenLayers[i - 1];
                    Backpropagation::updateWeights(*hiddenLayers[i], *previousLayer, learningRate);
                }
            }

            // Print the average loss every 1000 epochs so the output stays readable.
            if ((epoch + 1) % 1000 == 0)
                std::cout << "Epoch " << epoch + 1 << " | Loss: " << totalLoss / trainingInputs.size() << std::endl;
        }
    }
};
