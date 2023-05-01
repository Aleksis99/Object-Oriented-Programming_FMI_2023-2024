#include "Teacher.h"

Teacher::Teacher(const char* name, int age, const char* const* subjects, int subjectsCount) : Person(name, age)
{
	setSubjects(subjects, subjectsCount);
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);

		free();
		copyFrom(other);
	}

	return *this;
}

Teacher::~Teacher()
{
	free();
}

Teacher::Teacher(Teacher&& other) : Person(std::move(other))
{
	move(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other)
{
	if (this != &other)
	{
		Person::operator=(std::move(other));

		free();
		move(std::move(other));
	}

	return *this;
}

void Teacher::print(std::ostream& os) const
{
	Person::print(os);

	for (int i = 0; i < subjectsCount; i++)
	{
		os << " " << subjects[i];
	}
}

void Teacher::free()
{
	for (int i = 0; i < this->subjectsCount; i++)
	{
		delete[] this->subjects[i];
	}

	delete[] this->subjects;
	subjectsCount = 0;
}

void Teacher::move(Teacher&& other)
{
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;
	other.subjects = nullptr;
	other.subjectsCount = 0;	
}

void Teacher::copyFrom(const Teacher& other)
{
	setSubjects(other.subjects, other.subjectsCount);
}

void Teacher::setSubjects(const char* const* subjects, int subjectsCount)
{
	if (this->subjects == subjects || subjects == nullptr)
	{
		return;
	}

	for (int i = 0; i < this->subjectsCount; i++)
	{
		delete[] this->subjects[i];
	}
	
	delete[] this->subjects;

	this->subjectsCount = subjectsCount;
	this->subjects = new char* [subjectsCount];

	for (int i = 0; i < subjectsCount; i++)
	{
		this->subjects[i] = new char[strlen(subjects[i]) + 1];
		strcpy(this->subjects[i], subjects[i]);
	}
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacher)
{
	teacher.print(os);

	return os;
}
