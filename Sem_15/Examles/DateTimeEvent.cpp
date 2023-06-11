#include "DateTimeEvent.h"

void DateTimeEvent::print(std::ostream& os) const
{
	DateEvent::print(os);
	os << " " << getTime().minutes << ":" << getTime().minutes;
}

DateTimeEvent::DateTimeEvent(const char* name, const char* description, const Date& date, const Time& time) 
	: Event(name, description), DateEvent(name, description, date), TimeEvent(name, description, time)
{
}

Event* DateTimeEvent::clone() const
{
	return new DateTimeEvent(*this);
}
