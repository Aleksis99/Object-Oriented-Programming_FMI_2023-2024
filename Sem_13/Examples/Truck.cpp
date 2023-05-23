#include "Truck.h"

Truck::Truck(std::string regNum, unsigned loadCapacity)
	: Vehicle(regNum), loadCapacity(loadCapacity)
{
}

int Truck::getParkingPrice() const
{
	return loadCapacity/100;
}

Vehicle* Truck::clone() const
{
	return new Truck(*this);
}
