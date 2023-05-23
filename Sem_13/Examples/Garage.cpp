#include "Garage.h"

void Garage::copyFrom(const Garage& other)
{
	for (int i = 0; i < other.vehicles.size(); i++)
	{
		vehicles.push_back(other.vehicles[i]->clone());
	}
}

void Garage::free()
{
	for (int i = 0; i < vehicles.size(); i++)
	{
		delete vehicles[i];
	}

	vehicles.clear();
}

Garage::Garage() : totalPrice(0)
{
}

Garage::Garage(const Garage& other)
{
	copyFrom(other);
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Garage::~Garage()
{
	free();
}

int Garage::getTotalPrice() const
{
	return totalPrice;
}

void Garage::addVehicle(const Vehicle const* vehilce)
{

	totalPrice += vehilce->getParkingPrice();
	vehicles.push_back(vehilce->clone());
}
