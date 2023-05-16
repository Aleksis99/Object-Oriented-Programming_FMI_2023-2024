#include "FreeUser.h"

void FreeUser::print(std::ostream& os) const
{
	User::print(os);

	os << "Free subscrition";
}

FreeUser::FreeUser(std::string name, std::string password)
	:User(name, password, 0)

{
}

User* FreeUser::clone() const
{
	return new FreeUser(*this);
}

bool FreeUser::isPaidUser() const
{
	return false;
}
