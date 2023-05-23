#pragma once
#include "Vehicle.h"
class Truck : virtual public Vehicle
{
private:
	unsigned loadCapacity;

public:

	Truck(std::string regNum, unsigned loadCapacity);
	int getParkingPrice() const override;
	Vehicle* clone() const override;
};

