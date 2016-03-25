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

	string toString() {
		string str = "NeuralNetwork\n";
		str += "inputLayer\n";
		str += to_string(inputLayer.size()) + "\n";
		for (int i = 0; i < inputLayer.size(); i++) {
			str += inputLayer[i].toString();
		}
		str += "outputLayer\n";
		str += to_string(outputLayer.size())+ "\n";
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
		int index = str.find_first_of("inputLayer\n") + 12;
		int input_layer_size = stoi(str.substr(index, str.find_first_of("\n", index)));
		str = str.substr(str.find_first_of("\n"), str.length());
		vector<Neuron> input_layer;
		for (int i = 0; i < input_layer_size; i++) {
			Neuron n = Neuron::fromString(str);
			input_layer.push_back(n);
		}
		index = str.find_first_of("outputLayer\n") + 13;
		int output_layer_size = stoi(str.substr(index, str.find_first_of("\n", index)));
		str = str.substr(str.find_first_of("\n"), str.length());
		vector<Neuron> output_layer;
		for (int i = 0; i < output_layer_size; i++) {
			Neuron n = Neuron::fromString(str);
			output_layer.push_back(n);
		}
		int hidden_layers_number = stoi(str.substr(0, str.find_first_of("\n")));
		if (hidden_layers_number == 1) {
			index = str.find_first_of("hiddenLayer1\n") + 14;
			int hidden_layer_1_size = stoi(str.substr(index, str.find_first_of("\n", index)));
			str = str.substr(str.find_first_of("\n"), str.length());
			vector<Neuron> hidden_layer_1;
			for (int i = 0; i < hidden_layer_1_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_1.push_back(n);
			}
			return NeuralNetwork(input_layer, hidden_layer_1, output_layer);
		}
		else if (hidden_layers_number == 2) {
			index = str.find_first_of("hiddenLayer1\n") + 14;
			int hidden_layer_1_size = stoi(str.substr(index, str.find_first_of("\n", index)));
			str = str.substr(str.find_first_of("\n"), str.length());
			vector<Neuron> hidden_layer_1;
			for (int i = 0; i < hidden_layer_1_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_1.push_back(n);
			}
			index = str.find_first_of("hiddenLayer2\n") + 14;
			int hidden_layer_2_size = stoi(str.substr(index, str.find_first_of("\n", index)));
			str = str.substr(str.find_first_of("\n"), str.length());
			vector<Neuron> hidden_layer_2;
			for (int i = 0; i < hidden_layer_2_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_2.push_back(n);
			}
			return NeuralNetwork(input_layer, hidden_layer_1,hidden_layer_2, output_layer);
		}
		else {
			index = str.find_first_of("hiddenLayer1\n") + 14;
			int hidden_layer_1_size = stoi(str.substr(index, str.find_first_of("\n", index)));
			str = str.substr(str.find_first_of("\n"), str.length());
			vector<Neuron> hidden_layer_1;
			for (int i = 0; i < hidden_layer_1_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_1.push_back(n);
			}
			index = str.find_first_of("hiddenLayer2\n") + 14;
			int hidden_layer_2_size = stoi(str.substr(index, str.find_first_of("\n", index)));
			str = str.substr(str.find_first_of("\n"), str.length());
			vector<Neuron> hidden_layer_2;
			for (int i = 0; i < hidden_layer_2_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_2.push_back(n);
			}
			index = str.find_first_of("hiddenLayer3\n") + 14;
			int hidden_layer_3_size = stoi(str.substr(index, str.find_first_of("\n", index)));
			str = str.substr(str.find_first_of("\n"), str.length());
			vector<Neuron> hidden_layer_3;
			for (int i = 0; i < hidden_layer_3_size; i++) {
				Neuron n = Neuron::fromString(str);
				hidden_layer_3.push_back(n);
			}
			return NeuralNetwork(input_layer, hidden_layer_1, hidden_layer_2, output_layer);
		}
		
	}

};