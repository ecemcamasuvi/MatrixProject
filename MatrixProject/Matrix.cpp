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
	T** matrixCurrent = new T*[row];
	for (int i = 0; i < row; i++) {
		matrixCurrent[i] = new T[column];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrixCurrent[i][j] = 0;
		}
	}
	this->matrix = matrixCurrent;
}

template <class T>
Matrix<T>::Matrix(int rowInput, int columnInput, int valueInput)
{
	this->row = rowInput;
	this->column = columnInput;
	this->value = valueInput;
	T** matrixCurrent = new T*[row];
	for (int i = 0; i < row; i++) {
		matrixCurrent[i] = new T[column];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrixCurrent[i][j] = valueInput;
		}
	}
	this->matrix = matrixCurrent;
}

template <class T>
Matrix<T>::Matrix(int rowInput, int columnInput, char formatInput)
{
	this->row = rowInput;
	this->column = columnInput;
	this->format = formatInput;
	T** matrixCurrent = new T*[row];
	for (int i = 0; i < row; i++) {
		matrixCurrent[i] = new T[column];
	}
	switch (formatInput)
	{
	case 'e':
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
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
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				matrixCurrent[i][j] = rand() % 256;
			}
		}
	default:
		std::cout << "Geçerli bir ifade giriniz.";
		break;
	}
	this->matrix = matrixCurrent;
}

template<class T>
Matrix<T>::~Matrix()
{
}


template <class T>
void Matrix<T>::resize(int rowInput, int columnInput)
{
	T** previousMatrix = this->matrix;
	int previousMatrixRow = this->row;
	int previousMatrixColumn = this->column;
	this->row = rowInput;
	this->column = columnInput;
	this->matrix = new T*[this->row];
	for (int i = 0; i < row; i++) {
		this->matrix[i] = new T[this->column];
	}
	for (int i = 0; i < ((this->row < previousMatrixRow) ? this->row : previousMatrixRow); i++) {
		for (int j = 0; j < ((this->column < previousMatrixColumn) ? this->column : previousMatrixColumn); j++) {
			this->matrix[i][j] = previousMatrix[i][j];
		}
	}
	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (matrix[i][j] == null) {
				matrix[i][j] = 0;
			}
		}
	}*/
}

template <class T>
void Matrix<T>::print()
{
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			std::cout << this->matrix[i][j]+" ";
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
				myfile << this->matrix[i][j]+" ";
			}
			myfile << "\n";
		}
		myfile.close();
	}
}
