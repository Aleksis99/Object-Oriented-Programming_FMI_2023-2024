#include "Interval.h"
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

bool isPalindrome(int n)
{
	int reversed = 0;
	int copy = n;

	while (copy != 0)
	{
		int lastDigit = n % 10;
		reversed *= 10;
		reversed += lastDigit;
		copy /= 10;
	}

	return n == reversed;
}

bool uniqueDigits(int n)
{
	bool digits[10]{ false };

	while (n != 0)
	{
		int lastDigit = n % 10;

		if (digits[lastDigit])
		{
			return false;
		}

		digits[lastDigit] = true;
		n /= 10;
	}

	return true;
}

bool isPowerOf2(int n)
{
	if (n < 1)
	{
		return false;
	}

	if (n == 1)
	{
		return true;
	}

	while (n > 1)
	{
		if (n % 2 == 1)
		{
			return false;
		}

		n /= 2;
	}

	return true;
}

int Interval::count(bool(*condition)(int)) const
{
	int result = 0;

	for (int i = a; i <= b; i++)
	{
		if (condition(i))
		{
			result += 1;
		}
	}

	return result;
}

Interval::Interval()
{
	this->a = 0;
	this->b = 0;
}

Interval::Interval(int a, int b)
{
	this->a = 0;
	this->b = 0;

	if (a <= b)
	{
		this->a = a;
		this->b = b;
	}
}

int Interval::getA() const
{
	return a;
}

int Interval::getB() const
{
	return b;
}

void Interval::setA(int a)
{
	if (a <= b)
	{
		this->a = a;
	}
}

void Interval::setB(int b)
{
	if (a <= b)
	{
		this->b = b;
	}
}

int Interval::lenght() const
{
	return b - a;
}

bool Interval::contains(int n) const
{
	return (n >= a && n <= b);
}

int Interval::countPrimeNumbers() const
{
	return this->count(isPrime);
}

int Interval::countPalindromeNumbers() const
{
	return this->count(isPalindrome);
}

int Interval::countNumbersWithUniqueDigits() const
{
	return 0;
}

bool Interval::startAndEndArePowersOf2() const
{
	return isPowerOf2(a) && isPowerOf2(b);
}

Interval Interval::intersect(const Interval& other) const
{
	int newA = std::max(this->a, other.getA());
	int newB = std::min(this->b, other.getB());

	return Interval(newA, newB);
}

bool Interval::isSubInterval(const Interval& other) const
{
	return this->a <= other.getA() && this->b >= other.getB();
}


