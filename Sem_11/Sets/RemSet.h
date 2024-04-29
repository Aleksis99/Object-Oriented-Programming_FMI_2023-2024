#pragma once
#include "Set.h"
class RemSet : public Set
{
private:
	int rem;

public:

	RemSet(int rem);
	bool contains(int el) const override;
	Set* clone() const override;
};

