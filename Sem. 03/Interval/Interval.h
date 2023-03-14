#pragma once

class Interval
{
private:

	int a;
	int b;

	int count(bool(*condition)(int)) const;

public:

	Interval();
	Interval(int a, int b);

	int getA() const;
	int getB() const;

	void setA(int a);
	void setB(int b);

	int lenght() const;
	bool contains(int n) const;

	int countPrimeNumbers() const;
	int countPalindromeNumbers() const;
	int countNumbersWithUniqueDigits() const;

	bool startAndEndArePowersOf2() const;

	Interval intersect(const Interval& other) const;

	bool isSubInterval(const Interval& other) const;


};

