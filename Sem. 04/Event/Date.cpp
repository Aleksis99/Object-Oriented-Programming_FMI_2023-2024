#include <iostream>
#include "Date.h"

int maxDaysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() : year(1), month(1), day(1)
{
}

Date::Date(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

void Date::setYear(int year)
{
    if (year <= 0)
    {
        year = 1;
    }

    this->year = year;
}

void Date::setMonth(int month)
{
    if (month < 1 || month > 12)
    {
        month = 1;
    }

    this->month = month;
}

void Date::setDay(int day)
{
    if (isLeapYear())
    {
        maxDaysPerMonth[1] = 29;
    }
    else
    {
        maxDaysPerMonth[1] = 28;
    }

    if (year == 1916 && month == 4 && day < 14)
    {
        day = 14;
    }

    if (day < 1 || day > maxDaysPerMonth[month - 1])
    {
        day = 1;
    }

    this->day = day;
}

void Date::goNextDay()
{
    setDay(day + 1);

    if (day == 1)
    {
        setMonth(month + 1);

        if (month == 1)
        {
            setYear(year + 1);
        }
    }
}

int Date::compare(const Date& other) const
{
    if (year < other.year)
    {
        return -1;
    }

    if (year > other.year)
    {
        return 1;
    }

    if (month < other.month)
    {
        return -1;
    }

    if (month > other.month)
    {
        return 1;
    }

    if (day < other.day)
    {
        return -1;
    }

    if (day > other.day)
    {
        return 1;
    }

    return 0;
}

bool Date::isLeapYear() const
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void Date::print() const
{
    std::cout << year << " " << month << " " << day << std::endl;
}

int Date::getDayOfWeek() const
{
    Date currentDate(1, 1, 1); // saturday
    int dayOfWeek = 5;

    while (this->compare(currentDate) > 0)
    {
        currentDate.goNextDay();
        dayOfWeek = (dayOfWeek + 1) % 7;
    }

    return dayOfWeek + 1;
}
