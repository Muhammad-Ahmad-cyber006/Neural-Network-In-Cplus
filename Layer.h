#pragma once
#include <iostream>
#include <vector>
#include "Neuron.h"

class Layer
{
public:
    virtual ~Layer()
    {
        for (Neuron* neuron : listOfNeurons)
            delete neuron;
    }

    // Add neurons that each get one random weight per neuron of the previous layer.
    void addNeurons(size_t count, size_t weightsPerNeuron)
    {
        for (size_t i = 0; i < count; i++)
        {
            Neuron* neuron = new Neuron();

            for (size_t k = 0; k < weightsPerNeuron; k++)
                neuron->listOfWeightsIn.push_back(neuron->initNeuron());

            listOfNeurons.push_back(neuron);
        }
    }

    // Print every neuron's incoming weights (a bias neuron has none).
    void printLayer(const char* title) const
    {
        std::cout << "### " << title << " ###" << std::endl;

        int n = 1;

        for (const Neuron* neuron : listOfNeurons)
        {
            std::cout << "Neuron #" << n++ << " weights in:";

            for (double weight : neuron->listOfWeightsIn)
                std::cout << " " << weight;

            std::cout << std::endl;
        }
    }

    std::vector<Neuron*> listOfNeurons;
};
