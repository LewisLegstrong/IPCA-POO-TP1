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

void Park::removeEntry(const std::string &licensePlate, Time &out) {
    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
        if (i->getVehicle()->getLicensePlate() == licensePlate) {
            i->setExitTime(out); // Set the exit time
            std::cout << "Vehicle with license plate " << licensePlate << " has been removed at " 
                      << out.getHour() << ":" << out.getMinute() << ":" << out.getSeconds() << std::endl;
            parkedVehicles.erase(i);
            currentVehicles--;
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
void calculateTicket(std::string license) {
    float priceToPay = 0,0;

    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
        if (i->getVehicle()->getLicensePlate() == license) {
            int timeInPark = i->getExitTime() - i->getEntryTime();
            if (timeInPark < 60) {
                if ( i->getEntryTime()->getHour() < 8 && i->getExitTime()->getHour() > 20) {
                    priceToPay = (timeInPark/15) * 0,20;
            }
        }
    }
}