#pragma once
#include "SetExpression.h"
class BinaryOperation : public SetExpression
{
private:

	char operation;
	SetExpression* left;
	SetExpression* right;

	void copyFrom(const BinaryOperation& other);
	void free();
	
public:

	BinaryOperation(char operation, SetExpression* left, SetExpression* right);
	BinaryOperation(const BinaryOperation& other);
	BinaryOperation& operator=(const BinaryOperation& other);
	~BinaryOperation();

	bool isElementIn(const Set& set) override;
	SetExpression* clone() const override;
};

