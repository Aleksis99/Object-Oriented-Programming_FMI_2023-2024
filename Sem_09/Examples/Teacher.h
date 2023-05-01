#pragma once
#include "Person.h"

class Teacher : public Person
{
private:

	char** subjects = nullptr;
	int subjectsCount = 0;

	void free();
	void move(Teacher&& other);
	void copyFrom(const Teacher& other);

	void setSubjects(const char* const* subjects, int subjectsCount);
	friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);

protected:

	void print(std::ostream& os) const;

public:

	Teacher(const char* name, int age, const char* const* subjects, int subjectsCount);
	Teacher(const Teacher& other);
	Teacher(Teacher&& other);
	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other);
	~Teacher();
};

