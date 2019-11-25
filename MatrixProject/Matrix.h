#ifndef _MATRÝX_H_
#define _MATRÝX_H_
#include <string>
template <class T>
class Matrix
{
private:
	int column;
	int row;
	int value;
	char format;
	T** matrix;
	void createMatrix();
public:
	Matrix();
	Matrix(int rowInput, int columnInput, int valueInput);
	Matrix(int rowInput, int columnInput, char formatInput);
	~Matrix();
	void resize(int rowInput, int columnInput);
	void print();
	void print(std::string file);
	Matrix<T>* operator+(const Matrix<T>* secondItem);
	Matrix<T>* operator-(const Matrix<T>* secondItem);
	Matrix<T>* operator*(const Matrix<T>* secondItem);
	Matrix<T>* operator+(const int scalarItem);
	Matrix<T>* operator-(const int scalarItem);
	Matrix<T>* operator*(const int scalarItem);
	Matrix<T>* operator/(const int scalarItem);
	Matrix<T>* operator%(const int scalarItem);
	Matrix<T>* operator^(const int scalarItem);
	/*template<typename T>
	friend
		Matrix<T>* operator +(const Matrix<T>& firstItem, const Matrix<T>* secondItem);
	template<typename T>
	friend
		Matrix<T> operator +(const Matrix<T>& matrixItem, int scalarItem);*/
};
#endif
//
//friend Matrix<T>& operator +(const Matrix<T>& firstItem, const Matrix<T>& secondItem)
//{
//	if (firstItem->column == secondItem->column&&firstItem->row == secondItem->row) {
//		Matrix<T> result = new Matrix<T>(firstItem->row, firstItem->column, 'n');
//		//n, yeni oluþturulan herhangi bir kurala uymayan bir matrisi ifade eder.
//		T** resultMatrix = new T*[firstItem->row];
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

