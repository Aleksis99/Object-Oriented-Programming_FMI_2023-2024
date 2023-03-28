#include <iostream>
#include "ComplexNumber.h"
ComplexNumber::ComplexNumber(double real, double im) : real(real), im(im)
{
}

double ComplexNumber::getReal() const
{
    return real;
}

double ComplexNumber::getIm() const
{
    return im;
}

void ComplexNumber::setReal(double real)
{
    this->real = real;
}

void ComplexNumber::setIm(double im)
{
    this->im = im;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
    real += other.real;
    im += other.im;

    return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
    *this += (-other);

    return *this;
}

ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber(-real, -im);
}

std::istream& operator>>(std::istream& is, ComplexNumber& cN)
{
    is >> cN.real;
    is >> cN.im;

    return is;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& cN)
{
    os << cN.real;
    os << " + i(";
    os << cN.im;
    os << ")";

    return os;
}

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    double resultReal = lhs.real * rhs.real - lhs.im * rhs.im;
    double resultIm = rhs.real * lhs.im + rhs.im * lhs.real;

    return ComplexNumber(resultReal, resultIm);
}

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    ComplexNumber result = lhs;
    result += rhs;

    return result;
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    return lhs + (- rhs);
}
