#include "ArraySet.h"

void ArraySet::copy(const ArraySet& other)
{
	size = other.size;
	arr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void ArraySet::free()
{
	delete[] arr;
}

void ArraySet::move(ArraySet&& other)
{
	arr = other.arr;
	size = other.size;
	other.arr = nullptr;
}

ArraySet::ArraySet(int* arr, size_t size) : size(size)
{
	this->arr = new int[size];
	
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

ArraySet::ArraySet(const ArraySet& other)
{
	copy(other);
}

ArraySet& ArraySet::operator=(const ArraySet& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

ArraySet::ArraySet(ArraySet&& other)
{
	move(std::move(other));
}

ArraySet& ArraySet::operator=(ArraySet&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

bool ArraySet::contains(int el) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == el)
			return true;
	}

	return false;
}

Set* ArraySet::clone() const
{
	return new ArraySet(*this);
}
