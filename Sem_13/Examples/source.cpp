#include <iostream>
#include <fstream>
#include "Garage.h"

int main()
{
    Garage g;

    Car c("asd", 5, 1);
    Truck t("asd", 500);
    MiniBus m("asd", 5, 1, 500, 5);

    g.addVehicle(&c);
    g.addVehicle(&t);
    g.addVehicle(&m);

    std::cout << g.getTotalPrice();

    return 0;
}
