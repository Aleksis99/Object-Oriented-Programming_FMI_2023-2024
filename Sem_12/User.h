#pragma once
#include <iostream>
#include<string>

class User
{
private:
	
	static int users;
	int id;
	std::string name;
	std::string password;
	
	friend std::ostream& operator<<(std::ostream& os, const User& u);
protected:
	virtual void print(std::ostream& os) const;
	int subsriptionPrice;

public:

	User(std::string name, std::string password, int subsriptionPrice);
	
	std::string getName() const;
	std::string getPassword() const;
	int getId() const;
	int getSubscriptionPrice() const;
	virtual bool isPaidUser() const = 0;
	virtual User* clone() const = 0;
	virtual ~User() {};

};

