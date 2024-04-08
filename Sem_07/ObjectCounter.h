#pragma once
class ObjectCounter
{
private:

	size_t id;
	static size_t count;
	static size_t currCount;

public:

	ObjectCounter();
	~ObjectCounter();
	const size_t& getId() const;
	static const size_t& getCount();
	static const size_t& getCurrCount();
};

