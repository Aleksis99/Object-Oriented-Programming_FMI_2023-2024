#include "Calendar.h"

void Calendar::copyFrom(const Calendar& other)
{
	for (size_t i = 0; i < other.events.size(); i++)
	{
		events.push_back(other.events[i]->clone());
	}
}

void Calendar::free()
{
	for (size_t i = 0; i < events.size(); i++)
	{
		delete events[i];
	}

	events.clear();
}

Calendar::Calendar(const Calendar& other)
{
	copyFrom(other);
}

Calendar& Calendar::operator=(const Calendar& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Calendar::~Calendar()
{
	free();
}

void Calendar::addEvent(const Event* e)
{
	events.push_back(e->clone());
}

std::ostream& operator<<(std::ostream& os, const Calendar& c)
{
	for (size_t i = 0; i < c.events.size(); i++)
	{
		os << (*c.events[i]) << std::endl;
	}

	return os;
}
