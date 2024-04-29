#pragma once
#include <iostream>

class Set
{
public:

	virtual bool contains(int el) const = 0;
	virtual Set* clone() const = 0;
	virtual ~Set() = default;
};

