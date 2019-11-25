#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
	std::cout << "I really really hate C++\n";
	Matrix<int> *m1 = new Matrix<int>(4, 3, 3);
	Matrix<int> *m2 = new Matrix<int>(2, 3, 'r');
	Matrix<int> *m3 = new Matrix<int>(3, 6, 1);
	Matrix<int>* m4=m1->operator^(3);
	m4->print();
	m1->resize(6, 7);
	m1->print("deneme.txt");

}
