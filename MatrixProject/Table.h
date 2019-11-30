#pragma once
#include "Matrix.h"
#include <string>
template <class M>
class Table:public Matrix<int>
{
private:
	int rowCount;
	int colCount;
	std::string* rowNames;
	std::string* colNames;
	std::string** table;
	Matrix<int>* tempArray;
	void setNames();
	void createTable();
public:
	Table();
	Table(int r,int c,int d);
	Table(int r,int c,char ch);
	int itemAt(int r, int c);
	int itemAt(std::string s);
	int itemAt(std::string rs,std::string cs);
	~Table();
};

