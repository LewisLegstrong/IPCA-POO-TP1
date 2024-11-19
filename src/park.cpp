#include "park.hpp"

void Park::listVehicles() {
    for (const IORegistry &unit : this->parkedVehicles) {
        std::cout << unit.getDetails() << std::endl;
    }
}

Park::Park(int capacity)
{
    maxCapacity = capacity;
    currentVehicles = 0;
}

void Park::newEntry(Vehicle &v, Time &in) {
    if (currentVehicles < maxCapacity) {
        IORegistry newRegistry(v, in);
        parkedVehicles.push_back(newRegistry);
        currentVehicles++;
    } else {
        std::cout << "Park is at full capacity!" << std::endl;
    }
}

void Park::removeEntry(const std::string &licensePlate) {
    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
        if (i->getVehicle()->getLicensePlate() == licensePlate){
            parkedVehicles.erase(i);
            currentVehicles--;
            std::cout << "Vehicle with license plate " << licensePlate << " has been removed." << std::endl;
            return;
        }
    }
    std::cout << "Vehicle with license plate " << licensePlate << " not found." << std::endl;
}

int Park::getEmptySpots() {
    return maxCapacity - currentVehicles;
}

int Park::getOccupiedSpots() {
    return currentVehicles;
}