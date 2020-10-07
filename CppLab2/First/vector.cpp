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
	std::cout << "Vector has deleted" << std::endl;
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

int Vector::size() const
{
	return size_;
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
	std::cout << "\tArray has printed" << std::endl;
}

void Vector::addItem(int value)
{
	int* Ttmp = new int[size_ + 1];
	for (int i = 0; i < size_; i++)
	{
		Ttmp[i] = array_[i];
	}
	Ttmp[size_] = value;
	size_++;
	delete[] array_;
	array_ = Ttmp;
	std::cout << "Item " << value << " has added" << std::endl;
}

void Vector::insertItem(int index, int value)
{
	int* Ttmp = new int[size_ + 1];
	for (int i = 0, j = 0; i < size_ + 1; i++, j++)
	{
		if (i == index)
		{
			j--;
			Ttmp[i] = value;
			continue;
		}
		else
			Ttmp[i] = array_[j];
	}
	size_++;
	delete[] array_;
	array_ = Ttmp;
	std::cout << value << " has inserted at index " << index << std::endl;
}

void Vector::removeItem(int index)
{
	int* Ttmp = new int[size_ - 1];
	bool check = false;
	int removedItem = array_[index];
	for (int i = 0, j = 0; i < size_; i++, j++)
	{
		if (!check && i == index)
		{
			i--;
			check = true;
			continue;
		}
		else
			Ttmp[i] = array_[j];
	}
	size_--;
	delete[] array_;
	array_ = Ttmp;
	std::cout << removedItem << " with index " << index << " has removed" << std::endl;
}