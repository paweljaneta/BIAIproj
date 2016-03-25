#pragma once
#include <vector>
#include "Neuron.h"
using namespace std;

class NeuralNetwork
{
private:
	
	vector<Neuron> inputLayer;
	vector<Neuron> outputLayer;

	vector<Neuron> hiddenLayer1;
	vector<Neuron> hiddenLayer2;
	vector<Neuron> hiddenLayer3;

	int hiddenLayersNumber;
	
public:

	NeuralNetwork(int inputNeuronsNumber,int numberOfInputs, int outputNeuronsNumber,ActivationType actType, double learnRatio)
	{
		for (int i = 0; i < inputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < numberOfInputs; j++)
				temp.push_back(Input());

			inputLayer.push_back(Neuron(temp, actType, learnRatio));
		}
		for (int i = 0; i < outputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < inputNeuronsNumber; j++)
				temp.push_back(Input());

			outputLayer.push_back(Neuron(temp, actType, learnRatio));
		}
		hiddenLayersNumber = 0;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber , int outputNeuronsNumber, ActivationType actType, double learnRatio)
	{
		for (int i = 0; i < inputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < numberOfInputs; j++)
				temp.push_back(Input());

			inputLayer.push_back(Neuron(temp, actType, learnRatio));
		}

		for (int i = 0; i < hiddenLayer1NeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < inputNeuronsNumber; j++)
				temp.push_back(Input());

			hiddenLayer1.push_back(Neuron(temp, actType, learnRatio));
		}

		for (int i = 0; i < outputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < hiddenLayer1NeuronsNumber; j++)
				temp.push_back(Input());

			outputLayer.push_back(Neuron(temp, actType, learnRatio));
		}
		hiddenLayersNumber = 1;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber, int hiddenLayer2NeuronsNumber, int outputNeuronsNumber, ActivationType actType, double learnRatio)
	{
		for (int i = 0; i < inputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < numberOfInputs; j++)
				temp.push_back(Input());

			inputLayer.push_back(Neuron(temp, actType, learnRatio));
		}

		for (int i = 0; i < hiddenLayer1NeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < inputNeuronsNumber; j++)
				temp.push_back(Input());

			hiddenLayer1.push_back(Neuron(temp, actType, learnRatio));
		}

		for (int i = 0; i < hiddenLayer2NeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < hiddenLayer1NeuronsNumber; j++)
				temp.push_back(Input());

			hiddenLayer2.push_back(Neuron(temp, actType, learnRatio));
		}

		for (int i = 0; i < outputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < hiddenLayer2NeuronsNumber; j++)
				temp.push_back(Input());

			outputLayer.push_back(Neuron(temp, actType, learnRatio));
		}

		hiddenLayersNumber = 2;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber, int hiddenLayer2NeuronsNumber, int hiddenLayer3NeuronsNumber, int outputNeuronsNumber, ActivationType actType, double learnRatio)
	{

		hiddenLayersNumber = 3;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 0;
	}

	NeuralNetwork(vector<Neuron> inputLayer,vector<Neuron> hiddenLayer1 , vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 1;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> hiddenLayer1, vector<Neuron> hiddenLayer2, vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 2;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> hiddenLayer1, vector<Neuron> hiddenLayer2, vector<Neuron> hiddenLayer3, vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 3;
	}

	~NeuralNetwork()
	{

	}

	void work()
	{

	}

	void learnRow()
	{

	}

};