#include "Image.h"

short Image::get_digit() {
	return this->digit;
}

short Image::get_sizex() {
	return this->sizex;
}

short Image::get_sizey() {
	return this->sizey;
}

vector<vector<uchar>> Image::get_pixels() {
	return this->pixels;
}

uchar Image::get_pixel_value(int x, int y) {
	return this->pixels[x][y];
}

bool Image::is_eqaul(Image img) {
	if (this->digit == img.get_digit() && this->sizex == img.get_sizex() && this->sizey == img.get_sizey()) {
		for (int i = 0; i < sizex; i++) {
			for (int j = 0; j < sizey; j++) {
				if (this->pixels[i][j] != img.get_pixel_value(i, j)) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool operator==(Image image1, Image image2) {
	return image1.is_eqaul(image2);
}