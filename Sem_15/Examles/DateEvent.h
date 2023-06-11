#pragma once
#include "Event.h"

struct Date
{
	unsigned day;
	unsigned month;
	unsigned year;

};

class DateEvent : virtual public Event
{
private:

	Date date;

	void validateDate(Date& date) const;
	
protected:
	void print(std::ostream& os) const override;

public:

	DateEvent(const char* name, const char* description, const Date& date);

	Event* clone() const override;

	void setDate(const Date& date);
	const Date& getDate() const;

};

