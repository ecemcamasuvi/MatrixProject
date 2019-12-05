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
	void color2gray();//renkliyi griye çeviriyor
	void gray2binary(int thr);//eþik deðerinin üstündekileri beyaz;altýndakileri siyah yapýyor.beyaz=255,siyah=0--eþik deðeri=21760 verdim
	void erosion();//daraltma
	void dilation();//geniþletme
	void opening();//önce daraltma sonra geniþletme
	void closing();//tam tersi
};


