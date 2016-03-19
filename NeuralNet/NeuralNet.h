#pragma once
#include <vector>
#include "Neuron.h"
using namespace std;

class NeuralNetwork
{
private:
	vector<Neuron> inputLayer;
	//vector<Neuron> middleLayer;
	vector<Neuron> outputLayer;
public:
	NeuralNetwork()
	{

	}

	~NeuralNetwork()
	{

	}
};