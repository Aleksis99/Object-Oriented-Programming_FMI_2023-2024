#pragma once
#include "FreeUser.h"
#include "PaidUser.h"
#include "ProUser.h"

enum class UserType
{
	Free,
	Paid,
	Pro
};

class UserFactory
{
private:
	static const int PAID_PRICE = 10;
	static const int PRO_PRICE = 100;

	static int proUsers;
	static int paidUsers;

public:

	static User* createUser(std::string name, std::string password, UserType type);
	static void changeUserType(User*& user, UserType type);

	UserFactory() = delete;
};

