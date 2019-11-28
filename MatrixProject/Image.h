#pragma once
#include "Matrix.h"
#include <string>
template<int red,int green,int blue>
class Image :public Matrix<int>
{
private:
	struct {
		int redVal=red;
		int greenVal=green;
		int blueVal=blue;
	}rgb;
	Matrix<int>* image;
	void readFromFile(std::string fileName, std::string fileFormat);
public:
	Image();
	Image(int width,int height);
	Image(std::string fileName,std::string fileFormat);
	~Image();
	void imread(std::string fileName, std::string fileFormat);
	void imwrite(std::string fileName, std::string fileFormat);
	void color2gray();
};

