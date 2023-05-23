#pragma once
#include <string>

class Vehicle
{
private:
	std::string regNum;

public:

	Vehicle(const std::string& regNum);
	std::string getRegNum() const;
	virtual int getParkingPrice() const = 0;
	virtual Vehicle* clone() const = 0;
	virtual ~Vehicle() {};
};

