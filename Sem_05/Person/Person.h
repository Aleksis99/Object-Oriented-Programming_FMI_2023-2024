#pragma once
class Person
{
private:

	int age;
	char* name;

	void free();
	void copyFrom(const Person& other);
	void move(Person&& other);

public:

	Person();
	Person(int age, const char* name);
	~Person();

	Person(const Person& other);
	Person& operator=(const Person& other);

	Person(Person&& other);
	Person& operator=(Person&& other);

	int getAge() const;
	const char* getName() const;

	void setAge(int age);
	void setName(const char* name);

	void print() const;
};

