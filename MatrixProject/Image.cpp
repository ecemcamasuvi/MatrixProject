#include "pch.h"
#include "Image.h"
#include <string>
#include<iostream>
#include<fstream>

template<typename rgb>
Image<rgb>::Image()
{
	this->redVal = new Matrix<int>(255, 255, 0);
	this->greenVal = new Matrix<int>(255, 255, 0);
	this->blueVal = new Matrix<int>(255, 255, 0);
}

template<typename rgb>
Image<rgb>::Image(int width, int height)
{
	this->redVal = new Matrix<int>(height, width, 0);
	this->greenVal = new Matrix<int>(height, width, 0);
	this->blueVal = new Matrix<int>(height, width, 0);
}

template<typename rgb>
void Image<rgb>::readFromFile(std::string fileName, std::string fileFormat)
{
	if (fileFormat._Equal("bmp")) {
		std::ifstream readFile(fileName, std::ios::binary | std::ios::in);
		if (!readFile) {
			std::cout << "Cannot open file!\n";
		}
		else {
			char* info = new char[54];
			readFile.seekg(0, std::ios::beg);//konumlandýrma
			readFile.read(info, 54);// read the 54-byte header
			int width = *(int*)&info[18];// extract image height and width from header
			int height = *(int*)&info[22];
			/*this->image->setRow(height);
			this->image->setColumn(width);*/
			int size = 3 * width * height;//her pixel red green blue
			readFile.seekg(54, std::ios::beg);//header'ý atlayarak konumlandýr
			char* data = new char[size];
			readFile.read(data, size);// read the rest of the data at once
			readFile.close();
			this->redVal = new Matrix<int>(height, width, 0);
			this->greenVal = new Matrix<int>(height, width, 0);
			this->blueVal = new Matrix<int>(height, width, 0);
			int k = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					this->redVal->matrix[i][j] = *(int*)&data[k];
					this->greenVal->matrix[i][j] = *(int*)&data[k + 1];
					this->blueVal->matrix[i][j] = *(int*)&data[k + 2];
					k += 3;
				}
			}
			//this->image->setColumn(this->image->getColumn() / 3);

		}
	}
	else if (fileFormat._Equal("bin")) { //OLMADIII
		std::ifstream readFile(fileName, std::ios::binary | std::ios::in);
		if (!readFile) {
			std::cout << "Cannot open file!\n";
		}
		else {
			char* info = new char[2];
			readFile.seekg(0, std::ios::beg);
			readFile.read(info, 2);
			int height = *(int*)&info[0];
			int width = *(int*)&info[1];
			int size = 3 * width * height;
			readFile.seekg(2, std::ios::beg);
			char* data = new char[size];
			readFile.read(data, size);// read the rest of the data at once
			readFile.close();
			this->redVal = new Matrix<int>(height, width, 0);
			this->greenVal = new Matrix<int>(height, width, 0);
			this->blueVal = new Matrix<int>(height, width, 0);
			int k = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					this->redVal->matrix[i][j] = *(int*)&data[k];
					this->greenVal->matrix[i][j] = *(int*)&data[k + 1];
					this->blueVal->matrix[i][j] = *(int*)&data[k + 2];
					k += 3;
				}
			}
			//this->image->setColumn(this->image->getColumn() / 3);
		}
	}
}

template<typename rgb>
Image<rgb>::Image(std::string fileName, std::string fileFormat)
{
	readFromFile(fileName, fileFormat);
}

template<typename rgb>
Image<rgb>::~Image()
{
}

template<typename rgb>
void Image<rgb>::imread(std::string fileName, std::string fileFormat)
{
	readFromFile(fileName, fileFormat);
}

template<typename rgb>
void Image<rgb>::imwrite(std::string fileName, std::string fileFormat)
{
	if (fileFormat._Equal("bmp")) {
		FILE* f;
		unsigned char* img = NULL;
		int w = this->redVal->getColumn(); //1 rgb =3byte
		int h = this->redVal->getRow();
		int filesize = 54 + 3 * w * h;  //w is your image width, h is image height, both int
		int lenght = 3 * w * h;
		img = (unsigned char*)malloc(lenght);
		memset(img, 0, lenght);
		int k = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				img[k] = this->redVal->matrix[i][j];
				img[k + 1] = this->greenVal->matrix[i][j];
				img[k + 2] = this->blueVal->matrix[i][j];
				k += 3;
			}
		}
		unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
		unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
		unsigned char bmppad[3] = { 0,0,0 };
		bmpfileheader[2] = (unsigned char)(filesize);
		bmpfileheader[3] = (unsigned char)(filesize >> 8);
		bmpfileheader[4] = (unsigned char)(filesize >> 16);
		bmpfileheader[5] = (unsigned char)(filesize >> 24);
		bmpinfoheader[4] = (unsigned char)(w);
		bmpinfoheader[5] = (unsigned char)(w >> 8);
		bmpinfoheader[6] = (unsigned char)(w >> 16);
		bmpinfoheader[7] = (unsigned char)(w >> 24);
		bmpinfoheader[8] = (unsigned char)(h);
		bmpinfoheader[9] = (unsigned char)(h >> 8);
		bmpinfoheader[10] = (unsigned char)(h >> 16);
		bmpinfoheader[11] = (unsigned char)(h >> 24);
		int n = fileName.length();
		char* c = new char[(n + 1)];
		strcpy(c, fileName.c_str());
		f = fopen(c, "wb");
		fwrite(bmpfileheader, 1, 14, f);
		fwrite(bmpinfoheader, 1, 40, f);
		fwrite(img, 1, filesize - 54, f);

		//free(img);
		fclose(f);
	}
	else if (fileFormat._Equal("bin")) {
		FILE* f;
		unsigned char* img = NULL;
		int w = this->redVal->getColumn(); //1 rgb =3byte
		int h = this->redVal->getRow();
		int filesize = 2 + 3 * w * h;  //w is your image width, h is image height, both int
		img = (unsigned char*)malloc(3 * w * h);
		memset(img, 0, 3 * w * h);
		int k = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				img[k] = this->redVal->matrix[i][j];
				img[k + 1] = this->greenVal->matrix[i][j];
				img[k + 2] = this->blueVal->matrix[i][j];
				k += 3;
			}
		}
		unsigned char bmpfileheader[2] = { w,h };
		int n = fileName.length();
		char* c = new char[(n + 1)];
		strcpy(c, fileName.c_str());
		f = fopen(c, "wb");
		fwrite(bmpfileheader, 1, 2, f);
		fwrite(img, 1, filesize - 2, f);
		fclose(f);
	}
}

template<typename rgb>
void Image<rgb>::color2gray()
{
	int width = this->redVal->getColumn();
	int height = this->redVal->getRow();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int illuminate = this->greenVal->matrix[i][j] / 3;//r=b=0 
			this->redVal->matrix[i][j] = illuminate;
			this->greenVal->matrix[i][j] = illuminate;
			this->blueVal->matrix[i][j] = illuminate;
		}
	}
	this->isGray = true;
}

template<typename rgb>
void Image<rgb>::gray2binary(int thr)
{
	if (this->isGray == true) {
		int width = this->redVal->getColumn();
		int height = this->redVal->getRow();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (this->redVal->matrix[i][j] > thr) {
					this->redVal->matrix[i][j] = 255;//white
				}
				else {
					this->redVal->matrix[i][j] = 0;//black
				}
				if (this->greenVal->matrix[i][j] > thr) {
					this->greenVal->matrix[i][j] = 255;//white
				}
				else {
					this->greenVal->matrix[i][j] = 0;//black
				}
				if (this->blueVal->matrix[i][j] > thr) {
					this->blueVal->matrix[i][j] = 255;//white
				}
				else {
					this->blueVal->matrix[i][j] = 0;//black
				}
			}
		}
		this->isBinary = true;
	}
	else {
		std::cout << "\nGörüntü gri olmadýðýndan binary deðere çevrilemiyor.";
	}
}

template<typename rgb>
void Image<rgb>::erosion()//siyah kýsýmlarý daralt
{
	if (this->isBinary == true) {
		int width = this->redVal->getColumn();
		int height = this->redVal->getRow();
		for (int i = 1; i < height; i++)
		{
			for (int j = 3; j + 2 < width; j += 3)
			{
				if (this->redVal->matrix[i][j] == 255) {//siyah kýsýmlarý daralt
					this->redVal->matrix[i - 1][j - 1] = 255;
				}
				if (this->greenVal->matrix[i][j] == 255) {//siyah kýsýmlarý daralt
					this->greenVal->matrix[i - 1][j - 1] = 255;
				}
				if (this->blueVal->matrix[i][j] == 255) {//siyah kýsýmlarý daralt
					this->blueVal->matrix[i - 1][j - 1] = 255;
				}

			}
		}
	}
	else {
		std::cout << "\nGörüntü binary olmadýðýndan görüntü üzerinde morfolojik bir iþlem gerçekleþtirilemiyor.";
	}
}

template<typename rgb>
void Image<rgb>::dilation()
{
	if (this->isBinary == true) {
		int width = this->redVal->getColumn();
		int height = this->redVal->getRow();
		for (int i = 1; i < height; i++)
		{
			for (int j = 3; j + 2 < width; j += 3)
			{
				if (this->redVal->matrix[i][j] == 0) {//siyah kýsýmlarý geniþlet
					this->redVal->matrix[i - 1][j - 1] = 0;
				}
				if (this->greenVal->matrix[i][j] == 255) {//siyah kýsýmlarý geniþlet
					this->greenVal->matrix[i - 1][j - 1] = 0;
				}
				if (this->blueVal->matrix[i][j] == 255) {//siyah kýsýmlarý geniþlet
					this->blueVal->matrix[i - 1][j - 1] = 0;
				}
			}
		}
	}
	else {
		std::cout << "\nGörüntü binary olmadýðýndan görüntü üzerinde morfolojik bir iþlem gerçekleþtirilemiyor.";
	}
}

template<typename rgb>
void Image<rgb>::opening()
{
	this->erosion();
	this->dilation();
}

template<typename rgb>
void Image<rgb>::closing()
{
	this->dilation();
	this->erosion();
}

