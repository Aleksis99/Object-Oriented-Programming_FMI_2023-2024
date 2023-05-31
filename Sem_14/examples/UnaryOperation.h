#pragma once
#include "SetExpression.h"
class UnaryOperation : public SetExpression
{
private:
	char operation;
	SetExpression* expression;

	void copyFrom(const UnaryOperation& other);
	void free();

public:
	UnaryOperation(char operation, SetExpression* expression);
	UnaryOperation(const UnaryOperation& other);
	UnaryOperation& operator=(const UnaryOperation& other);
	~UnaryOperation();

	SetExpression* clone() const override;
	bool isElementIn(const Set& set) override;
};

