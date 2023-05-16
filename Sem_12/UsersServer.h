#pragma once
#include "UserFactory.h"

class UsersServer
{
private:
	static const int MAX_USERS = 1000;
	std::string name;
	int size = 0;
	User** users;

	void free();
	void copyFrom(const UsersServer& other);
	void initializeUsers();

	friend std::ostream& operator<<(std::ostream& os, const UsersServer& server);

public:

	UsersServer(std::string name = "");
	UsersServer(const UsersServer& other);
	UsersServer& operator=(const UsersServer& other);
	~UsersServer();

	bool changeUserSubscription(int id, UserType newType);
	bool addUser(std::string name, std::string password, UserType type);
	bool deleteUserById(int id);
	int getPaidSubcriptionsCount() const;
	int getTotalMonthlyRevenue() const;
};

