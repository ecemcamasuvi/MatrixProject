#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

int main()
{
    std::cout << "Hello World!\n"; 
	Matrix<int> *m1 = new Matrix<int>(2,3,5);
	m1->print();
	m1->print("deneme.txt");

}
