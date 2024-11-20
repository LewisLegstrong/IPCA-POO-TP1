#include <iostream>
#include <sstream>
#include <string>

#include "time.hpp"
#include "date.hpp"
#include "vehicle_reg.hpp"
#include "park.hpp"
#include "file_manipulation.hpp"

int main() {
    // Create a Park object with a capacity of 10
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


    //Remove a vehicle from the park
    Time exitTime(12, 45, 0);
    myPark.removeEntry(licensePlate, exitTime);

    // List all vehicles in the park again
    myPark.listVehicles();

    // Print the number of empty and occupied spots again
    std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;


    //////////////////////////////////////////////////////////////////

    // writeNewFile("file.txt", "Matricula: ");
    // writeNewFile("carro.txt", "Marca: ");
    // appendToFile("file.txt", "69-CU-69");
    // appendToFile("carro.txt", "Ferrari");
    // readFile("file.txt");
    // readFile("carro.txt");


    // Time spent in the park
    Time actualHour (17, 30, 0);
    int timeSpent = myPark.getTimeSpentInPark(licensePlate1, actualHour);
    if (timeSpent != -1) {
        std::cout << "Vehicle with license plate " << licensePlate << " has been in the park for " << timeSpent << " minutes." << std::endl;
    }

	return 0;
}