#pragma once

#include <vector>
#include "ActivationTypes.h"
#include <math.h>
#include <cstdlib>
//#include <time.h>
#include <ctime>
#include <string>

using namespace std;

template <typename ActivationType>
constexpr auto to_underlying(ActivationType e) noexcept
{
	return static_cast<std::underlying_type_t<ActivationType>>(e);
}

class Input
{
private:
	double inputSignal;
	double inputWeight;

public:

	Input()
	{
		//srand(clock());
		inputWeight= (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;
	}

	Input(double signal)
	{
		inputSignal = signal;

		//srand(clock());
		inputWeight = (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;
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


	string toString() {
		string str = to_string(1.0) + " ";
		str += to_string(this->inputWeight) + "\n";
		return str;
	}

	static Input fromString(string str) {
		string input_signal_str = str.substr(0, str.find(" ", 0));
		string input_weight_str = str.substr(str.find(" ", 0), str.length());
		double input_signal = stod(input_signal_str);
		double input_weight = stod(input_weight_str);
		return Input(input_signal, input_weight);
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

	Neuron(vector<Input> inVect, ActivationType actType, double learnRatio, double outputValue, double sum, double delta)
	{
		inputVector = inVect;
		activationType = actType;
		learnSpeed = learnRatio;
		outputValue = outputValue;
		sum = sum;
		delta = delta;
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

	void setInput(int index, double value)
	{
		inputVector[index].setInputSignal(value);
	}

	string toString() {
		string str = "Input\n";
		str += to_string(inputVector.size())+ "\n";
		for (int i = 0; i < this->inputVector.size(); i++) {
			str += inputVector[i].toString();
		}
		int type = to_underlying(this->activationType);
		str += to_string(type) + " ";
		str += to_string(this->learnSpeed) + " ";
		str += to_string(0.0) + " ";
		str += to_string(0.0)+ " ";
		str += to_string(0.0)+ "\n";
		return str;
	}

	static Neuron fromString(string &str) {
		int index = str.find("Input", 0);
		index += 5;
		int input_size = stoi(str.substr(index, str.find("\n", index)));
		str = str.substr(str.find("\n", index)+1, str.length());
		index = str.find("\n", 0);
		vector<Input> input_vector;
		str = str.substr(index+1, str.length());
		for (int i = 0; i < input_size; i++) {
			Input in = Input::fromString(str.substr(0, str.find("\n", 0)));
			input_vector.push_back(in);
			index = str.find("\n", 0);
			str = str.substr(index+1, str.length());
		}
		string activation_type_string = str.substr(0, str.find(" ", 0));
		str = str.substr(str.find(" ")+1, str.length());
		string learn_speed_string = str.substr(0, str.find(" ", 0));
		str = str.substr(str.find(" ")+1, str.length());
		string sum_string = str.substr(0, str.find(" ", 0));
		str = str.substr(str.find(" ")+1, str.length());
		string output_value_string = str.substr(0, str.find(" ", 0));
		str = str.substr(str.find(" ")+1, str.length());
		string delta_string = str.substr(0, str.find("\n", 0));
		str = str.substr(str.find("\n")+1, str.length());
		int activation_type = stoi(activation_type_string);
		double learn_speed = stod(learn_speed_string);
		double sum = stod(sum_string);
		double output_value = stod(output_value_string);
		double delta = stod(delta_string);
		ActivationType type = static_cast<ActivationType>(activation_type);
		return Neuron(input_vector, type, learn_speed, output_value, sum, delta);
	}
};

