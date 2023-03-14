#pragma once
#include <cstring>
#include "Date.h"
#include "Time.h"

#pragma warning (disable : 4996)

const int MAX_SIZE = 32;

class Event
{
private:
	char name[MAX_SIZE];
	Date date;
	Time time;

public:

	Event(const char* name, const Date& date, const Time& time);
	Event(const char* name, int year, int month, int day, int hours, int minutes, int seconds);

	void setName(const char* name);
	void setDate(const Date& date);
	void setTime(const Time& time);

	const char* getName() const;
	const Date& getDate() const;
	const Time& getTime() const;

	int getDayOfWeek() const;
	void print() const;
};

