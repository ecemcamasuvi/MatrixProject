#ifndef _MATRÝX_H_
#define _MATRÝX_H_
#include <string>
template <class U>
class Matrix
{
private:
	int column;
	int row;
	int value;
	char format;
	void createMatrix();
	float determinant(Matrix<U>* item);
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
	void resize(int rowInput, int columnInput);
	void print();
	void print(std::string file);
	Matrix<U>* T();
	Matrix<U>* emul(const Matrix<U>* secondItem);
	Matrix<U>* inv();
	float det();
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
//		//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
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
//		std::cout << "Ayný boyuta sahip matrisleri toplayabilirsiniz.";
//		return 0;
//	}
//}

