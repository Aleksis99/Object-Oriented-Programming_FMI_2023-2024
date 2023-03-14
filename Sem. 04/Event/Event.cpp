#include "Event.h"
#include <iostream>

Event::Event(const char* name, const Date& date, const Time& time) : date(date), time(time)
{
	setName(name);
}

Event::Event(const char* name, int year, int month, int day, int hours, int minutes, int seconds) 
	: date(year, month, day), time(hours, minutes, seconds)
{
	setName(name);
}

void Event::setName(const char* name)
{
	if (strlen(name) < MAX_SIZE)
	{
		strcpy(this->name, name);
	}
	else
	{
		strcpy(this->name, "No name");
	}
}

void Event::setDate(const Date& date)
{
	this->date = date;
}

void Event::setTime(const Time& time)
{
	this->time = time;
}

const char* Event::getName() const
{
	return name;
}

const Date& Event::getDate() const
{
	return date;
}

const Time& Event::getTime() const
{
	return time;
}

int Event::getDayOfWeek() const
{
	return date.getDayOfWeek();
}

void Event::print() const
{
	std::cout << "Name " << name << std::endl;
	std::cout << "Date ";
	date.print();
	std::cout << "Time ";
	time.print();
}
