#pragma once
#include "Set.h"
class ArraySet : public Set
{
private:
	int* arr = nullptr;
	size_t size;
	void copy(const ArraySet& other);
	void free();
	void move(ArraySet&& other);
public:

	ArraySet(int* arr, size_t size);
	ArraySet(const ArraySet& other);
	ArraySet& operator=(const ArraySet& other);
	ArraySet(ArraySet&& other);
	ArraySet& operator=(ArraySet&& other);

	bool contains(int el) const override;
	Set* clone() const override;
};

