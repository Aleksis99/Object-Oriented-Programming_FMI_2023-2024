#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton::Singleton(std::string data) : data(data)
{

}

std::string Singleton::getData() const
{
	return data;
}

Singleton* Singleton::getInstance(std::string data)
{
	if (instance != nullptr)
		return instance;

	instance = new Singleton(data);
}
