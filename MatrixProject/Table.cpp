#include "pch.h"
#include "Table.h"
#include <string>
template<class U>
void Table<U>::setNames()
{
	const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int columnCount = this->colCount - 1;
	if (columnCount <= 26) {
		this->colNames = new std::string[columnCount];
		for (int i = 0; i < columnCount; i++) {
			this->colNames[i] += letters[i];
		}
	}
	else {
		this->colNames = new std::string[columnCount];
		int k = 0;
		while (columnCount > 0) {
			int j = 26;
			if (columnCount < 26) {
				j = columnCount;
			}
			for (int i = 0; i < j; i++) {
				if (k == 0) {
					this->colNames[i] += letters[i];
				}
				else {
					this->colNames[i + 26 * k] += letters[k - 1];
					this->colNames[i + 26 * k] += letters[i];
				}
			}
			columnCount -= 26;
			k++;
		}
	}
	int rowCount = this->rowCount;
	this->rowNames = new std::string[rowCount];
	for (int i = 0; i < rowCount; i++) {
		this->rowNames[i] = std::to_string(i);
	}

}

template<class M>
void Table<M>::createTable()
{
	std::string** matrixCurrent = new std::string * [this->rowCount];
	for (int i = 0; i < this->rowCount; i++) {
		matrixCurrent[i] = new std::string[this->colCount];
	}
	setNames();
	for (int i = 0; i < this->rowCount; i++) {
		matrixCurrent[i][0] = this->rowNames[i];
	}
	for (int i = 1; i < this->colCount; i++) {
		matrixCurrent[0][i] = this->colNames[i - 1];
	}
	for (int i = 1; i < this->rowCount; i++) {
		for (int j = 1; j < this->colCount; j++) {
			matrixCurrent[i][j] = std::to_string(this->tempArray->matrix[i - 1][j - 1]);

		}
	}
	this->table = matrixCurrent;
}

template<class M>
Table<M>::Table()
{
	this->rowCount = 11;
	this->colCount = 11;
	this->tempArray = new Matrix<M>(10, 10, 0);
	createTable();
	//std::cout << this->table[3][5];
}

template<class M>
Table<M>::Table(int r, int c, int d)
{
	this->rowCount = r + 1;
	this->colCount = c + 1;
	this->tempArray = new Matrix<M>(r, c, d);
	createTable();
}

template<class M>
Table<M>::Table(int r, int c, char ch)
{
	this->rowCount = r + 1;
	this->colCount = c + 1;
	this->tempArray = new Matrix<M>(r, c, ch);
	createTable();
}

template<class M>
int Table<M>::itemAt(int r, int c)
{
	return (int)this->tempArray->matrix[r][c];
}

template<class M>
int Table<M>::itemAt(std::string s)
{
	const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int column = 0;
	int moreThanOne = 0;
	size_t found = -1;
	for (int j = 0; j < 26; j++) {
		found = s.find(letters[j]);
		if (found >= 0 && found <= s.size()) {
			column += j;
			column += moreThanOne * 26;
			moreThanOne++;
			s = s.substr(found + 1, s.size());
			j = 0;
		}
	}
	int row = stoi(s);
	return (int)this->tempArray->matrix[row][column];
}

template<class M>
int Table<M>::itemAt(std::string rs, std::string cs)
{
	int row = stoi(rs);
	const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int column = 0;
	int moreThanOne = 0;
	size_t found = -1;
	while (cs.size() > 0) {
		for (int j = 0; j < 26; j++) {
			found = cs.find(letters[j]);
			if (found >= 0 && found <= cs.size()) {
				column += j;
				column += moreThanOne * 26;
				moreThanOne++;
				cs = cs.substr(found + 1, cs.size());
				break;
			}
		}
	}
	return (int)this->tempArray->matrix[row][column];
}

template<class M>
Table<M>::~Table()
{
}
