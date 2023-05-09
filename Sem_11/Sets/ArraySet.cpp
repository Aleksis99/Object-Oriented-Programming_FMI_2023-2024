#include "ArraySet.h"

void ArraySet::free()
{
	delete[] arr;
	size = 0;
}

void ArraySet::copyFrom(const ArraySet& other)
{
	setArray(other.arr, other.size);
}

void ArraySet::setArray(const int* arr, int size)
{
	this->size = size;

	this->arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

ArraySet::ArraySet(const int* arr, int size)
{
	setArray(arr, size);
}

ArraySet::ArraySet(const ArraySet& other)
{
	copyFrom(other);
}

ArraySet& ArraySet::operator=(const ArraySet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ArraySet::~ArraySet()
{
	free();
}

bool ArraySet::contains(int element) const 
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
			return true;
	}

	return false;
}

Set* ArraySet::clone() const
{
	return new ArraySet(*this);
}
