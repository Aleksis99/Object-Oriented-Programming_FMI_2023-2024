#include <iostream>
#include "Teacher.h"
#include "Student.h"

Person print( Person p)
{
	std::cout << p << std::endl;

	return p;
}

int main()
{
	char** subjects = new char* [1];
	subjects[0] = new char[4] {"OOP"};

	Teacher t("name", 20, subjects, 1);

	Person p = print(t);

	std::cout << p << '\n';
	std::cout << t << '\n';

}