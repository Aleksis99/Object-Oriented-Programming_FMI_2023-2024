#pragma once
#include "DateEvent.h"
#include "TimeEvent.h"

class DateTimeEvent : public DateEvent, public TimeEvent
{
protected:
	void print(std::ostream& os) const override;

public:

	DateTimeEvent(const char* name, const char* description, const Date& date, const Time& time);
	
	Event* clone() const override;
};

