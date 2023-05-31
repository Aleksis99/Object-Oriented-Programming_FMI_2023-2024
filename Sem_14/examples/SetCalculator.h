#pragma once
#include <string>
#include "BinaryOperation.h"
#include "UnaryOperation.h"
#include "SetVarialbe.h"

class SetCalculator
{
private:

	SetExpression* expression;

	void copyFrom(const SetCalculator& other);
	void free();

	SetExpression* parse(std::string str) const;
	bool isOperation(char ch) const;

public:

	SetCalculator(const std::string& str);
	SetCalculator(const SetCalculator& other);
	SetCalculator& operator=(const SetCalculator& other);
	~SetCalculator();

	bool isElementIn(const Set& set);

};

