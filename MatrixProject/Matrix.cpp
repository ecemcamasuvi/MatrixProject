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
	T** matrixCurrent = new T * [rowCurrent];
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
		break;
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
	if (this->format != 'n') {
		this->row = rowInput;
		this->column = columnInput;
		createMatrix();
	}
	else {
		T** matrixCurrent = new T * [rowInput];
		for (int i = 0; i < rowInput; i++) {
			matrixCurrent[i] = new T[columnInput];
		}
		for (int i = 0; i < ((rowInput < this->row) ? rowInput : this->row); i++) {
			for (int j = 0; j < ((columnInput < this->column) ? columnInput : this->column); j++) {
				matrixCurrent[i][j] = this->matrix[i][j];
			}
		}
		for (int i = ((rowInput < this->row) ? rowInput : this->row); i < rowInput; i++) {
			for (int j = 0; j < columnInput; j++) {
				matrixCurrent[i][j] = 0;
			}
		}
		for (int i = 0; i < rowInput; i++) {
			for (int j = ((columnInput < this->column) ? columnInput : this->column); j < columnInput; j++) {
				matrixCurrent[i][j] = 0;
			}
		}
		//Herhangi bir örüntü bulunmayan bir matrisin boyutu büyüdüyse yeni oluþan bölgeleri 0'a setle. 
		//Önceki durumunda bulunan kýsýmlar ayný kalsýn.
		this->row = rowInput;
		this->column = columnInput;
		this->matrix = matrixCurrent;
	}
}

template <class T>
void Matrix<T>::print()
{
	std::cout << "\n";
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

template<class T>
Matrix<T>* Matrix<T>::operator+(const Matrix<T>* secondItem)
{
	if (this->column == secondItem->column && this->row == secondItem->row) {
		Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->column; j++) {
				result->matrix[i][j] = this->matrix[i][j] + secondItem->matrix[i][j];
			}
		}
		result->format = 'n';
		//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
		return result;
	}
	else {
		std::cout << "Ayný boyuta sahip matrisleri toplayabilirsiniz.";
		return NULL;
	}
}

template<class T>
Matrix<T>* Matrix<T>::operator-(const Matrix<T>* secondItem)
{
	if (this->column == secondItem->column && this->row == secondItem->row) {
		Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->column; j++) {
				result->matrix[i][j] = this->matrix[i][j] - secondItem->matrix[i][j];
			}
		}
		result->format = 'n';
		//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
		return result;
	}
	else {
		std::cout << "Ayný boyuta sahip matrisleri toplayabilirsiniz.";
		return NULL;
	}
}

template<class T>
Matrix<T>* Matrix<T>::operator*(const Matrix<T>* secondItem)
{
	if (this->column == secondItem->row) {
		Matrix<T>* result = new Matrix<T>(this->row, secondItem->column, 0);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < secondItem->column; j++) {
				for (int k = 0; k < this->column; k++) {
					result->matrix[i][j] += this->matrix[i][k] * secondItem->matrix[k][j];
				}
			}
		}
		result->format = 'n';
		//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
		return result;
	}
	else {
		std::cout << "Girdiðiniz matrislerin boyutu çarpma iþlemi için uygun deðil.";
		return NULL;
	}
}

template<class T>
Matrix<T>* Matrix<T>::operator+(const int scalarItem)
{
	Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] + scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class T>
Matrix<T>* Matrix<T>::operator-(const int scalarItem)
{
	Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] - scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class T>
Matrix<T>* Matrix<T>::operator*(const int scalarItem)
{
	Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] * scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class T>
Matrix<T>* Matrix<T>::operator/(const int scalarItem)
{
	Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] / scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class T>
Matrix<T>* Matrix<T>::operator%(const int scalarItem)
{
	Matrix<T>* result = new Matrix<T>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] % scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class T>
Matrix<T>* Matrix<T>::operator^(const int scalarItem)
{
	Matrix<T>* result = new Matrix<T>(this->row, this->column, 1);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			for (int k = 0; k < scalarItem; k++) {
				result->matrix[i][j] *= this->matrix[i][j];
			}
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}
