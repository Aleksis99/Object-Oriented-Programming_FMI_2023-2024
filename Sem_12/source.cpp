#include <iostream>
#include "UsersServer.h"
#include "Singleton.h"


int main()
{

	UsersServer server("MyServer");

	server.addUser("user1", "pass123", UserType::Free);
	server.addUser("user1", "pass123", UserType::Paid);
	server.addUser("user1", "pass123", UserType::Pro);
	server.addUser("user1", "pass123", UserType::Pro);
	server.addUser("user1", "pass123", UserType::Pro);

	server.deleteUserById(3);
	server.changeUserSubscription(0, UserType::Paid);
	std::cout << server.getPaidSubcriptionsCount() << std::endl;
	std::cout << server.getTotalMonthlyRevenue() << std::endl;
	std::cout << server << std::endl;


}
