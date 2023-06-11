#include "DateEvent.h"

void DateEvent::validateDate(Date& date) const
{
	if (date.day > 31)
	{
		date.day = 31;
	}

	if (date.month > 12)
	{
		date.month = 12;
	}
}

void DateEvent::print(std::ostream& os) const
{
	Event::print(os);
	os << " " << date.day << "/" << date.month << "/" << date.year;
}

DateEvent::DateEvent(const char* name, const char* description, const Date& date) : Event(name, description)
{
	setDate(date);
}

Event* DateEvent::clone() const
{
	return new DateEvent(*this);
}

void DateEvent::setDate(const Date& date)
{
	this->date = date;
	validateDate(this->date);
}

const Date& DateEvent::getDate() const
{
	return date;
}
