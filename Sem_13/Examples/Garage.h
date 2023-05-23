#pragma once
#include<vector>
#include "MiniBus.h"

class Garage
{
private:
	int totalPrice;
	std::vector<Vehicle*> vehicles;

	void copyFrom(const Garage& other);
	void free();

public:

	Garage();
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	~Garage();

	int getTotalPrice() const;
	void addVehicle(const Vehicle const* vehilce);
};

