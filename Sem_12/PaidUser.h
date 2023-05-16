#pragma once
#include "User.h"
class PaidUser : public User
{
protected:
	void print(std::ostream& os) const override;

public:

	PaidUser(std::string name, std::string password, int subcriptionPrice);

	User* clone() const override;
	bool isPaidUser() const override;
};

