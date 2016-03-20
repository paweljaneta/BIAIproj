#pragma once
#include <vector>
#include <String.h>
using namespace std;

typedef unsigned char uchar;

class Image 
{
private:
	int sizex, sizey;
	vector<vector<uchar>> pixels;
	uchar digit;
public:

	Image() {
		sizex = sizey = 0;
		digit = 0;
	}

	Image(int sizex, int sizey, uchar digit, vector<vector<uchar>> pixels) 
		: sizex(sizex), sizey(sizey), digit(digit)
	{
		this->pixels = vector<vector<uchar>>();
		for (int i = 0; i < this->get_sizex(); i++) {
			vector<uchar> data;
			for (int j = 0; j < this->get_sizey(); j++) {
				data.push_back(pixels[i][j]);
			}
			this->pixels.push_back(data);
		}
	}

	Image(const Image &img) {
		this->digit = img.digit;
		this->sizex = img.sizex;
		this->sizey = img.sizey;
		this->pixels = vector<vector<uchar>>();
		for (int i = 0; i < this->get_sizex(); i++) {
			vector<uchar> data;
			for (int j = 0; j < this->get_sizey(); j++) {
				data.push_back(img.pixels[i][j]);
			}
			this->pixels.push_back(data);
		}
	}

	short get_digit();

	short get_sizex();

	short get_sizey();

	vector<vector<uchar>> get_pixels();

	uchar get_pixel_value(int x, int y);

	bool is_eqaul(Image img);

};

bool operator==(Image image1, Image image2);