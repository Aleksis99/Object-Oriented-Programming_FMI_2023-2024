#include "UsersServer.h"

void UsersServer::free()
{
	for (int i = 0; i < MAX_USERS; i++)
	{
		if(users[i] != nullptr)
			delete users[i];
	}

	delete[] users;
}

void UsersServer::copyFrom(const UsersServer& other)
{
	name = other.name;
	size = other.size;
	users = new User * [MAX_USERS];

	for (int i = 0; i < MAX_USERS; i++)
	{
		if (other.users[i] != nullptr)
			users[i] = other.users[i]->clone();
		else
			users[i] = nullptr;
	}

}

void UsersServer::initializeUsers()
{
	users = new User * [MAX_USERS];
	for (int i = 0; i < MAX_USERS; i++)
	{
		users[i] = nullptr;
	}
}

UsersServer::UsersServer(std::string name) :name(name)
{
	initializeUsers();
}

UsersServer::UsersServer(const UsersServer& other)
{
	copyFrom(other);
}

UsersServer& UsersServer::operator=(const UsersServer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

UsersServer::~UsersServer()
{
	free();
}

bool UsersServer::changeUserSubscription(int id, UserType newType)
{
	for (int i = 0; i < MAX_USERS; i++)
	{
		if (users[i] != nullptr && users[i]->getId() == id)
		{
			UserFactory::changeUserType(users[i], newType);
			return true;
		}
	}

	return false;
}

bool UsersServer::addUser(std::string name, std::string password, UserType type)
{
	if (size >= MAX_USERS)
		return false;

	for (int i = 0; i < MAX_USERS; i++)
	{
		if (users[i] == nullptr)
		{
			users[i] = UserFactory::createUser(name, password, type);
			size++;

			return true;
		}
	}

	return false;
}

bool UsersServer::deleteUserById(int id)
{
	if (size == 0)
		return false;

	for (int i = 0; i < MAX_USERS; i++)
	{
		if (users[i] != nullptr && users[i]->getId() == id)
		{
			delete users[i];
			users[i] = nullptr;
			size--;
			return true;
		}
	}

	return false;
}

int UsersServer::getPaidSubcriptionsCount() const
{
	int result = 0;
	for (int i = 0; i < MAX_USERS; i++)
	{
		if(users[i] != nullptr)
			result += (int)users[i]->isPaidUser();
	}

	return result;
}

int UsersServer::getTotalMonthlyRevenue() const
{
	int result = 0;
	for (int i = 0; i < MAX_USERS; i++)
	{
		if (users[i] != nullptr)
			result += (int)users[i]->getSubscriptionPrice();
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const UsersServer& server)
{
	for (int i = 0; i < UsersServer::MAX_USERS; i++)
	{
		if (server.users[i] != nullptr)
			os << *server.users[i] << std::endl;
	}

	return os;
}
