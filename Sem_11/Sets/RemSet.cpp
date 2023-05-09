#include "RemSet.h"

RemSet::RemSet(int num) : num(num)
{
	if (num == 0)
		num = 1;
}

bool RemSet::contains(int element) const
{
	return element % num == 0;
}

Set* RemSet::clone() const
{
	return new RemSet(*this);
}
