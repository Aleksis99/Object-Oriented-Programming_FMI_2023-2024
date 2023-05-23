#include "Vehicle.h"

Vehicle::Vehicle(const std::string& regNum) : regNum(regNum)
{
}

std::string Vehicle::getRegNum() const
{
	return regNum;
}
