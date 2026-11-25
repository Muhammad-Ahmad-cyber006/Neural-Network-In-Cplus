#include "HiddenLayer.h"

int main()
{
    InputLayer inputLayer;
    OutputLayer outputLayer;

    inputLayer.numberOfNeuronsInLayer = 3;
    outputLayer.numberOfNeuronsInLayer = 2;

    std::vector<HiddenLayer*> hiddenLayers;

    HiddenLayer* hidden1 = new HiddenLayer();
    hidden1->numberOfNeuronsInLayer = 5;

    HiddenLayer* hidden2 = new HiddenLayer();
    hidden2->numberOfNeuronsInLayer = 4;

    hiddenLayers.push_back(hidden1);
    hiddenLayers.push_back(hidden2);

    HiddenLayer::initLayer(hiddenLayers, inputLayer, outputLayer);

    HiddenLayer printer;
    printer.printLayer(hiddenLayers);

    // Release allocated hidden layers and their neurons
    for (HiddenLayer* layer : hiddenLayers)
    {
        delete layer;
    }

    return 0;
}