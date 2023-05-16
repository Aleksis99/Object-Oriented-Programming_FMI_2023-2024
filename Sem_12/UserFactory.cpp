#include "UserFactory.h"

int UserFactory::proUsers = 1;
int UserFactory::paidUsers = 1;

User* UserFactory::createUser(std::string name, std::string password, UserType type)
{
    if (type == UserType::Free)
    {
        return new FreeUser(name, password);
    }

    if (type == UserType::Paid)
    {
        int price = paidUsers % 10 != 0 ? PAID_PRICE : PAID_PRICE / 2;
        paidUsers++;
        return new PaidUser(name, password, price);
    }

    if (type == UserType::Pro)
    {
        int price = proUsers % 100 != 0 ? PRO_PRICE : PRO_PRICE / 2;
        proUsers++;
        return new ProUser(name, password, price);
    }

    return nullptr;
}

void UserFactory::changeUserType(User*& user, UserType type)
{
    User* result = createUser(user->getName(), user->getPassword(), type);
    delete user;
    user = result;
}
