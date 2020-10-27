#include <iostream>
#include "Fraction.h"

//==================== constructors / destructor ====================

int Fraction::cnt = 0;

Fraction::Fraction(int a, int b)
{
	a_ = a;
	b_ = b;
	cnt++;
}

Fraction::Fraction(const Fraction& f)
{
	a_ = f.a_;
	b_ = f.b_;
	cnt++;
}

Fraction& Fraction::operator=(Fraction f)
{
	swap(f);
	return *this;
}

void Fraction::swap(Fraction f)
{
	std::swap(a_, f.a_);
	std::swap(b_, f.b_);
}


Fraction::~Fraction()
{
	std::cout << "Fraction has deleted" << std::endl;
}


//==================== setters / getters ====================

void Fraction::setA(int a)
{
	a_ = a;
}

void Fraction::setB(int b)
{
	b_ = b;
}

int Fraction::getA() const
{
	return a_;
}

int Fraction::getB() const
{
	return b_;
}

int Fraction::getCount() const
{
	return cnt;
}

//==================== other functions ====================

void Fraction::print()
{
	std::cout << a_ << " / " << b_ << std::endl;
}

void Fraction::printAsFraction(double decimalFraction)
{
	
}

void Fraction::printAsFraction(char* decimalFraction)
{

}

int Fraction::gcd(int a, int b)
{
	//Euclid's algorithm (iterative)
	while (a != b)
	{
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}

void Fraction::reduce()
{
	int gcdValue = gcd(a_, b_);
	a_ = a_ / gcdValue;
	b_ = b_ / gcdValue;
}

//==================== operators ====================

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	int f1a = f1.getA(), f1b = f1.getB(),
		f2a = f2.getA(), f2b = f2.getB(),
		fa = f1a * f2b + f2a * f1b,
		fb = f1b * f2b;
	Fraction f(fa, fb);
	f.reduce();
	return f;
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	int f1a = f1.getA(), f1b = f1.getB(),
		f2a = f2.getA(), f2b = f2.getB(),
		fa = f1a * f2b - f2a * f1b,
		fb = f1b * f2b;
	Fraction f(fa, fb);
	f.reduce();
	return f;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	int f1a = f1.getA(), f1b = f1.getB(),
		f2a = f2.getA(), f2b = f2.getB(),
		fa = f1a * f2a, fb = f1b * f2b;
	Fraction f(fa, fb);
	f.reduce();
	return f;
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	int f1a = f1.getA(), f1b = f1.getB(),
		f2a = f2.getA(), f2b = f2.getB(),
		fa = f1a * f2b, fb = f1b * f2a;
	Fraction f(fa, fb);
	f.reduce();
	return f;
}