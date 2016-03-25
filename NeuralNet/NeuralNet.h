#pragma once
#include <vector>
#include "Neuron.h"
#include "Image.h"

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

	int output;

	double outputTreshold;

	ActivationType activationType;
	
public:

	NeuralNetwork(int inputNeuronsNumber,int numberOfInputs, int outputNeuronsNumber,ActivationType actType, double learnRatio)
	{
		srand(clock());
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
		activationType = actType;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber , int outputNeuronsNumber, ActivationType actType, double learnRatio)
	{
		srand(clock());

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
		activationType = actType;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber, int hiddenLayer2NeuronsNumber, int outputNeuronsNumber, ActivationType actType, double learnRatio)
	{
		srand(clock());
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
		activationType = actType;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber, int hiddenLayer2NeuronsNumber, int hiddenLayer3NeuronsNumber, int outputNeuronsNumber, ActivationType actType, double learnRatio)
	{
		srand(clock());
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

		for (int i = 0; i < hiddenLayer3NeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < hiddenLayer2NeuronsNumber; j++)
				temp.push_back(Input());

			hiddenLayer3.push_back(Neuron(temp, actType, learnRatio));
		}

		for (int i = 0; i < outputNeuronsNumber; i++)
		{
			vector<Input> temp;
			temp.push_back(Input(1.0));

			for (int j = 0; j < hiddenLayer3NeuronsNumber; j++)
				temp.push_back(Input());

			outputLayer.push_back(Neuron(temp, actType, learnRatio));
		}
		hiddenLayersNumber = 3;
		activationType = actType;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 0;
		//get activation type
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

	int outputToNumber()
	{
		if (outputLayer[0].getOutputValue() >= outputTreshold)
			return 0;
		else if (outputLayer[1].getOutputValue() >= outputTreshold)
			return 1;
		else if (outputLayer[2].getOutputValue() >= outputTreshold)
			return 2;
		else if (outputLayer[3].getOutputValue() >= outputTreshold)
			return 3;
		else if (outputLayer[4].getOutputValue() >= outputTreshold)
			return 4;
		else if (outputLayer[5].getOutputValue() >= outputTreshold)
			return 5;
		else if (outputLayer[6].getOutputValue() >= outputTreshold)
			return 6;
		else if (outputLayer[7].getOutputValue() >= outputTreshold)
			return 7;
		else if (outputLayer[8].getOutputValue() >= outputTreshold)
			return 8;
		else if (outputLayer[9].getOutputValue() >= outputTreshold)
			return 9;
		else
			return -1;
	}

	void work(Image inputImage)
	{
		for (int y = 0; y < inputImage.get_sizey(); y++)
		{
			for (int x = 0; x < inputImage.get_sizex(); x++)
			{
				inputLayer[x + y].setInput(1, inputImage.get_pixel_value(x, y));
			}
		}


		for (int i = 0; i < inputLayer.size(); i++)
		{
			inputLayer[i].work();
		}

		if (hiddenLayersNumber > 0)
		{

		}

		if (hiddenLayersNumber > 1)
		{

		}

		if (hiddenLayersNumber > 2)
		{

		}


	}

	vector<double> numberToOutput(int number)
	{
		vector <double> temp;

		for (int i = 0; i < number; i++)
		{
			if (activationType == ActivationType::unipolarEdge || activationType == ActivationType::unipolarSigmoidal)
				temp.push_back(0.05);
			else
				temp.push_back(-0.95);
		}
		
		temp.push_back(0.95);

		for (int i = 0; i < 9 - number; i++)
		{
			{
				if (activationType == ActivationType::unipolarEdge || activationType == ActivationType::unipolarSigmoidal)
					temp.push_back(0.05);
				else
					temp.push_back(-0.95);
			}
		}
			
		return temp;
	}

	void learnRow(Image inputImage)
	{

	}

};