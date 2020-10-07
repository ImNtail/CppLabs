#include <iostream>
#include "Matrix.h"

//==================== constructors / destructor ====================

Matrix::Matrix(int x, int y)
{

	std::cout << "Vector has created" << std::endl;
}

Matrix::~Matrix()
{
	
	for (int i = 0; i < x; i++)
		delete[] array_;
	std::cout << "Vector has deleted" << std::endl;
}

//==================== setters / getters / incr / decr ====================

void Matrix::setAt(int x, int y, int value)
{
	
}

int Matrix::at(int x, int y) const
{
	return array_[x][y];
}

int Matrix::size() const
{
	return x*y;
}

Matrix& Matrix::operator++()
{
	
}

Matrix& Matrix::operator--()
{

}

//==================== other functions ====================

void Matrix::print() const
{
	
}