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
	std::cout << "I really Hateee C++!!hate hate  !!!\n";
	Matrix<int>* m1 = new Matrix<int>(2, 2, 5);
	Matrix<float>* m2 = new Matrix<float>(2, 2, 'r');
	Matrix<int>* m3 = new Matrix<int>(3, 6, 1);
	Table<int>* tab = new Table<int>(4,33,'r');
	std::cout<<tab->itemAt(2, 25);
	std::cout<<tab->itemAt("A2");
	std::cout<<tab->itemAt("2","AA");
	/*2. KISIM
	Image<rgb>* img = new Image<rgb>("untitled.bmp","bmp");
	std::cout<<img->getColumn();
	img->color2gray();
	img->imwrite("grayim.bmp", "bmp");
	img->gray2binary(21760);
	img->closing();
	img->imwrite("grayb.bmp", "bmp");*/

	//1. KISIM
	//Matrix<int>* m4=m1->operator^(3);
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
