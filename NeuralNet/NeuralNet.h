#pragma once
#include <vector>
#include "Neuron.h"
#include "Image.h"

using namespace std;

static double outputTreshold = 0.95;

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

	//double outputTreshold;

	ActivationType activationType;

	long int errors;

public:

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int outputNeuronsNumber, ActivationType actType, double learnRatio)
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
		errors = 0;
	}

	NeuralNetwork(int inputNeuronsNumber, int numberOfInputs, int hiddenLayer1NeuronsNumber, int outputNeuronsNumber, ActivationType actType, double learnRatio)
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
		errors = 0;
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
		errors = 0;
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
		errors = 0;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 0;
		this->inputLayer = inputLayer;
		this->outputLayer = outputLayer;
		errors = 0;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> hiddenLayer1, vector<Neuron> outputLayer)
	{
		hiddenLayersNumber = 1;
		this->inputLayer = inputLayer;
		this->hiddenLayer1 = hiddenLayer1;
		this->outputLayer = outputLayer;
		errors = 0;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> hiddenLayer1, vector<Neuron> hiddenLayer2, vector<Neuron> outputLayer)
	{
		hiddenLayersNumber = 2;
		this->inputLayer = inputLayer;
		this->hiddenLayer1 = hiddenLayer1;
		this->hiddenLayer2 = hiddenLayer2;
		this->outputLayer = outputLayer;
		errors = 0;
	}

	NeuralNetwork(vector<Neuron> inputLayer, vector<Neuron> hiddenLayer1, vector<Neuron> hiddenLayer2, vector<Neuron> hiddenLayer3, vector<Neuron> outputLayer)
	{

		hiddenLayersNumber = 3;
		this->inputLayer = inputLayer;
		this->hiddenLayer1 = hiddenLayer1;
		this->hiddenLayer2 = hiddenLayer2;
		this->hiddenLayer3 = hiddenLayer3;
		this->outputLayer = outputLayer;
		errors = 0;
	}

	~NeuralNetwork()
	{

	}

	int outputToNumber()
	{
		/*
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
			*/

		int index = 0;
		double maxVal = outputLayer[0].getOutputValue();

		for (int i = 1; i < outputLayer.size(); i++)
		{
			if (outputLayer[i].getOutputValue()>maxVal)
			{
				index = i;
				maxVal = outputLayer[i].getOutputValue();
			}
		}

		return index;
	}

	void work(Image inputImage)
	{
		for (int y = 0; y < inputImage.get_sizey(); y++)
		{
			for (int x = 0; x < inputImage.get_sizex(); x++)
			{
				inputLayer[y*inputImage.get_sizex() + x].setInput(1, ((double)inputImage.get_pixel_value(x, y)/(double)255));
			}
		}


		for (int i = 0; i < inputLayer.size(); i++)
		{
			inputLayer[i].work();
		}

		if (hiddenLayersNumber == 0)
		{
			for (int i = 0; i < outputLayer.size(); i++)
			{
				for (int j = 0; j < inputLayer.size(); j++)
				{
					outputLayer[i].setInput(j + 1, inputLayer[j].getOutputValue());
				}
			}

			for (int i = 0; i < outputLayer.size(); i++)
			{
				outputLayer[i].work();
			}

			output = outputToNumber();

		}

		if (hiddenLayersNumber == 1)
		{
			for (int j = 0; j < hiddenLayer1.size(); j++)
			{
				for (int i = 0; i < inputLayer.size(); i++)
				{
					hiddenLayer1[j].setInput(i + 1, inputLayer[i].getOutputValue());
				}
			}

			for (int i = 0; i < hiddenLayer1.size(); i++)
			{
				hiddenLayer1[i].work();
			}


			for (int i = 0; i < outputLayer.size(); i++)
			{
				for (int j = 0; j < hiddenLayer1.size(); j++)
				{
					outputLayer[i].setInput(j + 1, hiddenLayer1[j].getOutputValue());
				}
			}

			for (int i = 0; i < outputLayer.size(); i++)
			{
				outputLayer[i].work();
			}

			output = outputToNumber();

		}



		if (hiddenLayersNumber == 2)
		{
			for (int j = 0; j < hiddenLayer1.size(); j++)
			{
				for (int i = 0; i < inputLayer.size(); i++)
				{
					hiddenLayer1[j].setInput(i + 1, inputLayer[i].getOutputValue());
				}
			}

			for (int i = 0; i < hiddenLayer1.size(); i++)
			{
				hiddenLayer1[i].work();
			}

			for (int j = 0; j < hiddenLayer2.size(); j++)
			{
				for (int i = 0; i < hiddenLayer1.size(); i++)
				{
					hiddenLayer2[j].setInput(i + 1, hiddenLayer1[i].getOutputValue());
				}
			}

			for (int i = 0; i < hiddenLayer2.size(); i++)
			{
				hiddenLayer2[i].work();
			}


			for (int i = 0; i < outputLayer.size(); i++)
			{
				for (int j = 0; j < hiddenLayer2.size(); j++)
				{
					outputLayer[i].setInput(j + 1, hiddenLayer2[j].getOutputValue());
				}
			}

			for (int i = 0; i < outputLayer.size(); i++)
			{
				outputLayer[i].work();
			}

			output = outputToNumber();

		}

		if (hiddenLayersNumber == 3)
		{
			for (int j = 0; j < hiddenLayer1.size(); j++)
			{
				for (int i = 0; i < inputLayer.size(); i++)
				{
					hiddenLayer1[j].setInput(i + 1, inputLayer[i].getOutputValue());
				}
			}

			for (int i = 0; i < hiddenLayer1.size(); i++)
			{
				hiddenLayer1[i].work();
			}

			for (int j = 0; j < hiddenLayer2.size(); j++)
			{
				for (int i = 0; i < hiddenLayer1.size(); i++)
				{
					hiddenLayer2[j].setInput(i + 1, hiddenLayer1[i].getOutputValue());
				}
			}

			for (int i = 0; i < hiddenLayer2.size(); i++)
			{
				hiddenLayer2[i].work();
			}

			for (int j = 0; j < hiddenLayer3.size(); j++)
			{
				for (int i = 0; i < hiddenLayer2.size(); i++)
				{
					hiddenLayer3[j].setInput(i + 1, hiddenLayer2[i].getOutputValue());
				}
			}

			for (int i = 0; i < hiddenLayer3.size(); i++)
			{
				hiddenLayer3[i].work();
			}


			for (int i = 0; i < outputLayer.size(); i++)
			{
				for (int j = 0; j < hiddenLayer3.size(); j++)
				{
					outputLayer[i].setInput(j + 1, hiddenLayer3[j].getOutputValue());
				}
			}

			for (int i = 0; i < outputLayer.size(); i++)
			{
				outputLayer[i].work();
			}

			output = outputToNumber();
		}


	}

	vector<double> numberToOutput(int number)
	{
		vector <double> temp;

		for (int i = 0; i < number; i++)
		{
			if (activationType == ActivationType::unipolarEdge || activationType == ActivationType::unipolarSigmoidal)
				temp.push_back(0.00);
			else
				temp.push_back(-1.0);
		}

		temp.push_back(1.0);

		for (int i = 0; i < 9 - number; i++)
		{
			
				if (activationType == ActivationType::unipolarEdge || activationType == ActivationType::unipolarSigmoidal)
					temp.push_back(0.00);
				else
					temp.push_back(-1.0);

		}

		return temp;
	}

	void learnRow(Image inputImage)
	{
		int expectedResult = inputImage.get_digit();
		vector<double> expectedVector = numberToOutput(expectedResult);

		work(inputImage);

		if (expectedResult != output)
			errors++;


		for (int i = 0; i < outputLayer.size(); i++)
		{
			outputLayer[i].setDelta(expectedVector[i]-outputLayer[i].getOutputValue());
		}


		for (int i = 0; i < hiddenLayer1.size(); i++)
		{
			double sum = 0.0;

			for (int j = 0; j < outputLayer.size(); j++)
			{
				sum += outputLayer[j].getDeltaMulWeight(i + 1);
			}

			hiddenLayer1[i].setDelta(sum);
		}

		for (int i = 0; i < inputLayer.size(); i++)
		{
			double sum = 0.0;

			for (int j = 0; j < hiddenLayer1.size(); j++)
			{
				sum += hiddenLayer1[j].getDeltaMulWeight(i + 1);
			}

			inputLayer[i].setDelta(sum);
		}

		for (int i = 0; i < inputLayer.size(); i++)
		{
			inputLayer[i].updateWeights();
		}

		for (int i = 0; i < hiddenLayer1.size(); i++)
		{
			hiddenLayer1[i].updateWeights();
		}

		for (int i = 0; i < outputLayer.size(); i++)
		{
			outputLayer[i].updateWeights();
		}

	}

	long int getErrors()
	{
		return errors;
	}

	void resetErrors() {
		this->errors = 0;
	}

	void workWithTestSet(Image inputImage) {
		int expectedResult = inputImage.get_digit();
		work(inputImage);
		if (expectedResult != output)
			errors++;
	}

	string toString() {
		string str = "NeuralNetwork\n";
		str += "inputLayer\n";
		str += to_string(inputLayer.size()) + "\n";
		for (int i = 0; i < inputLayer.size(); i++) {
			str += inputLayer[i].toString();
		}
		str += "outputLayer\n";
		str += to_string(outputLayer.size()) + "\n";
		for (int i = 0; i < outputLayer.size(); i++) {
			str += outputLayer[i].toString();
		}
		str += to_string(hiddenLayersNumber) + "\n";
		if (hiddenLayersNumber == 1) {
			str += "hiddenLayer1\n";
			str += to_string(hiddenLayer1.size()) + "\n";
			for (int i = 0; i < hiddenLayer1.size(); i++) {
				str += hiddenLayer1[i].toString();
			}
		}
		else if (hiddenLayersNumber == 2) {
			str += "hiddenLayer1\n";
			str += to_string(hiddenLayer1.size()) + "\n";
			for (int i = 0; i < hiddenLayer1.size(); i++) {
				str += hiddenLayer1[i].toString();
			}
			str += "hiddenLayer2\n";
			str += to_string(hiddenLayer2.size()) + "\n";
			for (int i = 0; i < hiddenLayer2.size(); i++) {
				str += hiddenLayer2[i].toString();
			}
		}
		else {
			str += "hiddenLayer1\n";
			str += to_string(hiddenLayer1.size()) + "\n";
			for (int i = 0; i < hiddenLayer1.size(); i++) {
				str += hiddenLayer1[i].toString();
			}
			str += "hiddenLayer2\n";
			str += to_string(hiddenLayer2.size()) + "\n";
			for (int i = 0; i < hiddenLayer2.size(); i++) {
				str += hiddenLayer2[i].toString();
			}
			str += "hiddenLayer3\n";
			str += to_string(hiddenLayer3.size()) + "\n";
			for (int i = 0; i < hiddenLayer3.size(); i++) {
				str += hiddenLayer3[i].toString();
			}

		}
		return str;
	}

	static NeuralNetwork fromString(string str) {
		int index = str.find("inputLayer\n") + 11;
		int input_layer_size = stoi(str.substr(index, str.find("\n", index)));
		index = str.find("\n", index);
		str = str.substr(index+1, str.length());
		vector<Neuron> input_layer;
		for (int i = 0; i < input_layer_size; i++) {
			Neuron n = Neuron::fromString(str);
			input_layer.push_back(n);
		}
		index = str.find("outputLayer\n") + 12;
		int output_layer_size = stoi(str.substr(index, str.find("\n", index)));
		index = str.find("\n", index);
		str = str.substr(index + 1, str.length());
		vector<Neuron> output_layer;
		for (int i = 0; i < output_layer_size; i++) {
			Neuron n = Neuron::fromString(str);
			output_layer.push_back(n);
		}
		int hidden_layers_number = stoi(str.substr(0, str.find("\n")));
		if (hidden_layers_number == 1) {
			index = str.find("hiddenLayer1\n") + 13;
			int hidden_layer_1_size = stoi(str.substr(index, str.find("\n", index)));
			index = str.find("\n", index);
			str = str.substr(index + 1, str.length());
			vector<Neuron> hidden_layer_1;
			for (int i = 0; i < hidden_layer_1_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_1.push_back(n);
			}
			return NeuralNetwork(input_layer, hidden_layer_1, output_layer);
		}
		else if (hidden_layers_number == 2) {
			index = str.find("hiddenLayer1\n") + 13;
			int hidden_layer_1_size = stoi(str.substr(index, str.find("\n", index)));
			index = str.find("\n", index);
			str = str.substr(index + 1, str.length());
			vector<Neuron> hidden_layer_1;
			for (int i = 0; i < hidden_layer_1_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_1.push_back(n);
			}
			index = str.find("hiddenLayer2\n") + 13;
			int hidden_layer_2_size = stoi(str.substr(index, str.find("\n", index)));
			index = str.find("\n", index);
			str = str.substr(index + 1, str.length());
			vector<Neuron> hidden_layer_2;
			for (int i = 0; i < hidden_layer_2_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_2.push_back(n);
			}
			return NeuralNetwork(input_layer, hidden_layer_1, hidden_layer_2, output_layer);
		}
		else {
			index = str.find("hiddenLayer1\n") + 13;
			int hidden_layer_1_size = stoi(str.substr(index, str.find("\n", index)));
			index = str.find("\n", index);
			str = str.substr(index + 1, str.length());
			vector<Neuron> hidden_layer_1;
			for (int i = 0; i < hidden_layer_1_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_1.push_back(n);
			}
			index = str.find("hiddenLayer2\n") + 13;
			int hidden_layer_2_size = stoi(str.substr(index, str.find("\n", index)));
			index = str.find("\n", index);
			str = str.substr(index + 1, str.length());
			vector<Neuron> hidden_layer_2;
			for (int i = 0; i < hidden_layer_2_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_2.push_back(n);
			}
			index = str.find("hiddenLayer3\n") + 13;
			int hidden_layer_3_size = stoi(str.substr(index, str.find("\n", index)));
			index = str.find("\n", index);
			str = str.substr(index + 1, str.length());
			vector<Neuron> hidden_layer_3;
			for (int i = 0; i < hidden_layer_3_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_3.push_back(n);
			}
			return NeuralNetwork(input_layer, hidden_layer_1, hidden_layer_2, output_layer);
		}

	}

};