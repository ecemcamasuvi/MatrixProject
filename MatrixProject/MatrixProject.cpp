#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include "Image.h"
#include "Image.cpp"
#include "Table.h"
#include "Table.cpp"

typedef struct rgb {
	int redVal;
	int greenVal;
	int blueVal;
};

int main()
{
	//3. KISIM
	std::cout << "ddsd";
	Table<int>* tab = new Table<int>(4,37,'r');
	std::cout << "\n";
	std::cout<<tab->itemAt(2, 25);//0 verme
	std::cout << "\n";
	std::cout<<tab->itemAt("A2");
	std::cout<<tab->itemAt("2","AA");

	std::string s[] = { "aaaaa","2. satir","gulsah" };
	tab->setRowNames(s , 3);
	tab->setColNames(s, 2);
	tab->print();


	//2. KISIM
	/*std::cout << "hjddklssssddsddd";
	Image<rgb>* img = new Image<rgb>("untitled.bmp","bmp");
	std::cout<<img->getColumn();
	img->color2gray();//renkliyi griye çeviriyor
	img->gray2binary(100);//siyah beyaz yapar
	img->dilation();
	//img->imread("untitled.bmp", "bmp");//okuma
	img->imwrite("eburhan.bmp", "bmp");//yazma*/
	/*
	img->closing();
	img->imwrite("binn.bmp", "bmp");*/

	//1. KISIM
	/*Matrix<int>* m1 = new Matrix<int>(2, 2, 'e');
	Matrix<float>* m2 = new Matrix<float>(3, 3, 'r');
	Matrix<int>* m3 = new Matrix<int>(3, 6, 1);
	Matrix<int>* m4= new Matrix<int>(3, 6, 'e');*/
	//m1 = m1->operator+(m3);//Toplama işlemi matris ile matris
	/*m2->print();
	m2 = m2->inv();
	std::cout << "\n";
	m2->print();*/
	//std::cout<<m2->det();
	//m1->print();
	//m1->resize(3, 4);//yeniden boyutlandırma
	//m1 = m1->operator^(3);
	//m1->print();
	/*std::cout << "\n";
	m1->print("gulsah.txt");*/
	//m2->print();
	//m2->T()->print();
	//m2->print();
	//std::cout<<m2->det();
	//m2->inv()->print();
	//m2->print();
	//m2->operator/(5)->print();
	///*m1->inv()->print();*/
	//m1->resize(6, 7);
	//m1->print("deneme.txt");

}
