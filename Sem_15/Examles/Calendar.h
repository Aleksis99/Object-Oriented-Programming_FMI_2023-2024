#pragma once
#include <vector>
#include "DateTimeEvent.h"

class Calendar
{
private:

	std::vector<Event*> events;

	void copyFrom(const Calendar& other);
	void free();

	friend std::ostream& operator<<(std::ostream& os, const Calendar& c);

public:

	Calendar() = default;
	Calendar(const Calendar& other);
	Calendar& operator=(const Calendar& other);
	~Calendar();

	void addEvent(const Event* e);
	
};

