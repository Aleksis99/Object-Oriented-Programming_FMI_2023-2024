#include<iostream>
#include "Vector.h"

const int INITIAL_SIZE = 4;

void Vector::free()
{
	delete[] arr;
}

void Vector::copyFrom(const Vector& other)
{
	size = other.size;
	capacity = other.capacity;

	arr = new int[capacity];

	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void Vector::move(Vector&& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = other.arr;
	other.arr = nullptr;
}

Vector::Vector()
{
	size = 0;
	capacity = INITIAL_SIZE;
	arr = new int[capacity];
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Vector::~Vector()
{
	free();
}

Vector::Vector(Vector&& other)
{
	move(std::move(other));
}

Vector& Vector::operator=(Vector&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

int Vector::getSize() const
{
	return size;
}

int Vector::operator[](int i) const
{
	if (i >= 0 && i < size)
	{
		return arr[i];
	}

	throw std::exception( "Out of range index");
}

int& Vector::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return arr[i];
	}

	throw std::exception("Out of range index");
}

void Vector::resize(int capacity)
{
	if (size <= capacity)
	{
		this->capacity = capacity;
		int* newArr = new int[capacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
	}
}

void Vector::pushBack(int n)
{
	if (size >= capacity)
	{
		resize(capacity*2);
	}

	arr[size] = n;
	size++;
}

int Vector::popBack()
{
	if (size > 0)
	{
		size--;

		return arr[size];
	}

	throw std::exception("Empty arr");
}

void Vector::removeAt(int index)
{
	if (index >= 0 && index < size)
	{
		for (int i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		size--;
	}
	else 
	{
		throw std::exception("Out of range index");
	}
}

int Vector::find(int n) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n)
		{
			return i;
		}
	}

	return -1;
}

void Vector::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j]) 
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}
