#pragma once

class Matrix
{
public:
	//==================== constructors / destructor ====================

	Matrix(int x, int y);
	~Matrix();

	//==================== setters / getters / incr / decr ====================

	void setAt(int x, int y, int value);
	int at(int x, int y) const;
	int size() const;
	Matrix& operator++ ();
	Matrix& operator-- ();

	//==================== other functions ====================

	void print() const;

	//==================== variables ====================
private:
	int** array_;
	int x;
	int y;
};