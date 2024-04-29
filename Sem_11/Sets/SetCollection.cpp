#include "SetCollection.h"

void SetCollection::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete sets[i];
	}

	delete[] sets;
}

void SetCollection::copy(const SetCollection& other)
{
	size = other.size;
	capacity = other.capacity;

	sets = new Set * [capacity];

	for (size_t i = 0; i < size; i++)
	{
		sets[i] = other.sets[i]->clone();
	}
}

void SetCollection::move(SetCollection&& other)
{
	size = other.size;
	capacity = other.capacity;
	sets = other.sets;
	other.sets = nullptr;
}

SetCollection::SetCollection()
{
	sets = new Set * [capacity];
}

SetCollection::SetCollection(const SetCollection& other)
{
	copy(other);
}

SetCollection::SetCollection(SetCollection&& other)
{
	move(std::move(other));
}

SetCollection& SetCollection::operator=(const SetCollection& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

SetCollection& SetCollection::operator=(SetCollection&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

SetCollection::~SetCollection()
{
	free();
}

void SetCollection::resize(size_t capacity)
{
	if (capacity < size)
		throw "Invalid resize";

	this->capacity = capacity;

	Set** newSets = new Set* [capacity];

	for (size_t i = 0; i < size; i++)
	{
		newSets[i] = sets[i];
	}

	delete[] sets;
	sets = newSets;
}

void SetCollection::addSet(Set* set)
{
	if (size == capacity)
		resize(capacity * 2);

	sets[size] = set->clone();
	size++;
}

size_t SetCollection::countSets(int el) const
{
	size_t result = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (sets[i]->contains(el))
			result++;
	}

	return result;
}

bool SetCollection::setIntersection(int el) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!sets[i]->contains(el))
			return false;
	}

	return true;
}

bool SetCollection::setUnion(int el) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (sets[i]->contains(el))
			return true;
	}

	return false;
}

bool SetCollection::contains(size_t index, int el)
{
	if (index >= size)
		throw "Index out of bounds";

	return sets[index]->contains(el);
}
