#include "ObjectCounter.h"

int ObjectCounter::count = 0;

ObjectCounter::ObjectCounter()
{
	id = count;
	count++;
}


int ObjectCounter::getCount()
{
	return count;
}

int ObjectCounter::getId() const
{
	return id;
}
