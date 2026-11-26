#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace Activation
{
    // Sigmoid squashes any number into (0, 1): 1 / (1 + e^-x).
    inline double sigmoid(double x)
    {
        // Two branches avoid overflow in exp() for large positive or negative x.
        if (x >= 0.0)
            return 1.0 / (1.0 + std::exp(-x));

        double expX = std::exp(x);
        return expX / (1.0 + expX);
    }

    // Derivative of sigmoid written in terms of its OUTPUT: s * (1 - s).
    inline double sigmoidDerivative(double output)
    {
        return output * (1.0 - output);
    }

    // ReLU passes positive numbers and blocks negative ones: max(0, x).
    inline double relu(double x)
    {
        return std::max(0.0, x);
    }

    // ReLU slope is 1 when the neuron is active and 0 when it is off.
    inline double reluDerivative(double x)
    {
        return x > 0.0 ? 1.0 : 0.0;
    }

    // Tanh squashes any number into (-1, 1).
    inline double tanh(double x)
    {
        return std::tanh(x);
    }

    // Derivative of tanh written in terms of its OUTPUT: 1 - t^2.
    inline double tanhDerivative(double output)
    {
        return 1.0 - (output * output);
    }

    // Softmax turns a list of scores into probabilities that add up to 1.
    inline std::vector<double> softmax(const std::vector<double>& inputs)
    {
        if (inputs.empty())
            throw std::invalid_argument("Softmax input cannot be empty");

        std::vector<double> outputs(inputs.size());

        // Subtracting the max keeps exp() from overflowing and does not change the result.
        double maxValue = *std::max_element(inputs.begin(), inputs.end());

        double sum = 0.0;

        for (size_t i = 0; i < inputs.size(); i++)
        {
            outputs[i] = std::exp(inputs[i] - maxValue);
            sum += outputs[i];
        }

        // Divide by the sum so all outputs add up to 1.
        for (double& value : outputs)
            value /= sum;

        return outputs;
    }
}
