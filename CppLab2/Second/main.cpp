/*
Написать класс Fraction для представления обыкновенных дробей(как отношения двух целых чисел x / y).
Перегрузить операторы + , -, *, / для дробей.
Реализовать метод void reduce() для сокращения дроби, а также статические методы :
 - int gcd(int n, int m)
	функция для нахождения наибольшего общего делителя чисел n и m;
 - void printAsFraction(double decimal_fraction)
 - void printAsFraction(char* decimal_fraction)
	перегруженные методы вывода десятичной дроби в виде обыкновенной
	(например, при значении decimal_fraction = 0.43 на экране должно
	вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса.Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей.
Вывести на экран результаты.Показать также результаты работы статических методов класса.
*/

#include <iostream>
#include "Fraction.h"

void main()
{
	Fraction a = Fraction(5, 7);
	std::cout << "A is " << a << std::endl;

	a.setA(355);
	a.setB(555);
	std::cout << "A is " << a << std::endl;
	std::cout << "Count of fractions: " << a.getCount() << std::endl;
	std::cout << "Numerator of a is " << a.getA() << " and denominator of a is " << a.getB() << std::endl;

	Fraction b = a;
	std::cout << "B is " << b << std::endl;
	std::cout << "Count of fractions: " << a.getCount() << std::endl;

	std::cout << "GCD of b is " << b.gcd(b.getA(), b.getB()) << std::endl;
	b.reduce();
	std::cout << "B is " << b << std::endl;

	a.setA(3); a.setB(15);
	b.setA(4); b.setB(18);
	a = a + b;
	std::cout << "A is " << a << std::endl;
	a = a - b;
	std::cout << "A is " << a << std::endl;
	a = a * b;
	std::cout << "A is " << a << std::endl;
	a = a / b;
	std::cout << "A is " << a << std::endl;
	Fraction::printAsFraction(0.566);
	//Fraction::printAsFraction("0.25");
}