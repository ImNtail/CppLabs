#pragma once

class Fraction
{
	static int cnt;
public:
	//==================== constructors / destructor ====================

	Fraction(int a, int b);
	Fraction(const Fraction& b);
	Fraction& operator=(Fraction f);
	void swap(Fraction f);
	~Fraction();

	//==================== setters / getters ====================

	void setA(int a);
	void setB(int b);
	int getA() const;
	int getB() const;
	int getCount() const;

	//==================== other functions ====================

	void print();
	friend std::ostream& operator<< (std::ostream& out, const Fraction& point);
	static void printAsFraction(double decimalFraction);
	static void printAsFraction(char* decimalFraction);
	static int gcd(int a, int b);
	void reduce();


	//==================== variables ====================
private:
	int a_, b_;
};

//==================== operators ====================

Fraction operator+(const Fraction& f1, const Fraction& f2);
Fraction operator-(const Fraction& f1, const Fraction& f2);
Fraction operator*(const Fraction& f1, const Fraction& f2);
Fraction operator/(const Fraction& f1, const Fraction& f2);