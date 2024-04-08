#include "ObjectCounter.h"

size_t ObjectCounter::count = 0;
size_t ObjectCounter::currCount = 0;

ObjectCounter::ObjectCounter()
{
	id = count;
	count++;
	currCount++;
}

ObjectCounter::~ObjectCounter()
{
	currCount--;
}

const size_t& ObjectCounter::getId() const
{
	return id;
}

const size_t& ObjectCounter::getCount()
{
	return count;
}

const size_t& ObjectCounter::getCurrCount()
{
	return currCount;
}
