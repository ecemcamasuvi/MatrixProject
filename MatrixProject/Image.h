#pragma once
#include "Matrix.h"
#include <string>
template<typename rgb>
class Image :public Matrix<int>
{
private:
	Matrix<int>* redVal;
	Matrix<int>* greenVal;
	Matrix<int>* blueVal;
	void readFromFile(std::string fileName, std::string fileFormat);
	bool isGray = false;
	bool isBinary = false;
public:
	Image();
	Image(int width, int height);
	Image(std::string fileName, std::string fileFormat);
	~Image();
	void imread(std::string fileName, std::string fileFormat);
	void imwrite(std::string fileName, std::string fileFormat);
	void color2gray();
	void gray2binary(int thr);
	void erosion();
	void dilation();
	void opening();
	void closing();
};


