#pragma once
#include "Set.h"

class ArraySet : public Set
{
private:
	int* arr;
	int size;

	void free();
	void copyFrom(const ArraySet& other);
	void setArray(const int* arr, int size);

public:

	ArraySet(const int* arr, int size);
	ArraySet(const ArraySet& other);
	ArraySet& operator=(const ArraySet& other);
	~ArraySet();

	bool contains(int element) const override;
	Set* clone() const override;

};

