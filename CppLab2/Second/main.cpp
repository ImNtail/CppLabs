/*
�������� ����� Fraction ��� ������������� ������������ ������(��� ��������� ���� ����� ����� x / y).
����������� ��������� + , -, *, / ��� ������.
����������� ����� void reduce() ��� ���������� �����, � ����� ����������� ������ :
 - int gcd(int n, int m)
	������� ��� ���������� ����������� ������ �������� ����� n � m;
 - void printAsFraction(double decimal_fraction)
 - void printAsFraction(char* decimal_fraction)
	������������� ������ ������ ���������� ����� � ���� ������������
	(��������, ��� �������� decimal_fraction = 0.43 �� ������ ������
	��������� 43 / 100, ��� 0.25 � 1 / 4 � �.�.).
����� ����������� � ���� ������������ ����� ������ ������� ���� ��������� �� ������ ������ � ��������� ����������� ������.
������������������ ������ ���������� ������.������� ��������� �������� ������.
���������� �������� ��������, ���������, ��������� � ������� ������.
������� �� ����� ����������.�������� ����� ���������� ������ ����������� ������� ������.
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