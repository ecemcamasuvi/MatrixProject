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
Image<red, green, blue>::Image(std::string fileName, std::string fileFormat)
{
	if (fileFormat._Equal("bmp")) {
	}
	else if (fileFormat._Equal("bin")) {
		std::ifstream readFile(fileName, std::ios::binary | std::ios::in);
		if (!readFile) {
			std::cout << "Cannot open file!\n";
		}
		else {
			char* size = new char[2];
			readFile.seekg(0, std::ios::beg);
			readFile.read(size, 2);
			readFile.seekg(0, std::ios::end);
			int length = readFile.tellg();
			readFile.seekg(2, std::ios::beg);
			int height = (int)size[0];
			int width = (int)size[1];
			char* binaryImage = new char[length];
			while (readFile.read(binaryImage,length))
				this->image = new Matrix<int>(height, width, 0);
			int k = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					this->image->matrix[i][j] = binaryImage[k];
					k++;
				}
				k++;
			}
			readFile.close();
			this->image->print();
		}
	}
}

template<int red, int green, int blue>
Image<red, green, blue>::~Image()
{
}
