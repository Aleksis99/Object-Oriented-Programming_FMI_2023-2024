#include "SetVarialbe.h"

SetVarialbe::SetVarialbe(char var) : var(var)
{
}

bool SetVarialbe::isElementIn(const Set& set)
{
	return set.get(var);
}

SetExpression* SetVarialbe::clone() const
{
	return new SetVarialbe(*this);
}
