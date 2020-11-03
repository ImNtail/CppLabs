#pragma once
#include "Vector.h"

class Matrix
{
	//==================== constructors / destructor ====================
private:
	Matrix(int** arr);
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix& m);
	Matrix& operator=(Matrix m);
	void swap(Matrix m);
	~Matrix();

	//==================== setters / getters / incr / decr ====================

	void setAt(int x, int y, int value);
	int at(int x, int y) const;
	int size() const;
	int getRows() const;
	int getCols() const;
	Matrix& operator++ ();
	Matrix& operator-- ();
	void operator++(int);
	void operator--(int);

	//==================== other functions ====================

	void print() const;
	void init(int value);
	void initFact();
	Vector* forTheTaskMethod();

	//==================== variables ====================
private:
	int** array_;
	int x_;
	int y_;
};