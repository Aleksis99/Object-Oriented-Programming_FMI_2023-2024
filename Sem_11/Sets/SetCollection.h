#pragma once
#include "RemSet.h"
#include "ArraySet.h"

const size_t INIT_CAPACITY = 4;

class SetCollection
{
private:

	Set** sets = nullptr;
	size_t capacity = INIT_CAPACITY;
	size_t size = 0;

	void free();
	void copy(const SetCollection& other);
	void move(SetCollection&& other);

public:

	SetCollection();
	SetCollection(const SetCollection& other);
	SetCollection(SetCollection&& other);
	SetCollection& operator=(const SetCollection& other);
	SetCollection& operator=(SetCollection&& other);
	~SetCollection();
	void resize(size_t capacity);
	void addSet(Set* set);
	size_t countSets(int el) const;
	bool setIntersection(int el) const;
	bool setUnion(int el) const;
	bool contains(size_t index, int el);
};

