#pragma once
class Date
{
private:

	int year;
	int month;
	int day;

public:

	Date();
	Date(int year, int month, int day);

	int getYear() const;
	int getMonth() const;
	int getDay() const;

	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);

	void goNextDay();
	int compare(const Date& other) const;

	bool isLeapYear() const;
	void print() const;

	int getDayOfWeek() const;
};

