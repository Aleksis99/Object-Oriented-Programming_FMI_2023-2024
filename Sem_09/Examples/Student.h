#pragma once
#include "Person.h"

class Student : public Person
{
private:

	int examsPassed;
	friend std::ostream& operator<<(std::ostream& os, const Student& student);

protected:

	void print(std::ostream& os) const;
	
public:

	Student(const char* name, int age, int examsPassed);

	int getExamsPassed() const;
	void setExamsPassed(int examsPassed);

};

