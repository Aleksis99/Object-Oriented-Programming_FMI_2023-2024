#pragma once
#include "Set.h"

const char AND		= '^';
const char OR		= 'v';
const char XOR		= 'x';
const char IMPL		= '>';
const char BIMPL	= '=';
const char NEG		= '!';

class SetExpression
{
public:

	virtual bool isElementIn(const Set& set) = 0;
	virtual SetExpression* clone() const = 0;
	virtual ~SetExpression() = default;
};

