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
public:
	Matrix();
	Matrix(int rowInput, int columnInput, int valueInput);
	Matrix(int rowInput, int columnInput, char formatInput);
	~Matrix();
	void resize(int rowInput, int columnInput);
	void print();
	void print(std::string file);
};
#endif