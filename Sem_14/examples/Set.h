#pragma once


class Set
{
private:
	bool vars[26]{ false };

public:

	void set(char ch, bool value);
	bool get(char ch) const;
};

