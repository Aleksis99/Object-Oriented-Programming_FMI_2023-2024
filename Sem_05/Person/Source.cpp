#include <iostream>
#include "Person.h"

Person createPerson(int age, const char* name)
{
	Person p(age, name);

	return std::move(p);
}

void printPerson(Person p)
{
	p.print();
}


int main()
{
	Person p(18, "Ivan");
	Person p2;

	p2 = p;

	Person p3 = createPerson(21, "Bobi");

	printPerson(p);

	p2.print();


}