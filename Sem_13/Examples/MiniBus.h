#pragma once
#include "Truck.h"
#include "Car.h"

class MiniBus : public Car, public Truck
{
private:
	unsigned numDoors;

public:

	MiniBus(std::string regNum, unsigned passengers, bool polite, unsigned loadCapacity, unsigned numDoors);
	int getParkingPrice() const override;
	Vehicle* clone() const override;
};

