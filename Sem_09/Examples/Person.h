#pragma once
#pragma warning (disable : 4996)
#include <iostream>

class Person
{
private:

	char* name = nullptr;
	int age;

	void copyFrom(const Person& other);
	void free();
	void move(Person&& other);

	friend std::ostream& operator<<(std::ostream& os, const Person& person);

protected:

	void print(std::ostream& os) const;

public:

	Person();
	Person(const char* name, int age);
	Person(const Person& other);
	Person(Person&& other);
	Person& operator=(const Person& other);
	Person& operator=(Person&& other);
	~Person();

	const char* getName() const;
	int getAge() const;

	void setName(const char* name);
	void setAge(int age);
};

