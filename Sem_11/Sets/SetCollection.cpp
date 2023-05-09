#include "SetCollection.h"

void SetCollection::free()
{
	for (int i = 0; i < size; i++)
	{
		delete sets[i];
	}

	delete[] sets;
}

void SetCollection::copyFrom(const SetCollection& other)
{
	size = other.size;
	capacity = other.capacity;
	sets = new Set*[capacity];

	for (int i = 0; i < size; i++)
	{
		sets[i] = other.sets[i]->clone();
	}
}

void SetCollection::resize()
{
	capacity *= 2;

	Set** newSets = new Set * [capacity];

	for (int i = 0; i < size; i++)
	{
		newSets[i] = sets[i];
	}

	delete[] sets;
	sets = newSets;
}

SetCollection::SetCollection() : size(0), capacity(4)
{
	sets = new Set * [capacity];
}

SetCollection::SetCollection(const SetCollection& other)
{
	copyFrom(other);
}

SetCollection& SetCollection::operator=(const SetCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SetCollection::~SetCollection()
{
	free();
}

bool SetCollection::elementInSetUnion(int element) const
{
	for (int i = 0; i < size; i++)
	{
		if (sets[i]->contains(element))
			return true;
	}

	return false;
}

bool SetCollection::elementInSetIntersection(int element) const
{
	for (int i = 0; i < size; i++)
	{
		if (!sets[i]->contains(element))
			return false;
	}

	return true;
}

void SetCollection::addSet(const Set* newSet)
{
	if (size == capacity)
		resize();

	sets[size] = newSet->clone();
	size++;
}
