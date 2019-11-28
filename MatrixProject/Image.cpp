#include "Image.h"
#include <string>
#include<iostream>
#include<fstream>

template<int red, int green, int blue>
Image<red, green, blue>::Image()
{
	this->image = new Matrix<int>(255, 255, 0);
}

template<int red, int green, int blue>
Image<red, green, blue>::Image(int width, int height)
{
	this->image = new Matrix<int>(height, width, 0);
	this->image->print();
}

template<int red, int green, int blue>
void Image<red, green, blue>::readFromFile(std::string fileName, std::string fileFormat)
{
	if (fileFormat._Equal("bmp")) {
		std::ifstream readFile(fileName, std::ios::binary | std::ios::in);
		if (!readFile) {
			std::cout << "Cannot open file!\n";
		}
		else {
			char* info = new char[54];
			readFile.seekg(0, std::ios::beg);
			readFile.read(info, 54);// read the 54-byte header
			int width = *(int*)&info[18];// extract image height and width from header
			int height = *(int*)&info[22];
			/*this->image->setRow(height);
			this->image->setColumn(width);*/
			int size = 3 * width * height;
			readFile.seekg(54, std::ios::beg);
			char* data = new char[size];
			readFile.read(data, size);// read the rest of the data at once
			readFile.close();
			this->image = new Matrix<int>(height, width * 3, 0);
			int k = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width * 3; j++) {
					this->image->matrix[i][j] = *(int*)&data[k];
					k++;
				}
				k++;
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
			this->image = new Matrix<int>(height, width * 3, 0);
			int k = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width * 3; j++) {
					this->image->matrix[i][j] = *(int*)&data[k];
					k++;
				}
				k++;
			}
			//this->image->setColumn(this->image->getColumn() / 3);
		}
	}
}

template<int red, int green, int blue>
Image<red, green, blue>::Image(std::string fileName, std::string fileFormat)
{
	readFromFile(fileName, fileFormat);
}

template<int red, int green, int blue>
Image<red, green, blue>::~Image()
{
}

template<int red, int green, int blue>
void Image<red, green, blue>::imread(std::string fileName, std::string fileFormat)
{
	readFromFile(fileName, fileFormat);
}

template<int red, int green, int blue>
void Image<red, green, blue>::imwrite(std::string fileName, std::string fileFormat)
{
	if (fileFormat._Equal("bmp")) {
		FILE* f;
		unsigned char* img = NULL;
		int w = this->image->getColumn()/3; //1 rgb =3byte
		int h = this->image->getRow();
		int filesize = 54 + 3 * w * h;  //w is your image width, h is image height, both int
		int lenght = 3 * w * h;
		img = (unsigned char*)malloc(lenght);
		memset(img, 0, lenght);
		int k = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w * 3; j++)
			{
				img[k] = this->image->matrix[i][j];
				k++;
			}
			k++;
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
		int w = this->image->getColumn()/3; //1 rgb =3byte
		int h = this->image->getRow();
		int filesize = 2 + 3 * w * h;  //w is your image width, h is image height, both int
		img = (unsigned char*)malloc(3 * w * h);
		memset(img, 0, 3 * w * h);
		int k = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w * 3; j++)
			{
				img[k] = this->image->matrix[i][j];
				k++;
			}
			k++;
		}
		unsigned char bmpfileheader[2] = { w,h };
		int n = fileName.length();
		char* c = new char[(n + 1)];
		strcpy(c, fileName.c_str());
		f = fopen(c, "wb");
		fwrite(bmpfileheader, 1, 2, f);
		fwrite(img, 1, filesize - 2, f);

		free(img);
		fclose(f);
	}
}

template<int red, int green, int blue>
void Image<red, green, blue>::color2gray()
{
	int width = this->image->getColumn();
	int height = this->image->getRow();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j+2 < width; j += 3)
		{
			int illuminate = this->image->matrix[i][j+1]/3;//r=b=0 
			this->image->matrix[i][j] = illuminate;
			this->image->matrix[i][j+1] =illuminate;
			this->image->matrix[i][j + 2] = illuminate;
		}
	}
}
