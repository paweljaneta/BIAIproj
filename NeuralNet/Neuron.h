#pragma once

#include <vector>
#include "ActivationTypes.h"
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

class Input
{
private:
	double inputSignal;
	double inputWeight;

public:

	Input()
	{
		srand(time(NULL));
		inputWeight= (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;
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

	double learnSpeed;

	double sum;
	double outputValue;

	double delta;


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
		outputValue = 1.0 / (1.0 + exp(-learnSpeed*sum));
	}

	void bipolarSigmoidalActivation()
	{
		outputValue = 2.0 / (1.0 + exp(-learnSpeed*sum)) - 1.0;
	}

	void tanhActivation()
	{
			//outputValue = (1.0 - exp(-learnSpeed*sum)) / (1.0 + exp(-learnSpeed*sum));
		outputValue = tanh(sum);
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


	void linearUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++) 
		{
			inputVector[i].setInputWeight(inputVector[i].getInputWeight()+learnSpeed*delta*inputVector[i].getInputSignal());
		}
	}

	void cutLinearUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++)
		{
			if (!(outputValue >= 1 || outputValue <= -1))
			{
				inputVector[i].setInputWeight(inputVector[i].getInputWeight() + learnSpeed*delta*inputVector[i].getInputSignal());
			}
		}
	}

	void unipolarEdgeUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++)
		{
			
		}
	}

	void bipolarEdgeUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++)
		{

		}
	}

	void unipolarSigmoidalUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++)
		{
			inputVector[i].setInputWeight(inputVector[i].getInputWeight() + learnSpeed*delta*inputVector[i].getInputSignal()*(outputValue*(1.0 - outputValue)));
		}
	}

	void bipolarSigmoidalUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++)
		{
			inputVector[i].setInputWeight(inputVector[i].getInputWeight() + learnSpeed*delta*inputVector[i].getInputSignal()*((1.0 - outputValue *outputValue) / 2.0));
		}
	}

	void tanhUpdate()
	{
		for (int i = 0; i < inputVector.size(); i++)
		{
			inputVector[i].setInputWeight(inputVector[i].getInputWeight() + learnSpeed*delta*inputVector[i].getInputSignal()*(1-tanh(sum)*tanh(sum)));
		}
	}

	void update()
	{
		switch (activationType) {
		case ActivationType::linear:
			linearUpdate();
			break;
		case ActivationType::cutLinear:
			cutLinearUpdate();
			break;
		case ActivationType::unipolarEdge:
			unipolarEdgeUpdate();
			break;
		case ActivationType::bipolarEdge:
			bipolarEdgeUpdate();
			break;
		case ActivationType::unipolarSigmoidal:
			unipolarSigmoidalUpdate();
			break;
		case ActivationType::bipolarSigmoidal:
			bipolarSigmoidalUpdate();
			break;
		case ActivationType::tanh:
			tanhUpdate();
			break;
		}
	}
public:

	Neuron()
	{
	}

	Neuron(vector<Input> inVect, ActivationType actType,double learnRatio)
	{
		inputVector = inVect;
		activationType = actType;
		learnSpeed = learnRatio;
	}

	Neuron(vector<pair<double, double>> inVect, ActivationType actType, double learnRatio) //pair of signal,weight
	{
		for (int i = 0; i < inVect.size(); i++) {
			inputVector.push_back(Input(inVect[i].first, inVect[i].second));
		}

		activationType = actType;
		learnSpeed = learnRatio;
	}

	~Neuron()
	{
	}

	void work()
	{
		calculateSum();
		activation();
	}

	void updateWeights()
	{
		update();
	}

	void setDelta(double d)
	{
		delta = d;
	}

	double getDelta()
	{
		return delta;
	}

	double getDeltaMulWeight(int index)
	{
		return delta*inputVector[index].getInputWeight();
	}

	double getOutputValue()
	{
		return outputValue;
	}
};

