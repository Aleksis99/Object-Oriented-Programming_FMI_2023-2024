#include "ProUser.h"

void ProUser::print(std::ostream& os) const
{
	User::print(os);
	os << "Pro user Subscription Price: " << subsriptionPrice;

}

ProUser::ProUser(std::string name, std::string password, int subcriptionPrice)
	:User(name, password, subcriptionPrice)
{
}

User* ProUser::clone() const
{
	return new ProUser(*this);
}

bool ProUser::isPaidUser() const
{
	return true;
}
