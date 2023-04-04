#include <iostream>
#include "Dictionary.h"

class A
{
	int a;
	int b;

public:

	A(int a, int b) : a(a), b(b) {};
};

class B
{
	A* object;

public:


};

int main()
{
	Dictionary dict;

	dict.add(3, "No");
	dict.add(2, "Maybe");
	dict.add(1, "Yes");

	std::cout << dict.get(1); // Yes

	dict.update(1, "Later");

	std::cout << dict.get(1); // Later

	std::cout << dict[1]; // true

}