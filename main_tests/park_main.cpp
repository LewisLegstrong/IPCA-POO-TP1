#include "park.hpp"
#include "vehicle_reg.hpp"
#include "time.hpp"
#include <iostream>

int main() {

    Park myPark(10);
    std::string licensePlate1 = "97-97-DJ";
    std::string licensePlate2 = "69-CU-69";
    Vehicle hondaCivic(licensePlate1);
    Vehicle bmwE46(licensePlate2);

    // List all vehicles in the park
    std::cout << "List of the park when it's still empty." << std::endl;
    myPark.listVehicles();
    // Print the number of empty and occupied spots
    std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;

    if (myPark.isParked(licensePlate1)) {
        std::cout << licensePlate1 << "is parked here." << std::endl;
    }
    else {
        std::cout << licensePlate1 << "is NOT parked here." << std::endl;
    }

    // Create a Time object with the entry time (hours and minutes)
	Time entryTime1(11, 30, 0);
    Time entryTime2(15, 45, 0);    
    myPark.newEntry(hondaCivic, entryTime1);
    myPark.newEntry(bmwE46, entryTime2);

    // Simulated time in the park
    std::cout << "Simulated value of the time that the car have been in the park." << std::endl;
    Time simulated(19, 30, 0);
    float simValueToPay = myPark.getSimulatedPriceToReceive( simulated );

    // List all vehicles in the park again
     std::cout << "List of the park when it's occupied." << std::endl;
    myPark.listVehicles();

    // Print the number of empty and occupied spots again
    std::cout << "Empty spots: " << myPark.getEmptySpots() << std::endl;
    std::cout << "Occupied spots: " << myPark.getOccupiedSpots() << std::endl;

    // //Remove a vehicle from the park
    Time exitTime1(20, 30, 0);
    Time exitTime2(23, 15, 0);
    myPark.removeEntry(licensePlate1, exitTime1);
    myPark.removeEntry(licensePlate2, exitTime2);

    std::cout << "The park has received " << myPark.getAccValue() << " lasagnas as payment" << std::endl;

    if (myPark.isParked(licensePlate1)) {
    std::cout << licensePlate1 << "is parked here." << std::endl;
    }
    else {
        std::cout << licensePlate1 << "is NOT parked here." << std::endl;
    }

    // Time spent in the park
    std::cout << "Time spent in park." << std::endl;
    Time actualHour (17, 30, 0);
    int timeSpent = myPark.getTimeSpentInPark(licensePlate2, actualHour);
    if (timeSpent != -1) {
        std::cout << "Vehicle with license plate " << licensePlate1 << " has been in the park for " << timeSpent << " minutes." << std::endl;
    }

    // Create a Time object with the entry time (hours and minutes)
    std::cout << "Create a Time object with the entry time." << std::endl;
	Time entryTime3(11, 30, 0);
    myPark.newEntry(hondaCivic, entryTime3);

    // Consult historic
    std::cout << "Consults historic." << std::endl;
    myPark.consultHistoric(licensePlate2 + ".txt");
    myPark.removeEntry(licensePlate2, exitTime2);

    return 0;
}