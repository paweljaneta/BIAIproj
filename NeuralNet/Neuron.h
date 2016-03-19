#pragma once
#include <vector>
#include "ActivationTypes.h"
#include <math.h>

using namespace std;

class Input
{
private:
	double inputSignal;
	double inputWeight;

public:

	Input()
	{

	}

	Input(double signal, double weight)
	{
		inputSignal = signal;
		inputWeight = weight;
	}

	~Input()
	{

	}


	void setInputWeight(double weight)
	{
		inputWeight = weight;
	}

	void setInputSignal(double signal)
	{
		inputSignal = signal;
	}

	double getInputWeight()
	{
		return inputWeight;
	}

	double getInputSignal()
	{
		return inputSignal;
	}

	double getSigMulWeight()
	{
		return inputSignal*inputWeight;
	}
};



class Neuron
{
private:
	vector<Input> inputVector;
	ActivationType activationType;

	double alfa;
	double beta;

	bool alfaSet;
	bool betaSet;

	double sum;
	double outputValue;

	void calculateSum()
	{
		sum = 0;

		for (int i = 0; i < inputVector.size(); i++)
		{
			sum += inputVector[i].getSigMulWeight();
		}
	}

	//Activation functions

	void linearActivation()
	{
		outputValue = sum;
	}

	void cutLinearActivation()
	{
		outputValue = sum;

		if (outputValue > 1)
			outputValue = 1;

		if (outputValue < -1)
			outputValue = -1;

	}

	void unipolarEdgeActivation()
	{
		if (sum < 0)
			outputValue = 0;
		else
			outputValue = 1;
	}

	void bipolarEdgeActivation()
	{
		if (sum < 0)
			outputValue = -1;
		else
			outputValue = 1;
	}

	void unipolarSigmoidalActivation()
	{
		if(betaSet)
		outputValue = 1.0 / (1.0 + exp(-beta*sum));
	}

	void bipolarSigmoidalActivation()
	{
		if(betaSet)
		outputValue = 2.0 / (1.0 + exp(-beta*sum)) - 1.0;
	}

	void tanhActivation()
	{
		if (alfaSet)
			outputValue = (1.0 - exp(-alfa*sum)) / (1.0 + exp(-alfa*sum));
	}

	void activation()
	{
		switch (activationType) {
		case ActivationType::linear:
			linearActivation();
			break;
		case ActivationType::cutLinear:
			cutLinearActivation();
			break;
		case ActivationType::unipolarEdge:
			unipolarEdgeActivation();
			break;
		case ActivationType::bipolarEdge:
			bipolarEdgeActivation();
			break;
		case ActivationType::unipolarSigmoidal:
			unipolarSigmoidalActivation();
			break;
		case ActivationType::bipolarSigmoidal:
			bipolarSigmoidalActivation();
			break;
		case ActivationType::tanh:
			tanhActivation();
			break;
		}
	}


public:

	//dodaæ alfa, beta
	Neuron()
	{
	}

	Neuron(vector<Input> inVect, ActivationType actType)
	{
		inputVector = inVect;
		activationType = actType;
	}

	Neuron(vector<pair<double, double>> inVect, ActivationType actType) //pair of signal,weight
	{
		for (int i = 0; i < inVect.size(); i++) {
			inputVector.push_back(Input(inVect[i].first, inVect[i].second));
		}

		activationType = actType;
	}

	~Neuron()
	{
	}

	void work()
	{
		calculateSum();
		activation();
	}

	double getOutputValue()
	{
		return outputValue;
	}
};

