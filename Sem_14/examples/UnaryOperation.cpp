#include "UnaryOperation.h"

void UnaryOperation::copyFrom(const UnaryOperation& other)
{
	operation = other.operation;
	expression = other.expression->clone();
}

void UnaryOperation::free()
{
	delete expression;
}

UnaryOperation::UnaryOperation(char operation, SetExpression* expression)
	:operation(operation), expression(expression)
{
}

UnaryOperation::UnaryOperation(const UnaryOperation& other)
{
	copyFrom(other);
}

UnaryOperation& UnaryOperation::operator=(const UnaryOperation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

UnaryOperation::~UnaryOperation()
{
	free();
}

SetExpression* UnaryOperation::clone() const
{
	return new UnaryOperation(*this);
}

bool UnaryOperation::isElementIn(const Set& set)
{
	if (operation == NEG)
	{
		return !expression->isElementIn(set);
	}

	return false;
}
