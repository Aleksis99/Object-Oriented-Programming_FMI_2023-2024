#include "Event.h"
#pragma warning (disable : 4996)

void Event::copyFrom(const Event& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

void Event::free()
{
	delete[] name;
	delete[] description;
}

void Event::print(std::ostream& os) const
{
	os << name << " : " << description;
}

Event::Event(const char* name, const char* description)
{
	setName(name);
	setDescription(description);
}

Event::Event(const Event& other)
{
	copyFrom(other);
}

Event& Event::operator=(const Event& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Event::~Event()
{
	free();
}

Event* Event::clone() const
{
	return new Event(*this);
}

const char* Event::getName() const
{
	return name;
}

const char* Event::getDescription() const
{
	return description;
}

void Event::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Event::setDescription(const char* description)
{
	delete[] this->description;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

std::ostream& operator<<(std::ostream& os, const Event& e)
{
	e.print(os);

	return os;
}
