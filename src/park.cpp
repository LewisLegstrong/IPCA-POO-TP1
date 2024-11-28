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
            sumAccValue( i->getPricePaid() );
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

int Park::getTimeSpentInPark(const std::string &licensePlate, Time &current) const{
    for (auto unit : parkedVehicles) {
        if (unit.getVehicle()->getLicensePlate() == licensePlate) {
            return unit.getTimeInPark(current);
        }
    }
    std::cerr << "Vehicle with license plate " << licensePlate << " not found." << std::endl;
    return -1;
}

void Park::sumAccValue( float pricePaid ) {
    this->accumulatedValue += pricePaid;
}

bool Park::isParked(std::string &licensePlate) {
    for ( auto unit : parkedVehicles ) {
        if (unit.getVehicle()->getLicensePlate() == licensePlate)
            return true;
    }
    return false;
}

float Park::getAccValue() {
    return this->accumulatedValue;
}

float Park::getSimulatedPriceToReceive( Time &simulatedTime ) {
    float toBeReceivedSim = 0.0;

    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) { 
        std::cout << "IM IN " << std::endl;
        toBeReceivedSim += i->simCalculateTicket( simulatedTime );
    }

    return toBeReceivedSim;
}

void Park::consultHistoric(std::string licensePlate) {
    readFile(licensePlate);
}