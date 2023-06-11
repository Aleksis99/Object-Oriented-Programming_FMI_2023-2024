#pragma once
#include <iostream>
#include <cstring>

class Event
{
private:

	char* name = nullptr;
	char* description = nullptr;

	void copyFrom(const Event& other);
	void free();

	friend std::ostream& operator<<(std::ostream& os, const Event& e);

protected:

	virtual void print(std::ostream& os) const;

public:

	Event(const char* name, const char* description);
	Event(const Event& other);
	Event& operator=(const Event& other);
	virtual ~Event();

	virtual Event* clone() const;

	const char* getName() const;
	const char* getDescription() const;

	void setName(const char* name);
	void setDescription(const char* description);

};

