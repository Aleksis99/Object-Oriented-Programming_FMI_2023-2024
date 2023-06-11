#pragma once
#include "Event.h"

struct Time
{
	unsigned hours;
	unsigned minutes;
};

class TimeEvent : virtual public Event
{
private:
	Time time;

	void validateTime(Time& time) const;

protected:
	void print(std::ostream& os) const override;

public:

	TimeEvent(const char* name, const char* description, const Time& time);

	Event* clone() const override;

	void setTime(const Time& time);
	const Time& getTime() const;
};

