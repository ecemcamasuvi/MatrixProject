#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

template <class U>
Matrix<U>::Matrix()
{
	this->row = 10;
	this->column = 10;
	this->value = 0;
	createMatrix();
}

template<class U>
int Matrix<U>::getColumn()
{
	return this->column;
}

template<class U>
int Matrix<U>::getRow()
{
	return this->row;
}

template<class U>
void Matrix<U>::setColumn(int columnInput)
{
	this->column = columnInput;
}

template<class U>
void Matrix<U>::setRow(int rowInput)
{
	this->row = rowInput;
}

template <class U>
Matrix<U>::Matrix(int rowInput, int columnInput, int valueInput)
{
	this->row = rowInput;
	this->column = columnInput;
	this->value = valueInput;
	createMatrix();
}

template <class U>
Matrix<U>::Matrix(int rowInput, int columnInput, char formatInput)
{
	this->row = rowInput;
	this->column = columnInput;
	this->format = formatInput;
	createMatrix();
}

template<class U>
Matrix<U>::~Matrix()
{
}

template<class U>
void Matrix<U>::createMatrix()
{
	int rowCurrent = this->row;
	int columnCurrent = this->column;
	int valueCurrent = this->value;
	char formatCurrent = this->format;
	U** matrixCurrent = new U * [rowCurrent];
	for (int i = 0; i < rowCurrent; i++) {
		matrixCurrent[i] = new U[columnCurrent];
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
				//matrixCurrent[i][j] = rand() % 5;
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

template <class U>
void Matrix<U>::resize(int rowInput, int columnInput)
{
	if (this->format != 'n') {
		this->row = rowInput;
		this->column = columnInput;
		createMatrix();
	}
	else {
		U** matrixCurrent = new U * [rowInput];
		for (int i = 0; i < rowInput; i++) {
			matrixCurrent[i] = new U[columnInput];
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

template <class U>
void Matrix<U>::print()
{
	std::cout << "\n";
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			std::cout << this->matrix[i][j];
			std::cout << "  ";
		}
		std::cout << "\n";
	}
}

template<class U>
void Matrix<U>::print(std::string file)
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

template<class U>
Matrix<U>* Matrix<U>::operator+(const Matrix<U>* secondItem)
{
	if (this->column == secondItem->column && this->row == secondItem->row) {
		Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
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

template<class U>
Matrix<U>* Matrix<U>::operator-(const Matrix<U>* secondItem)
{
	if (this->column == secondItem->column && this->row == secondItem->row) {
		Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
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

template<class U>
Matrix<U>* Matrix<U>::operator*(const Matrix<U>* secondItem)
{
	if (this->column == secondItem->row) {
		Matrix<U>* result = new Matrix<U>(this->row, secondItem->column, 0);
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

template<class U>
Matrix<U>* Matrix<U>::operator+(const int scalarItem)
{
	Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] + scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class U>
Matrix<U>* Matrix<U>::operator-(const int scalarItem)
{
	Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] - scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class U>
Matrix<U>* Matrix<U>::operator*(const int scalarItem)
{
	Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] * scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class U>
Matrix<U>* Matrix<U>::operator/(const int scalarItem)
{
	Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] / scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class U>
Matrix<U>* Matrix<U>::operator%(const int scalarItem)
{
	Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			result->matrix[i][j] = this->matrix[i][j] % scalarItem;
		}
	}
	result->format = 'n';
	//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
	return result;
}

template<class U>
Matrix<U>* Matrix<U>::operator^(const int scalarItem)
{
	Matrix<U>* result = new Matrix<U>(this->row, this->column, 1);
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

template<class U>
Matrix<U>* Matrix<U>::T()
{
	Matrix<U>* transpoze = new Matrix<U>(this->column, this->row, 'n');
	for (int i = 0; i < this->column; i++) {
		for (int j = 0; j < this->row; j++) {
			transpoze->matrix[i][j] = this->matrix[j][i];
		}
	}
	return transpoze;
}

template<class U>
Matrix<U>* Matrix<U>::emul(const Matrix<U>* secondItem)
{
	if (this->column == secondItem->column && this->row == secondItem->row) {
		Matrix<U>* result = new Matrix<U>(this->row, this->column, 0);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->column; j++) {
				result->matrix[i][j] = this->matrix[i][j] * secondItem->matrix[i][j];
			}
		}
		result->format = 'n';
		//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
		return result;
	}
	else {
		std::cout << "Eleman düzeyinde çarpma iþlemi için satýr ve sütunlar eþit olmalýdýr.";
		return NULL;
	}
}

template<class U>
Matrix<U>* Matrix<U>::inv()
{
	//INT DEÐERLER ÝÇÝN AÞAÐIDAKÝ YÖNTEM ÝÞLENDÝ
	/*if (this->column == this->row && determinant(this) != 0) {
		Matrix<U>* result = new Matrix<U>(this->row, this->column, 'e');
		//birim matris
		for (int i = 0; i < this->row; i++) {
			float current = this->matrix[i][i];
			for (int j = 0; j < this->column; j++) {
				this->matrix[i][j] = (this->matrix[i][j] * 1000) / current;
				//float olmadýðýndan 1000 ile çarpýldý.
				result->matrix[i][j] = (result->matrix[i][j] * 1000) / current;
			}
			for (int k = 0; k < this->row; k++) {
				if (i != k) {
					float diyagon = this->matrix[k][i];
					for (int x = 0; x < this->column; x++) {
						this->matrix[k][x] = this->matrix[k][x] * 1000 - (this->matrix[i][x] * diyagon);
						result->matrix[k][x] = result->matrix[k][x] * 1000 - (result->matrix[i][x] * diyagon);
					}
				}
			}
		}
		result->format = 'n';
		return result;
	}
	else {
		std::cout << "Kare ve determinantý 0'dan farklý olan matrisin tersi alýnabilir.";
		return NULL;
	}*/	
	if (this->column == this->row && determinant(this) != 0) {
		Matrix<U>* result = new Matrix<U>(this->row, this->column, 'e');
		//birim matris
		for (int i = 0; i < this->row; i++) {
			float current = this->matrix[i][i];
			for (int j = 0; j < this->column; j++) {
				this->matrix[i][j] = (this->matrix[i][j]) / current;
				result->matrix[i][j] = (result->matrix[i][j]) / current;
			}
			for (int k = 0; k < this->row; k++) {
				if (i != k) {
					float diyagon = this->matrix[k][i];
					for (int x = 0; x < this->column; x++) {
						this->matrix[k][x] = this->matrix[k][x] - (this->matrix[i][x] * diyagon);
						result->matrix[k][x] = result->matrix[k][x]  - (result->matrix[i][x] * diyagon);
					}
				}
			}
		}
		std::cout << "\n UYARI!\nGirilen degerlerin int olmamasi durumunda sonuc yanlis cikabilir.";
		result->format = 'n';
		return result;
	}
	else {
		std::cout << "\nKare ve determinantý 0'dan farklý olan matrisin tersi alýnabilir.";
		return NULL;
	}
}

template<class U>
float Matrix<U>::det()
{
	if (this->column == this->row) {
		float x = determinant(this);
		return x;
	}
	else {
		std::cout << "Kare matrisin determinantý alýnabilir.";
		return NULL;
	}
}
template<class U>
float Matrix<U>::determinant(Matrix<U>* item)
{
	if (item->column == 1) {
		return item->matrix[0][0];
	}
	else {
		float result = 0;
		for (int i = 0; i < item->column; i++) {
			Matrix<U>* temp = new Matrix<U>(item->row - 1, item->column - 1, 0);
			for (int j = 1; j < item->row; j++) {
				int tempCount = 0;
				for (int k = 0; k < item->column; k++) {
					if (i != k) {
						temp->matrix[j - 1][tempCount] = item->matrix[j][k];
						tempCount++;
					}
				}
			}
			if (i % 2 != 1) {
				float x = determinant(temp);
				result += item->matrix[0][i] * x;
			}
			else {
				float x = determinant(temp);
				result -= item->matrix[0][i] * x;
			}
		}
		return result;
	}
}
