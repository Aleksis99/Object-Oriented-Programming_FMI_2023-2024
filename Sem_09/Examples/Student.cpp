#include "Student.h"

Student::Student(const char* name, int age, int examsPassed) : Person(name, age)
{
	setExamsPassed(examsPassed);
}

int Student::getExamsPassed() const
{
	return examsPassed;
}

void Student::setExamsPassed(int examsPassed)
{
	if (examsPassed < 0 )
	{
		examsPassed = 0;
	}

	this->examsPassed = examsPassed;
}

void Student::print(std::ostream& os) const
{
	Person::print(os);
	os << " " << examsPassed;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
	student.print(os);

	return os;
}
