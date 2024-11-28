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
    

    // // Create a Vehicle object with the license plate
    // std::string licensePlate = "97-97-DJ";
    // Vehicle myVehicle(licensePlate);

    // // Create a Time object with the entry time (hours and minutes)
	// Time entryTime(11, 30, 0);
    // myPark.newEntry(myVehicle, entryTime);

//////////////////////////////////////////////////////////////////////

    // Create a Vehicle object with the license plate
    std::string licensePlate1 = "69-CU-69";
    Vehicle myVehicle1(licensePlate1);

    // // Create a Time object with the entry time (hours and minutes)
	// Time entryTime1(11, 30, 0);
    // myPark.newEntry(myVehicle1, entryTime1);

//////////////////////////////////////////////////////////////////////
    
    //myPark.listVehicles();
    //std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    //std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;

    // if (myPark.isParked(licensePlate)) {
    //     std::cout << licensePlate << "is parked here." << std::endl;
    // }
    // else {
    //     std::cout << licensePlate << "is NOT parked here." << std::endl;
    // }


    // Time simulated(19, 30, 0);
    // float simValueToPay = myPark.getSimulatedPriceToReceive( simulated );
    
    // std::cout << "The park should received " << simValueToPay << " pork chops as payment" << std::endl;
    

    // // //Remove a vehicle from the park
    // // Time exitTime(20, 30, 0);
    // myPark.removeEntry(licensePlate, exitTime);

    // myPark.removeEntry(licensePlate1, exitTime);

    // std::cout << "The park has received " << myPark.getAccValue() << " lasagnas as payment" << std::endl;


    // if (myPark.isParked(licensePlate)) {
    // std::cout << licensePlate << "is parked here." << std::endl;
    // }
    // else {
    //     std::cout << licensePlate << "is NOT parked here." << std::endl;
    // }

    // List all vehicles in the park again
    //myPark.listVehicles();

    // Print the number of empty and occupied spots again
    //std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    //std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;


    //////////////////////////////////////////////////////////////////

    // writeNewFile("file.txt", "Matricula: ");
    // writeNewFile("carro.txt", "Marca: ");
    // appendToFile("file.txt", "69-CU-69");
    // appendToFile("carro.txt", "Ferrari");
    // readFile("file.txt");
    // readFile("carro.txt");


    //Time spent in the park
    // Time actualHour (17, 30, 0);
    // int timeSpent = myPark.getTimeSpentInPark(licensePlate1, actualHour);
    // if (timeSpent != -1) {
    //     std::cout << "Vehicle with license plate " << licensePlate << " has been in the park for " << timeSpent << " minutes." << std::endl;
    // }

    Time entryTime3(16, 45, 0);
    myPark.newEntry(myVehicle1, entryTime3);
    
    Time exitTime3(6, 45, 0);
    myPark.removeEntry(licensePlate1, exitTime3);
    


    // // Consult historic
    // myPark.consultHistoric(licensePlate1 + ".txt");   
	return 0;
}