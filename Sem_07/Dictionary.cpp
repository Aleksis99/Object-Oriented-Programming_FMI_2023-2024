#include "Dictionary.h"

void Dictionary::copyFrom(const Dictionary& other)
{
	pairs = new Pair<int, String>* [other.capacity];
	capacity = other.capacity;
	size = other.size;

	for (int i = 0; i < size; i++)
	{
		pairs[i] = new Pair<int, String>(*other.pairs[i]);
	}
}

void Dictionary::free()
{
	for (int i = 0; i < size; i++)
	{
		delete pairs[i];
	}

	delete[] pairs;
}

void Dictionary::move(Dictionary&& other)
{
	pairs = other.pairs;
	capacity = other.capacity;
	size = other.size;
	other.size = 0;
	other.pairs = nullptr;
}

int Dictionary::find(int key) const
{
	int l = 0;
	int h = size - 1;
	int mid = (l + h) / 2;

	while (l <= h)
	{
		int midKey = pairs[mid]->key;

		if (key == midKey)
		{
			return mid;
		}
		else if(key < midKey)
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}

		mid = (l + h) / 2;
	}

	return -1;
}

void Dictionary::resize(int capacity)
{
	if (capacity < size)
	{
		this->capacity = capacity;

		Pair<int, String>** newPairs = new Pair<int, String>* [capacity];

		for (int i = 0; i < size; i++)
		{
			newPairs[i] = pairs[i];
		}

		delete[] pairs;
		pairs = newPairs;
	}
}

bool Dictionary::add(int key, const String& value)
{
	if (contains(key))
	{
		return false;
	}

	if (size == capacity)
	{
		resize(capacity * 2);
	}

	int newIndex = size;
	size++;

	while (newIndex > 0 && pairs[newIndex - 1]->key > key)
	{
		pairs[newIndex] = pairs[newIndex - 1];
		newIndex--;
	}

	pairs[newIndex] = new Pair<int, String>({ key, value });

	return true;
}

bool Dictionary::update(int key, const String& value)
{
	int index = find(key);
	if (index == -1)
	{
		return false;
	}

	pairs[index]->value = value;

	return true;
}

bool Dictionary::operator[](int key) const
{
	return contains(key);
}

bool Dictionary::contains(int key) const
{
	return find(key) != -1;
}

bool Dictionary::remove(int key)
{
	int index = find(key);

	if (index == -1)
	{
		return false;
	}

	delete pairs[index];

	while (index < size - 1)
	{
		pairs[index] = pairs[index + 1];
	}
	
	size--;

	return true;
}

String Dictionary::get(int key, const String& deffValue)
{
	int index = find(key);

	if (index == -1)
	{
		return deffValue;
	}

	return pairs[index]->value;
}

Dictionary::Dictionary()
{
	capacity = 4;
	pairs = new Pair<int, String>* [capacity];
	size = 0;
}

Dictionary::~Dictionary()
{
	free();
}

Dictionary::Dictionary(const Dictionary& other)
{
	copyFrom(other);
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Dictionary::Dictionary(Dictionary&& other)
{
	move(std::move(other));
}

Dictionary& Dictionary::operator=(Dictionary&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}
