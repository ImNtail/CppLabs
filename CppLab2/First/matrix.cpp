#include <iostream>
#include <iomanip>
#include "Vector.h"
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
			++(*(*(array_ + i) + j));
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
			--(*(*(array_ + i) + j));
		}
	}
	return *this;
}
/*
Matrix Ttmp(x_, y_);
	Ttmp.array_ = array_;
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) += 1;
		}
	}
	return Ttmp;
*/

void Matrix::operator++(int)
{
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			(*(*(array_ + i) + j))++;
		}
	}
}

void Matrix::operator--(int)
{
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			(*(*(array_ + i) + j))--;
		}
	}
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

int fact(int num)
{
	if (num == 0)
		return 1;
	else
		return num * fact(num - 1);
}

void Matrix::initFact()
{
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			*(*(array_ + i) + j) = fact(i) + fact(j);
		}
	}
}

Vector* Matrix::forTheTaskMethod()
{
	int rowsCnt = 1;
	Vector* arr1d = new Vector();
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			if (rowsCnt % 2 == 0)
			{
				arr1d->addItem(*(*(array_ + i) + j));
			}
		}
		rowsCnt++;
	}
	return arr1d;
}