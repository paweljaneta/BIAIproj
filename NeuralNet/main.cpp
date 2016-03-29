#include <iostream>
#include "ImageSet.h"
#include "NeuralNet.h"
#include "FileReader.h"

#include "ActivationTypes.h"
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

typedef unsigned char uchar;

LPCWSTR convertCharArrayToLPCWSTR(const char* charArray) {
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}


bool SaveBMP(uchar * buffer, int width, int height, long paddedsize, LPCTSTR bmpfile)
{
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapFileInfo;
	memset(&bitmapFileHeader, 0, sizeof(BITMAPFILEHEADER));
	memset(&bitmapFileInfo, 0, sizeof(BITMAPINFOHEADER));
	bitmapFileHeader.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bitmapFileHeader.bfReserved1 = 0;
	bitmapFileHeader.bfReserved2 = 0;
	bitmapFileHeader.bfSize = sizeof(BITMAPFILEHEADER) +
		sizeof(BITMAPINFOHEADER) + paddedsize;
	bitmapFileHeader.bfOffBits = 0x36;
	bitmapFileInfo.biSize = sizeof(BITMAPINFOHEADER);
	bitmapFileInfo.biWidth = width;
	bitmapFileInfo.biHeight = height;
	bitmapFileInfo.biPlanes = 1;
	bitmapFileInfo.biBitCount = 24;
	bitmapFileInfo.biCompression = BI_RGB;
	bitmapFileInfo.biSizeImage = 0;
	bitmapFileInfo.biXPelsPerMeter = 0x0ec4;
	bitmapFileInfo.biYPelsPerMeter = 0x0ec4;
	bitmapFileInfo.biClrUsed = 0;
	bitmapFileInfo.biClrImportant = 0;
	HANDLE file = CreateFile(bmpfile, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!file)
	{
		CloseHandle(file);
		return false;
	}
	unsigned long bwritten;
	if (WriteFile(file, &bitmapFileHeader, sizeof(BITMAPFILEHEADER),
		&bwritten, NULL) == false)
	{
		CloseHandle(file);
		return false;
	}

	if (WriteFile(file, &bitmapFileInfo, sizeof(BITMAPINFOHEADER),
		&bwritten, NULL) == false)
	{
		CloseHandle(file);
		return false;
	}
	for (int i = bitmapFileInfo.biHeight - 1; i >= 0; i--) {
		for (int j = 0; j < bitmapFileInfo.biWidth; j++)
		{
			int index = i*bitmapFileInfo.biWidth + j;
			WriteFile(file, &buffer[index], 1, &bwritten, NULL);
			WriteFile(file, &buffer[index], 1, &bwritten, NULL);
			WriteFile(file, &buffer[index], 1, &bwritten, NULL);
		} //dla szerokosci niepodzielnej przez 4 trzeba dopelniæ zapis czarnym
		for (int i = 0; i < width % 4; i++)
		{
			unsigned char buf = 0;
			WriteFile(file, &buf, 1, &bwritten, NULL);
		}
	}
	CloseHandle(file);
	return true;
}

int getRandom(int *hVector, int listCount, int currentRepeat);


int main() {
	MINSTFileReader reader = MINSTFileReader();
	try {
		reader.read_mnist_labels();
		reader.read_mnist_images();
	}
	catch (runtime_error e) {
		cout << e.what() << endl;
	}
	ImageSet set = reader.get_images(60000);

	int hashVector[60000];

	for (int i = 0; i < set.get_list_count(); i++)
	{
		hashVector[i] = 0;
	}

	//for (int i = 0; i < 20; i++) {
	//	string name = "Wynik" + to_string(i);
	//	name += ".bmp";
	//	SaveBMP(reader.get_buffer(i), 28, 28, 0, convertCharArrayToLPCWSTR(name.c_str()));
	//}

	cout << "Set read" << endl;

	fstream file1, file2, file3;

	//file1.open("356_decreasing_learn_speed_2x_neurons.txt", ios::out);
	//file2.open("267_decreasing_learn_speed_neurons.txt",ios::out);
	file3.open("356_decreasing_learn_speed_2x_random_neurons.txt", ios::out);

	//NeuralNetwork siec(784, 1, 89, 10, ActivationType::unipolarSigmoidal, 0.2);

	//NeuralNetwork siec1(784, 1, 178, 10, ActivationType::unipolarSigmoidal, 0.7);
	//NeuralNetwork siec2(784, 1, 267, 10, ActivationType::unipolarSigmoidal, 0.7);
	NeuralNetwork siec3(784, 1, 356, 10, ActivationType::unipolarSigmoidal, 0.7);

	long int previousErrors = 0;

	//for (int i = 0; i < set.get_list_count(); i++)
	//{
	//	siec.learnRow(set.get_image_from_list(i));

	//	if ((i % 100) == 0)
	//	{
	//		cout << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec.getErrors()-previousErrors)*100.0 / 100.0<<" %" << endl;
	//		previousErrors = siec.getErrors();
	//	}

	//}
	/*
	for (int i = 0; i < set.get_list_count(); i++)
	{
		siec1.learnRow(set.get_image_from_list(i));

		if ((i % 100) == 0)
		{
			cout << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec1.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec1.getErrors()-previousErrors)*100.0 / 100.0<<" %" << endl;
			file1<< (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec1.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec1.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			previousErrors = siec1.getErrors();
		}

	}

	for (int i = 0; i < set.get_list_count(); i++)
	{
		siec2.learnRow(set.get_image_from_list(i));

		if ((i % 100) == 0)
		{
			cout << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec2.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec2.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			file2 << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec2.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec2.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			previousErrors = siec2.getErrors();
		}

	}
	*/
	for (int i = 0; i < set.get_list_count(); i++)
	{
		siec3.learnRow(set.get_image_from_list(getRandom(hashVector, set.get_list_count(), 0)));

		if ((i % 100) == 0)
		{
			cout << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec3.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec3.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			file3 << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec3.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec3.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			previousErrors = siec3.getErrors();
		}

	}

	for (int i = 0; i < set.get_list_count(); i++)
	{
		siec3.learnRow(set.get_image_from_list(getRandom(hashVector, set.get_list_count(), 1)));

		if ((i % 100) == 0)
		{
			cout << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec3.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec3.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			file3 << (double)i*100.0 / (double)set.get_list_count() << " %		e: " << (double)siec3.getErrors()*100.0 / (double)(i + 1) << " %		ce: " << (double)(siec3.getErrors() - previousErrors)*100.0 / 100.0 << " %" << endl;
			previousErrors = siec3.getErrors();
		}

	}

	//reader.write_neural_network_to_file(siec);
	//siec = reader.read_neural_network_from_file();

	//file1.close();
	//file2.close();
	file3.close();

	cout << "test" << endl;
	system("pause");
	return 0;

}

int getRandom(int *hVector, int listCount, int currentRepeat)
{
	int result;
	int multiplier;

	multiplier = rand() % 11 ;

	result = (rand()%600+1) *multiplier;

	result = result % listCount;

	while (hVector[result] != currentRepeat)
	{
		multiplier = rand() % 11;
		result = (rand() % 600+1) *multiplier;
		result = result % listCount;
	}

	hVector[result]++;

	return result;
}