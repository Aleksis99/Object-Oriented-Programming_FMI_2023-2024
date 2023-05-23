#pragma once
#include "Vehicle.h"

class Car : virtual public Vehicle
{
private:
	unsigned passengers;
	bool polite;

public:

	Car(std::string regNum, unsigned passengers, bool polite);
	int getParkingPrice() const override;
	Vehicle* clone() const override;
};

