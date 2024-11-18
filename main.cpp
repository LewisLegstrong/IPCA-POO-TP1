#include <iostream>
#include <sstream>
#include <string>

#include "time.hpp"
#include "date.hpp"
#include "vehicle_reg.hpp"
#include "park.hpp"
#include "file_manipulation.hpp"

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
    Park myPark;

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

    //////////////////////////////////////////////////////////////////

    writeNewFile("file.txt", "Matricula: ");
    writeNewFile("carro.txt", "Marca: ");
    appendToFile("file.txt", "69-CU-69");
    appendToFile("carro.txt", "Ferrari");
    readFile("file.txt");
    readFile("carro.txt");

	return 0;
}