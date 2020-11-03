/*
Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
 - Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.
 - В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые
позволяют получить и установить значение элемента массива с индексом [i][j], T –
это тип элементов массива по варианту (int или double).
 - Перегрузить операторы инкремента и декремента (как префиксного, так и
постфиксного). Смысл инкремента / декремента всего массива заключается в
инкременте / декременте каждого элемента массива
*/

#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "Vector.h"

void main()
{
	//============================== VECTOR ==============================
	std::cout << "============================== Vector test ==============================" << std::endl;
	Vector v1;
	v1.print();

	v1.addItem(1);
	v1.addItem(2);
	v1.addItem(3);
	v1.addItem(4);
	v1.addItem(5);
	v1.print();

	std::cout << "First item: " << v1.getItem(0) << std::endl;
	std::cout << "Second item: " << v1[1] << std::endl;
	std::cout << "Third item: " << v1.getItem(2) << std::endl;
	std::cout << "Fourth item: " << v1[3] << std::endl;
	std::cout << "Last item: " << v1.getItem(4) << std::endl;

	v1.setItem(0, 10);
	v1.print();

	v1.removeItem(0);
	v1.print();

	v1.removeItem(v1.size() - 1);
	v1.print();

	v1.insertItem(0, 10);
	v1.insertItem(1, 1);
	v1.print();   
	
	//============================== MATRIX ==============================
	std::cout << "\n============================== Matrix test ==============================" << std::endl;

	Matrix m1(5, 5);
	m1.init(5);
	m1.print();

	m1.setAt(2, 2, 10);
	m1.setAt(3, 5, 20);
	m1.setAt(5, 3, 30);
	m1.print();

	std::cout << "Size of matrix is " << m1.size() << std::endl;
	std::cout << "Item with coordinates (2,2) is " << m1.at(2, 2) << std::endl;
	std::cout << "There are " << m1.getRows() << " rows in this matrix" << std::endl;
	std::cout << "There are " << m1.getCols() << " cols in this matrix" << std::endl;

	++m1;
	m1.print();

	--m1;
	m1.print();

	m1++;
	m1.print();

	m1--;
	m1.print();

	//============================== 2nd task of the 1st lab ==============================
	std::cout << "\n============================== The 2nd task of the 1st lab ==============================" << std::endl;
	Matrix arr2d(5, 5);
	arr2d.initFact();
	arr2d.print();
	Vector* arr1d = arr2d.forTheTaskMethod();
	arr1d->print();
	arr1d->~Vector();
}