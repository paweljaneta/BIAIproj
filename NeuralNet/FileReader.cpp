#include <fstream>
#include <iostream>
#include <string>
#include "FileReader.h"

using namespace std;

void MINSTFileReader::read_mnist_images()
{
	auto reverseInt = [](int i) {
		unsigned char c1, c2, c3, c4;
		c1 = i & 255, c2 = (i >> 8) & 255, c3 = (i >> 16) & 255, c4 = (i >> 24) & 255;
		return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
	};

	ifstream file(this->images_file_path);

	if (file.is_open()) {
		int magic_number = 0;

		file.read((char *)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);

		if (magic_number != 2051) throw runtime_error("Invalid MNIST image file!");

		file.read((char *)&this->images_count, sizeof(this->images_count)), this->images_count = reverseInt(this->images_count);
		file.read((char *)&this->sizey, sizeof(this->sizey)), this->sizey = reverseInt(this->sizey);
		file.read((char *)&this->sizex, sizeof(this->sizex)), this->sizex = reverseInt(this->sizex);

		this->image_size = this->sizex * this->sizey;

		this->images_data = new uchar*[this->images_count];
		for (int i = 0; i < this->images_count; i++) {
			this->images_data[i] = new uchar[this->image_size];
			file.read((char *)this->images_data[i], this->image_size);
		}
	}
	else {
		throw runtime_error("Cannot open file `" + this->images_file_path + "`!");
	}
}

void MINSTFileReader::read_mnist_labels()
{
	auto reverseInt = [](int i) {
		unsigned char c1, c2, c3, c4;
		c1 = i & 255, c2 = (i >> 8) & 255, c3 = (i >> 16) & 255, c4 = (i >> 24) & 255;
		return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
	};

	typedef unsigned char uchar;

	ifstream file(this->labels_file_path);

	if (file.is_open()) {
		int magic_number = 0;
		file.read((char *)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);

		if (magic_number != 2049) throw runtime_error("Invalid MNIST label file!");

		file.read((char *)&this->labels_count, sizeof(this->labels_count)), this->labels_count = reverseInt(this->labels_count);

		this->labels = new uchar[this->labels_count];
		for (int i = 0; i < this->labels_count; i++) {
			file.read((char*)&this->labels[i], 1);
		}
	}
	else {
		throw runtime_error("Cannot open file `" + this->labels_file_path + "`!");
	}
}

ImageSet MINSTFileReader::get_images(int ogranicznik) {
	if (ogranicznik != 0) {
		this->images_count = ogranicznik;
	}
	Image * images = new Image[this->images_count];
	for (int i = 0; i < this->images_count; i++) {
		vector<vector<uchar>> data;
		for (int j = 0; j < this->sizex; j++) {
			vector<uchar> temporary;
			for (int k = 0; k < this->sizey; k++) {
				temporary.push_back(this->images_data[i][j*this->sizex + k]);
			}
			data.push_back(temporary);
		}
		images[i] = Image(this->sizex, this->sizey, this->labels[i], data);
	}
	return ImageSet(this->images_count, images);
}