#include"ImageSet.h"

int ImageSet::get_list_count() {
	return this->list_count;
}

list<Image> ImageSet::get_image_list() {
	return this->image_list;
}

Image ImageSet::get_image_from_list(int which) {
	int i = 0;
	for (auto &img : image_list) {
		if (i == which) {
			return img;
		}
		i++;
	}
	return Image();
}

Image ImageSet::get_last_image_from_list() {
	return this->image_list.back();
}

void ImageSet::add_image_to_list(Image img) {
	this->image_list.push_back(img);
	this->list_count++;
}

Image ImageSet::remove_last_image_from_list() {
	Image img = this->image_list.back();
	this->image_list.pop_back();
	return img;
}

Image ImageSet::remove_image_from_list(int which) {
	int i = 0;
	Image image;
	list<Image>::iterator it = image_list.begin();;
	for (auto &img : image_list) {
		if (i == which) {
			image = img;
			image_list.erase(it);
		}
		it++;
		i++;
	}
	return image;
}

int ImageSet::find_image_in_list(Image image) {
	int i = 0;
	for (auto &img : image_list) {
		if (img == image) {
			return i;
		}
		i++;
	}
	return 0;
}