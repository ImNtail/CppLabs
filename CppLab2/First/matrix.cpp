#include <iostream>
#include <iomanip>
#include "Matrix.h"

//==================== constructors / destructor ====================

Matrix::Matrix(int rows, int cols)
{
	x_ = rows;
	y_ = cols;
	array_ = new int*[x_];
	for (int i = 0; i < x_; i++)
		array_[i] = new int[y_];
	std::cout << "Matrix has created" << std::endl;
}

Matrix::Matrix(const Matrix& m)
{
	x_ = m.x_;
	y_ = m.y_;
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) = *(*(m.array_ + i) + j);
		}
	}
}

Matrix& Matrix::operator=(Matrix m)
{
	swap(m);
	return *this;
}

void Matrix::swap(Matrix m)
{
	std::swap(x_, m.x_);
	std::swap(y_, m.y_);
	std::swap(array_, m.array_);
}

Matrix::~Matrix()
{
	for (int i = 0; i < x_; i++)
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
	return x_*y_;
}

int Matrix::getRows() const
{
	return x_;
}

int Matrix::getCols() const
{
	return y_;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) += 1;
		}
	}
	return *this;
}

Matrix& Matrix::operator--()
{
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) -= 1;
		}
	}
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix Ttmp(*this);
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) += 1;
		}
	}
	return Ttmp;
}

Matrix Matrix::operator--(int)
{
	Matrix Ttmp(*this);
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) -= 1;
		}
	}
	return Ttmp;
}
//==================== other functions ====================

void Matrix::print() const
{
	std::cout << "Array:" << std::endl;
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			std::cout << std::setw(8) << *(*(array_ + i) + j);
		}
		std::cout << std::endl;
	}
	std::cout << "Array has printed" << std::endl;
}

void Matrix::init(int value)
{
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) = value;
		}
	}
}