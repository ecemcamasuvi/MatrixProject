#ifndef _MATR�X_H_
#define _MATR�X_H_
#include <string>
template <class U>//jenerik class->sadece <> i�erisine girilen tipte veriler al�r nesnesi.
class Matrix
{
private:
	int row;//sat�r
	int column;//s�tun
	int value;//eleman de�eri
	char format;//r ya da e
	void createMatrix();
	int determinant(Matrix<U>* item);
public:
	U** matrix;
	Matrix();
	int getColumn();
	int getRow();
	void setColumn(int columnInput);
	void setRow(int rowInput);
	Matrix(int rowInput, int columnInput, int valueInput);
	Matrix(int rowInput, int columnInput, char formatInput);
	~Matrix();
	void resize(int rowInput, int columnInput);//yeniden boyutland�rma
	void print();
	void print(std::string file);
	Matrix<U>* T();//transpozu sat�r s�tun oluyor.
	Matrix<U>* emul(const Matrix<U>* secondItem);//eleman d�zeyinde �arpma i�lemi
	Matrix<U>* inv();//tersi
	int det();//determinant
	Matrix<U>* operator+(const Matrix<U>* secondItem);
	Matrix<U>* operator-(const Matrix<U>* secondItem);
	Matrix<U>* operator*(const Matrix<U>* secondItem);
	Matrix<U>* operator+(const int scalarItem);
	Matrix<U>* operator-(const int scalarItem);
	Matrix<U>* operator*(const int scalarItem);
	Matrix<U>* operator/(const int scalarItem);
	Matrix<U>* operator%(const int scalarItem);
	Matrix<U>* operator^(const int scalarItem);
	/*template<typename U>
	friend
		Matrix<U>* operator +(const Matrix<U>& firstItem, const Matrix<U>* secondItem);
	template<typename U>
	friend
		Matrix<U> operator +(const Matrix<U>& matrixItem, int scalarItem);*/
};
#endif
//
//friend Matrix<U>& operator +(const Matrix<U>& firstItem, const Matrix<U>& secondItem)
//{
//	if (firstItem->column == secondItem->column&&firstItem->row == secondItem->row) {
//		Matrix<U> result = new Matrix<U>(firstItem->row, firstItem->column, 'n');
//		//n, yeni olu�turulan herhangi bir kurala uymayan bir matrisi ifade eder.
//		U** resultMatrix = new T*[firstItem->row];
//		for (int i = 0; i < firstItem->row; i++) {
//			resultMatrix[i] = new T[firstItem->column];
//		}
//		for (int i = 0; i < firstItem->row; i++) {
//			for (int j = 0; j < firstItem->column; j++) {
//				resultMatrix[i][j] = firstItem->matrix[i][j] + secondItem->matrix[i][j];
//			}
//		}
//		result->matrix = resultMatrix;
//		return *result;
//	}
//	else {
//		std::cout << "Ayn� boyuta sahip matrisleri toplayabilirsiniz.";
//		return 0;
//	}
//}

