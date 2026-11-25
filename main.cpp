
#include "InputLayer.h"

int main()
{
    InputLayer inputLayer;

    inputLayer.numberOfNeuronsInLayer = 5;

    inputLayer.initLayer();
    inputLayer.printLayer();

    return 0;
}