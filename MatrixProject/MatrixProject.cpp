﻿#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include "Image.h"
#include "Image.cpp"

int main()
{
	std::cout << "I Hate you C++:'(!!\n";
	Matrix<int>* m1 = new Matrix<int>(2, 2, 5);
	Matrix<float>* m2 = new Matrix<float>(2, 2, 'r');
	Matrix<int>* m3 = new Matrix<int>(3, 6, 1);
	Image<0, 0, 0>* img = new Image<0, 0, 0>("untitled.bmp","bmp");
	std::cout<<img->getColumn();
	img->color2gray();
	img->imwrite("mood.bmp", "bmp");
	
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
