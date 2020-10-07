#pragma once

class Matrix
{
public:
	//==================== constructors / destructor ====================

	Matrix(int rows, int cols);
	~Matrix();

	//==================== setters / getters / incr / decr ====================

	void setAt(int x, int y, int value);
	int at(int x, int y) const;
	int size() const;
	int getRows() const;
	int getCols() const;
	Matrix& operator++ ();
	Matrix& operator-- ();

	//==================== other functions ====================

	void print() const;
	void init(int value);

	//==================== variables ====================
private:
	int** array_;
	int x;
	int y;
};