#pragma once


class ComplexNumber
{

private:

	double real;
	double im;

public:

	ComplexNumber(double real = 0, double im = 0);

	double getReal() const;
	double getIm() const;

	void setReal(double real);
	void setIm(double im);

	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber operator-() const;

	friend std::istream& operator>>(std::istream& is, ComplexNumber& cN);
	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cN);
	friend ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);

};


ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);

