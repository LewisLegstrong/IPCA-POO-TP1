#include <iostream>
#include <sstream>
#include <string>

#include "time.hpp"
#include "date.hpp"
#include "vehicle_reg.hpp"
#include "park.hpp"

// void printV( std::vector<IORegistry> &v ) {
//     for (IORegistry unit : v) {
//         std::cout << unit.information->license_plate << " ";
//     }
//     std::cout << std::endl;
// }

// void printV(std::vector<IORegistry> &v) {
//     for (const IORegistry &unit : v) {
//         std::cout << unit.getVehicle()->getLicensePlate() << " ";
//     }
//     std::cout << std::endl;
// }

int main() {
    Park myPark(10);
    
    // Create a Vehicle object with the license plate
    std::string licensePlate = "ABC123";
    Vehicle myVehicle(licensePlate);

    // Create a Time object with the entry time (hours and minutes)
	Time entryTime(10, 30, 0);

    myPark.newEntry(myVehicle, entryTime);

//////////////////////////////////////////////////////////////////////
    // Create a Vehicle object with the license plate
    std::string licensePlate1 = "123ABC";
    Vehicle myVehicle1(licensePlate1);

    // Create a Time object with the entry time (hours and minutes)
	Time entryTime1(11, 30, 0);

    myPark.newEntry(myVehicle1, entryTime1);

//////////////////////////////////////////////////////////////////////
    
    myPark.listVehicles();
    std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;

    // Remove the vehicle from the park
    myPark.removeEntry(licensePlate);

    // List all vehicles in the park again
    myPark.listVehicles();

    // Print the number of empty and occupied spots again
    std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;

	return 0;
}