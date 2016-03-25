#include <iostream>
#include "ImageSet.h"
#include "FileReader.h"
#include "NeuralNet.h"
#include "ActivationTypes.h"
#include <Windows.h>
#include <string>

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

int main() {
	MINSTFileReader reader = MINSTFileReader();
	try {
		reader.read_mnist_labels();
		reader.read_mnist_images();
	} catch(runtime_error e){
		cout << e.what() << endl;
	}
	ImageSet set = reader.get_images(10);
	//for (int i = 0; i < 20; i++) {
	//	string name = "Wynik" + to_string(i);
	//	name += ".bmp";
	//	SaveBMP(reader.get_buffer(i), 28, 28, 0, convertCharArrayToLPCWSTR(name.c_str()));
	//}

	NeuralNetwork siec(784, 1, 89, 10, ActivationType::unipolarSigmoidal, 0.7);

	siec.work(set.get_image_from_list(1));

	cout << "test" << endl;
	system("pause");
	return 0;
}