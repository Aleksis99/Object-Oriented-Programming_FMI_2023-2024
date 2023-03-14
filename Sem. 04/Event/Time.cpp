#include <iostream>
#include "Time.h"

int Time::getTimeInSeconds() const
{
    return (hours * 3600 + minutes * 60 + seconds);
}

void Time::setTimeBySeconds(int seconds)
{
    if (seconds < 0)
    {
        seconds = 0;
    }

    int hours = seconds / 3600;
    setHours(hours);

    int minutes = seconds % 3600;
    minutes /= 60;

    setMinutes(minutes);

    setSeconds(seconds % 60);
}

Time::Time() : hours(0), minutes(0), seconds(0)
{
}

Time::Time(int hours, int minutes, int seconds)
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

int Time::getHours() const
{
    return hours;
}

int Time::getMinutes() const
{
    return minutes;
}

int Time::getSeconds() const
{
    return seconds;
}

void Time::setHours(int hours)
{
    if (hours < 0 || hours > 23)
    {
        hours = 0;
    }

    this->hours = hours;
}

void Time::setMinutes(int minutes)
{
    if (minutes < 0 || minutes > 59)
    {
        minutes = 0;
    }

    this->minutes = minutes;
}

void Time::setSeconds(int seconds)
{
    if (seconds < 0 || seconds > 59)
    {
        seconds = 0;
    }

    this->seconds = seconds;
}

void Time::addHours(int hours)
{
    int seconds = getTimeInSeconds() + hours * 3600;
    setTimeBySeconds(seconds);
}

void Time::addMinutes(int minutes)
{
    int seconds = getTimeInSeconds() + minutes * 60;
    setTimeBySeconds(seconds);
}

void Time::addSeconds(int seconds)
{
    seconds = getTimeInSeconds() + seconds;
    setTimeBySeconds(seconds);
}

Time& Time::timeToMidnight() const
{
    Time time(23, 59, 59);
    Time result = this->timeDifferce(time);
    result.addSeconds(1);

    return result;
}

Time& Time::timeDifferce(const Time& other) const
{
    Time result;

    int timeDifferce = getTimeInSeconds() - other.getTimeInSeconds();

    if (timeDifferce < 0)
    {
        timeDifferce *= -1;
    }

    result.setTimeBySeconds(timeDifferce);

    return result;
}

int Time::compare(const Time& other) const
{
    int thisSeconds = getTimeInSeconds();
    int otherSeconds = other.getTimeInSeconds();

    if (thisSeconds < otherSeconds)
    {
        return -1;
    }

    if (thisSeconds > otherSeconds)
    {
        return 1;
    }

    return 0;
}

bool Time::isDinnerTime() const
{
    Time start(20, 30, 0);
    Time end(22, 0, 0);

    return (this->compare(start) >= 0 && this->compare(end) <= 0);
}

bool Time::isPartyTime() const
{
    Time start(23, 0, 0);
    Time end(6, 0, 0);

    return (this->compare(start) >= 0 || this->compare(end) <= 0);
}

void Time::print() const
{
    std::cout << hours << " " << minutes << " " << seconds << std::endl;

}
