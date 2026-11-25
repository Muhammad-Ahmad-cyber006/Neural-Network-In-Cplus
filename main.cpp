#include "OutputLayer.h"

int main()
{
    OutputLayer outputLayer;

    outputLayer.numberOfNeuronsInLayer = 3;

    outputLayer.initLayer();
    outputLayer.printLayer();

    return 0;
}