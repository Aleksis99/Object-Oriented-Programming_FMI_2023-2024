#include "BinaryOperation.h"

void BinaryOperation::copyFrom(const BinaryOperation& other)
{
	operation = other.operation;
	left = other.left->clone();
	right = other.right->clone();
}

void BinaryOperation::free()
{
	delete left;
	delete right;
}

BinaryOperation::BinaryOperation(char operation, SetExpression* left, SetExpression* right)
	: operation(operation), left(left), right(right)
{
}

BinaryOperation::BinaryOperation(const BinaryOperation& other)
{
	copyFrom(other);
}

BinaryOperation& BinaryOperation::operator=(const BinaryOperation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

BinaryOperation::~BinaryOperation()
{
	free();
}

bool BinaryOperation::isElementIn(const Set& set)
{
	switch (operation)
	{
	case AND :
		return left->isElementIn(set) && right->isElementIn(set);
	case OR:
		return left->isElementIn(set) || right->isElementIn(set);
	case XOR:
		return (left->isElementIn(set) && !right->isElementIn(set))
			|| (!left->isElementIn(set) && right->isElementIn(set));
	case IMPL:
		return !left->isElementIn(set) || right->isElementIn(set);
	case BIMPL:
		return left->isElementIn(set) == right->isElementIn(set);
	}

	return false;
}

SetExpression* BinaryOperation::clone() const
{
	return new BinaryOperation(*this);
}
