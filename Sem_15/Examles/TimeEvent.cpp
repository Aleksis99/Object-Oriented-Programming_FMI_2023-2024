#include "TimeEvent.h"

void TimeEvent::validateTime(Time& time) const
{
	if (time.hours > 23)
		time.hours = 0;

	if (time.minutes > 59)
		time.hours = 0;
}

void TimeEvent::print(std::ostream& os) const
{
	Event::print(os);
	os << " " << time.hours << ":" << time.minutes;
}

TimeEvent::TimeEvent(const char* name, const char* description, const Time& time) : Event(name, description)
{
	setTime(time);
}

Event* TimeEvent::clone() const
{
	return new TimeEvent(*this);
}

void TimeEvent::setTime(const Time& time)
{
	this->time = time;
	validateTime(this->time);
}

const Time& TimeEvent::getTime() const
{
	return time;
}
