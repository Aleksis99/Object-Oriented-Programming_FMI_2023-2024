#include "PaidUser.h"

void PaidUser::print(std::ostream& os) const
{
	User::print(os);
	os << "Paid user Subscription Price: " << subsriptionPrice;

}

PaidUser::PaidUser(std::string name, std::string password, int subcriptionPrice)
	:User(name, password, subcriptionPrice)
{
}

User* PaidUser::clone() const
{
	return new PaidUser(*this);
}

bool PaidUser::isPaidUser() const
{
	return true;
}
