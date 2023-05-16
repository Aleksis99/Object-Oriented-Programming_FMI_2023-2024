#pragma once
#include "User.h"
class ProUser : public User
{
protected:
	void print(std::ostream& os) const override;

public:

	ProUser(std::string name, std::string password, int subcriptionPrice);

	User* clone() const override;
	bool isPaidUser() const override;
};

