#pragma once

class Vector
{
public:
	//==================== constructors / destructor ====================

	Vector();
	Vector(int size);
	~Vector();

	//==================== setters / getters ====================

	void setItem(int index, int value);
	int getItem(int index) const;
	int& operator[] (const int index);

	//==================== other functions ====================

	void print() const;
	void addItem(int value);
	void insertItem(int index, int value);
	void removeItem(int index);

	//==================== variables ====================
private:
	int* array_;
	int size_;
}; 