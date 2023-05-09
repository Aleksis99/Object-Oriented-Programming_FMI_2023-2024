#pragma once
#include "Set.h"

class SetCollection
{
private:

	Set** sets;
	int size;
	int capacity;

	void free();
	void copyFrom(const SetCollection& other);

	void resize();

public:

	SetCollection();
	SetCollection(const SetCollection& other);
	SetCollection& operator=(const SetCollection& other);
	~SetCollection();

	bool elementInSetUnion(int element) const;
	bool elementInSetIntersection(int element) const;
	void addSet(const Set* newSet);

};

