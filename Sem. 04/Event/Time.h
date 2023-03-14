#pragma once
class Time
{
private:

	int hours;
	int minutes;
	int seconds;

	int getTimeInSeconds() const;
	void setTimeBySeconds(int seconds);

public:

	Time();
	Time(int hours, int minutes, int seconds);

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	void setHours(int hours);
	void setMinutes(int minutes);
	void setSeconds(int seconds);

	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	Time& timeToMidnight() const;
	Time& timeDifferce(const Time& other) const;

	int compare(const Time& other) const;

	bool isDinnerTime() const;
	bool isPartyTime() const;

	void print() const;
};

