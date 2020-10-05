#include <iostream>
#include "Vector.h"

//==================== constructors / destructor ====================

Vector::Vector()
{
	size_ = 0;
	array_ = new int[size_];

	std::cout << "Null vector has created" << std::endl;
}

Vector::Vector(int size)
{
	size_ = size;
	array_ = new int[size_];

	std::cout << "Vector has created" << std::endl;
}

Vector::~Vector()
{
	delete[] array_;
}

//==================== setters / getters ====================

void Vector::setItem(int index, int value)
{
	array_[index] = value;
}

int Vector::getItem(int index) const
{
	return array_[index];
}

int& Vector::operator[](const int index)
{
	return array_[index];
}

//==================== other functions ====================

void Vector::print() const
{
	std::cout << "Array:" << std::endl;
	for (int i = 0; i < size_; i++)
	{
		std::cout << array_[i] << " ";
	}
	std::cout << "\nArray has printed" << std::endl;
}

void Vector::addItem(int value)
{
	int* tmp = array_;
	delete[] array_;
	size_++;
	array_ = new int[size_];
	array_[size_] = value;
	delete[] tmp;
	std::cout << "Item has added" << std::endl;
}

void Vector::insertItem(int index, int value)
{

}

void Vector::removeItem(int index)
{

}