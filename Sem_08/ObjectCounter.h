#pragma once
class ObjectCounter
{
private:

	static int count;
	int id;

public:

	ObjectCounter();

	static int getCount();
	int getId() const;
};

