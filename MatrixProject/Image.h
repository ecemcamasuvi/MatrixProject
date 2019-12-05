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
	void color2gray();//renkliyi griye �eviriyor
	void gray2binary(int thr);//e�ik de�erinin �st�ndekileri beyaz;alt�ndakileri siyah yap�yor.beyaz=255,siyah=0--e�ik de�eri=21760 verdim
	void erosion();//daraltma
	void dilation();//geni�letme
	void opening();//�nce daraltma sonra geni�letme
	void closing();//tam tersi
};


