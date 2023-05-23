#pragma once
#include<string>

class Singleton
{

private:
	std::string data;

protected:
	Singleton(std::string data = "");
	static Singleton* instance ;

public:

	std::string getData() const;
	static Singleton* getInstance(std::string data);
	
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

};

