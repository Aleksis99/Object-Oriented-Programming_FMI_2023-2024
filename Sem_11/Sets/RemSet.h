#pragma once
#include "Set.h"

class RemSet : public Set
{
private:
	int num;

public:
	
	RemSet(int num);
	bool contains(int element) const override;
	Set* clone() const override;

};

