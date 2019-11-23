#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

template <class T>
Matrix<T>::Matrix()
{
	this->row = 10;
	this->column = 10;
	this->value = 0;
	createMatrix();
}

template <class T>
Matrix<T>::Matrix(int rowInput, int columnInput, int valueInput)
{
	this->row = rowInput;
	this->column = columnInput;
	this->value = valueInput;
	createMatrix();
}

template <class T>
Matrix<T>::Matrix(int rowInput, int columnInput, char formatInput)
{
	this->row = rowInput;
	this->column = columnInput;
	this->format = formatInput;
	createMatrix();
}

template<class T>
Matrix<T>::~Matrix()
{
}

template<class T>
void Matrix<T>::createMatrix()
{
	int rowCurrent = this->row;
	int columnCurrent = this->column;
	int valueCurrent = this->value;
	char formatCurrent = this->format;
	T** matrixCurrent = new T*[rowCurrent];
	for (int i = 0; i < rowCurrent; i++) {
		matrixCurrent[i] = new T[columnCurrent];
	}
	switch (formatCurrent)
	{
	case 'e':
		for (int i = 0; i < rowCurrent; i++) {
			for (int j = 0; j < columnCurrent; j++) {
				if (i == j) {
					matrixCurrent[i][j] = 1;
				}
				else {
					matrixCurrent[i][j] = 0;
				}
			}
		}
		break;
	case 'r':
		for (int i = 0; i < rowCurrent; i++) {
			for (int j = 0; j < columnCurrent; j++) {
				matrixCurrent[i][j] = rand() % 256;
			}
		}
	default:
		for (int i = 0; i < rowCurrent; i++) {
			for (int j = 0; j < columnCurrent; j++) {
				matrixCurrent[i][j] = valueCurrent;
			}
		}
		break;
	}
	this->matrix = matrixCurrent;
}

template <class T>
void Matrix<T>::resize(int rowInput, int columnInput)
{
	this->row = rowInput;
	this->column = columnInput;
	createMatrix();
}

template <class T>
void Matrix<T>::print()
{
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			std::cout << this->matrix[i][j];
		}
		std::cout << "\n";
	}
}

template<class T>
void Matrix<T>::print(std::string file)
{
	std::ofstream myfile(file);
	if (myfile.is_open())
	{
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->column; j++) {
				myfile << this->matrix[i][j];
			}
			myfile << "\n";
		}
		myfile.close();
	}
}
