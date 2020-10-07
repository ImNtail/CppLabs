#include <iostream>
#include <iomanip>
#include "Matrix.h"

//==================== constructors / destructor ====================

Matrix::Matrix(int rows, int cols)
{
	x = rows;
	y = cols;
	array_ = new int*[x];
	for (int i = 0; i < x; i++)
		array_[i] = new int[y];
	std::cout << "Matrix has created" << std::endl;
}

Matrix::~Matrix()
{
	for (int i = 0; i < x; i++)
		delete[] array_[i];
	std::cout << "Matrix has deleted" << std::endl;
}

//==================== setters / getters / incr / decr ====================

void Matrix::setAt(int x, int y, int value)
{
	array_[y-1][x-1] = value;
}

int Matrix::at(int x, int y) const
{
	return array_[y - 1][x - 1];
}

int Matrix::size() const
{
	return x*y;
}

int Matrix::getRows() const
{
	return x;
}

int Matrix::getCols() const
{
	return y;
}

Matrix& Matrix::operator++()
{
	return *this;
}

Matrix& Matrix::operator--()
{
	return *this;
}

//==================== other functions ====================

void Matrix::print() const
{
	std::cout << "Array:" << std::endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << std::setw(8) << *(*(array_ + i) + j);
		}
		std::cout << std::endl;
	}
	std::cout << "Array has printed" << std::endl;
}

void Matrix::init(int value)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			*(*(array_ + i) + j) = value;
		}
	}
}