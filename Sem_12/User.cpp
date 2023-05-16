#include "User.h"

int User::users = 0;

void User::print(std::ostream& os) const
{
	os << "Id: " << id << " Username: " << name << " Password: " << password << " ";
}

User::User(std::string name, std::string password, int subsriptionPrice)
	:name(name), password(password), subsriptionPrice(subsriptionPrice), id(users)
{
	users++;
}

std::string User::getName() const
{
	return name;
}

std::string User::getPassword() const
{
	return password;
}

int User::getId() const
{
	return id;
}

int User::getSubscriptionPrice() const
{
	return subsriptionPrice;
}

std::ostream& operator<<(std::ostream& os, const User& u)
{
	u.print(os);

	return os;
}
