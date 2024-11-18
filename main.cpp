#include <iostream>
#include <sstream>
#include <string>

#include "time.hpp"
#include "date.hpp"
#include "park_data.hpp"

// void printV( std::vector<IORegistry> &v ) {
//     for (IORegistry unit : v) {
//         std::cout << unit.information->license_plate << " ";
//     }
//     std::cout << std::endl;
// }

int main() {
	Vehicle v("aa-bb-cc");
    // Create a Vehicle object with the license plate
    std::string licensePlate = "ABC123";
    Vehicle myVehicle(licensePlate);

    // Create a Time object with the entry time (hours and minutes)
	Time entryTime(10, 30, 0);


    // Create an IORegistry object using the Vehicle and Time objects
    IORegistry myRegistry(myVehicle, entryTime);

    // Create a vector to store IORegistry objects
    std::vector<IORegistry> vehicles;

    // Add the IORegistry object to the vector
    vehicles.push_back(myRegistry);

    std::cout << myVehicle.getLicensePlate() << std::endl;
    // printV(vehicles);

	return 0;
}