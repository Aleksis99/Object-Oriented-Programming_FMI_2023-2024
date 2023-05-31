#pragma once
#include "SetExpression.h"
class SetVarialbe : public SetExpression
{
	char var;

public:

	SetVarialbe(char var);
	bool isElementIn(const Set& set) override;
	SetExpression* clone() const override;
};

