#include "RemSet.h"

RemSet::RemSet(int rem) : rem(rem)
{
	if (rem == 0)
	{
		this->rem = 1;
	}
}

bool RemSet::contains(int el) const
{
	return el % rem == 0;
}

Set* RemSet::clone() const
{
	return new RemSet(*this);
}
