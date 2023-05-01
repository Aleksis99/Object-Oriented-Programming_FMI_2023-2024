#include "Person.h"

void Person::copyFrom(const Person& other)
{
	setAge(other.age);
	setName(other.name);
}

void Person::free()
{
	delete[] name;
	name = nullptr;
}

void Person::move(Person&& other)
{
	name = other.name;
	age = other.age;
	other.name = nullptr;
}

Person::Person()
{
}

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}

Person::~Person()
{
	free();
}

Person::Person(const Person& other) 
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Person::Person(Person&& other)
{
	move(std::move(other));
}

Person& Person::operator=(Person&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::setName(const char* name)
{
	if (this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setAge(int age)
{
	if (age < 0)
	{
		age = 0;
	}

	this->age = age;
}

void Person::print(std::ostream& os) const
{
	os << name << " " << age;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	person.print(os);

	return os;
}
