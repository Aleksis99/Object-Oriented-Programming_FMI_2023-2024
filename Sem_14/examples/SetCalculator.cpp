#include "SetCalculator.h"

void SetCalculator::copyFrom(const SetCalculator& other)
{
	expression = other.expression;
}

void SetCalculator::free()
{
	delete expression;
}

SetExpression* SetCalculator::parse(std::string str) const
{
	if (str.length() == 1)
		return new SetVarialbe(str[0]);

	std::string withoutBrackets = str.substr(1, str.length() - 2);
	int count = 0;

	for (int i = 0; i < withoutBrackets.length(); i++)
	{
		if (withoutBrackets[i] == '(')
			count++;
		if (withoutBrackets[i] == ')')
			count--;

		if (isOperation(withoutBrackets[i]) && count == 0)
		{
			if (withoutBrackets[i] == NEG)
			{
				return new UnaryOperation(NEG, parse(withoutBrackets.substr(i + 1)));
			}
			else
			{
				return new BinaryOperation(withoutBrackets[i], parse(withoutBrackets.substr(0, i)), parse(withoutBrackets.substr(i + 1)));
			}
		}
	}


	return nullptr;
}

bool SetCalculator::isOperation(char ch) const
{
	return	ch == AND ||
		ch == OR ||
		ch == XOR ||
		ch == IMPL ||
		ch == BIMPL ||
		ch == NEG;

}

SetCalculator::SetCalculator(const std::string& str)
{
	expression = parse(str);
}

SetCalculator::SetCalculator(const SetCalculator& other)
{
	copyFrom(other);
}

SetCalculator& SetCalculator::operator=(const SetCalculator& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SetCalculator::~SetCalculator()
{
	free();
}

bool SetCalculator::isElementIn(const Set& set)
{
	return expression->isElementIn(set);
}
