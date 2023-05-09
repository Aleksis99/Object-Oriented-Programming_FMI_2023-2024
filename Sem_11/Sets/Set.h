#pragma once
class Set
{
public:
	virtual bool contains(int element) const = 0;
	virtual ~Set() {};
	virtual Set* clone() const = 0;
};

