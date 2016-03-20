#pragma once

#include "Image.h"
#include <list>

using namespace std;

class ImageSet
{
private:
	list<Image> image_list;
	int list_count;

public:
	ImageSet() {
		image_list = list<Image>();
		list_count = 0;
	}

	ImageSet(int list_count, Image * image) 
		: list_count(list_count)
	{
		image_list = list<Image>();
		for (int i = 0; i < list_count; i++) {
			image_list.push_back(image[i]);
		}
	}

	ImageSet(const ImageSet &set) {
		this->list_count = set.list_count;
		this->image_list = list<Image>(this->list_count);
		for (auto &image : set.image_list) {
			this->image_list.push_back(image);
		}
	}

	int get_list_count();

	list<Image> get_image_list();

	Image get_image_from_list(int which);

	Image get_last_image_from_list();

	void add_image_to_list(Image img);

	Image remove_last_image_from_list();

	Image remove_image_from_list(int which);
	
	int find_image_in_list(Image image);

};
