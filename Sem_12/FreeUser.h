#pragma once
#include "User.h"

class FreeUser : public User
{
protected:
	void print(std::ostream& os) const override;

public:

	FreeUser(std::string name, std::string password);

	User* clone() const override;
	bool isPaidUser() const override;

};

