#pragma once
#include "Matrix.h"
#include <string>
template<int red,int green,int blue>
class Image :public Matrix<int>
{
private:
	struct {
		int redVal=red;
		int greenVal=green;//gri g�r�nt� i�in parlakl�k
		int blueVal=blue;
	}rgb;
	Matrix<int>* image;
public:
	Image();
	Image(int width,int height);
	Image(std::string fileName,std::string fileFormat);
	~Image();
};

