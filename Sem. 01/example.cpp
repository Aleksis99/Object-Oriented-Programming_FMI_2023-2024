#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)

struct Person
{
	char name[32];
	char lastName[32];
	int age;
};

struct Family
{
	Person father;
	Person mother;
	int age;
};

void readPerson(Person& p)
{
	std::cin >> p.name >> p.lastName >> p.age;
}

void printPerson(const Person& p)
{
	std::cout << p.name << p.lastName << p.age << std::endl;
}

void printFamily(const Family& f)
{
	printPerson(f.father);
	printPerson(f.mother);
	std::cout << f.age;
}

int main()
{
	const Person p({ "Ivan", "Petrov", 32 });

	printPerson(p);
	//std::cout << p.name;

	Person p2;
	p2.age = 10;

	std::cout << p2.name;
	std::cout << p2.lastName;

	Family f = { p , p, 12 };

	printFamily(f);

	Person arr[32];

	printPerson(arr[2]);

	Person* dynArr = new Person[32];

	delete[] dynArr;

}

