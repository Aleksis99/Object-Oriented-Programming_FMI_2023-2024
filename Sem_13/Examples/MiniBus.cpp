#include "MiniBus.h"

MiniBus::MiniBus(std::string regNum, unsigned passengers, bool polite, unsigned loadCapacity, unsigned numDoors)
	: Vehicle(regNum), Car(regNum, passengers, polite), Truck(regNum, loadCapacity), numDoors(numDoors)
{
}

int MiniBus::getParkingPrice() const
{
	return (Truck::getParkingPrice() + Car::getParkingPrice()) / 2;
}

Vehicle* MiniBus::clone() const
{
	return new MiniBus(*this);
}
