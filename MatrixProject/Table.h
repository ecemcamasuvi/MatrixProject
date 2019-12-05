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
	void updateTable();
public:
	Table();
	Table(int r,int c,int d);
	Table(int r,int c,char ch);
	int itemAt(int r, int c);//r. satýrdaki ve c. sütundaki deðeri döndür: 2,2
	int itemAt(std::string s);////r. satýrdaki ve c. sütundaki deðeri döndür :A2
	int itemAt(std::string rs,std::string cs);//mesela 3. satýr, AAA sütunu
	void setRowNames(std::string s[], int n);
	void setColNames(std::string s[], int n);
	void print();
	~Table();
};

