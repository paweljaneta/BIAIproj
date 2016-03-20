#include <iostream>
#include "FileReader.h"

using namespace std;

typedef unsigned char uchar;

int main() {
	MINSTFileReader reader = MINSTFileReader();
	try {
		reader.read_mnist_labels();
		reader.read_mnist_images();
	} catch(exception e){
		cout << e.what() << endl;
	}
	ImageSet set = reader.get_images(1000);
	cout << "test" <<endl;
	system("pause");
	return 0;
}