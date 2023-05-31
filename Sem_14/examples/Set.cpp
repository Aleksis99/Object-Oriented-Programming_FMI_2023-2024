#include "Set.h"

void Set::set(char ch, bool value)
{
	if (ch < 'A' || ch > 'Z')
		throw "Invalid variable";

	vars[(int)(ch - 'A')] = value;
}

bool Set::get(char ch) const
{
	if (ch < 'A' || ch > 'Z')
		throw "Invalid variable";

	return vars[(int)(ch - 'A')];
}

