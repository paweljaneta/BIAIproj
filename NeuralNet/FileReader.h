#include <fstream>
#include <uchar.h>
#include <iostream>
#include <Windows.h>
#include "ImageSet.h"
#include "NeuralNet.h"

typedef unsigned char uchar;

using namespace std;

class MINSTFileReader 
{
private:
	uchar** images_data;
	int images_count;
	int image_size;
	int sizex, sizey;
	string images_file_path;

	uchar* labels;
	int labels_count;
	string labels_file_path;

public:

	MINSTFileReader() {
		WCHAR buffer[255];
		GetCurrentDirectory(255, buffer);
		wstring ws(buffer);
		string path(ws.begin(), ws.end());
		images_file_path = path + "\\resources\\train-images.idx3-ubyte";
		labels_file_path = path + "\\resources\\train-labels.idx1-ubyte";
	}

	MINSTFileReader(string labels_file_relative_path, string images_file_realtive_path) {
		WCHAR buffer[255];
		GetCurrentDirectory(255, buffer);
		wstring ws(buffer);
		string path(ws.begin(), ws.end());
		images_file_path = path + images_file_realtive_path;
		labels_file_path = path + labels_file_relative_path;
	}

	void read_mnist_images();

	void read_mnist_labels();

	//mo¿na se rêcznie ograniczyæ set
	ImageSet get_images(int ogranicznik = 0);

	uchar * get_buffer(int i) {
		return this->images_data[i];
	}

	void write_neural_network_to_file(NeuralNetwork neural_network);

	NeuralNetwork read_neural_network_from_file();
};
