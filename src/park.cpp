#include "park.hpp"

void Park::listVehicles() {
    for (const IORegistry &unit : this->parkedVehicles) {
        std::cout << unit.getDetails() << std::endl;
    }
}

Park::Park(int capacity, std::string parkLocation)
{
    this->city = parkLocation;
    this->maxCapacity = capacity;
    this->currentVehicles = 0;
}

// void Park::newEntry(Vehicle &v, DateTime &in) {
//     if (currentVehicles < maxCapacity) {
//         IORegistry newRegistry(v, in);
//         parkedVehicles.push_back(newRegistry);
//         currentVehicles++;
//     } else {
//         std::cout << "Park is at full capacity!" << std::endl;
//     }
// }


// void Park::removeEntry(const std::string &licensePlate, Time &out) {
//     for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
//         if (i->getVehicle()->getLicensePlate() == licensePlate) {
//             i->setExitTime(out); // Set the exit time
//             std::cout << "Vehicle with license plate " << licensePlate << " has been removed at " 
//                       << out.getHour() << ":" << out.getMinute() << ":" << out.getSeconds() << std::endl;
//             sumAccValue( i->getPricePaid() );
//             parkedVehicles.erase(i);
//             currentVehicles--;
//             return;
//         }
//     }
//     std::cout << "Vehicle with license plate " << licensePlate << " not found." << std::endl;
// }

int Park::getEmptySpots() {
    return maxCapacity - currentVehicles;
}

int Park::getOccupiedSpots() {
    return currentVehicles;
}

// int Park::getTimeSpentInPark(const std::string &licensePlate, Time &current) const{
//     for (auto unit : parkedVehicles) {
//         if (unit.getVehicle()->getLicensePlate() == licensePlate) {
//             return unit.getTimeInPark(current);
//         }
//     }
//     std::cerr << "Vehicle with license plate " << licensePlate << " not found." << std::endl;
//     return -1;
// }

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

// float Park::getSimulatedPriceToReceive( Time &simulatedTime ) {
//     float toBeReceivedSim = 0.0;

//     for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) { 
//         std::cout << "IM IN " << std::endl;
//         toBeReceivedSim += i->simCalculateTicket( simulatedTime );
//     }

//     return toBeReceivedSim;
// }

void Park::consultHistoric(std::string licensePlate) {
    readFile(licensePlate);
}



GestPark::GestPark() {
    // Constructor implementation
}

GestPark::~GestPark() {
    // Destructor implementation
}


std::string Park::getCity() const {
    return city;
}

int Park::getMaxCapacity() const {
    return maxCapacity;
}


void GestPark::insertParkInCity( std::string city, int capacity ) {

    Park newPark(capacity, city);
    availableParks.push_back(newPark);

    std::cout << "Park inserted in " << city << " with capacity " << capacity << std::endl;
}

void GestPark::listParksInCity(std::string city) {
    std::cout << "Park of " << city << ":" << std::endl;
    bool parkFound = false;
    for (const auto& park : availableParks) {
        if (park.getCity() == city) {
            std::cout << "Park with capacity: " << park.getMaxCapacity() << std::endl;
            parkFound = true;
        }
    }
    if (!parkFound) {
        std::cout << "No park in " << city << std::endl;
    }
}

void GestPark::printAvailableParks() {
    std::cout << "Available parks:" << std::endl;
    for (const auto& park : availableParks) {
        std::cout << "City: " << park.getCity() << ", Capacity: " << park.getMaxCapacity() << std::endl;
    }
}

std::string GestPark::paymentsReceivedByClient(int nif) {
    std::ostringstream oss;
    for (const auto& subscription : subscriptions) {
        if (subscription.getNIF() == nif) {
            oss << "Customer: " << subscription.getCustomerName() << ", License Plate: " << subscription.getLicensePlate()
                << ", Paid for Current Month: " << (subscription.getIsPaidForCurrentMonth() ? "Yes" : "No") << std::endl;
        }
    }
    return oss.str();
}

void GestPark::registerMonthlySubscription(std::string customerName, int nif, std::string licensePlate, bool isPaidForCurrentMonth) {
    Subscription newSubscription(customerName, nif, licensePlate, isPaidForCurrentMonth);
    subscriptions.push_back(newSubscription);
}

void GestPark::updateSubscriptionPaymentStatus(std::string licensePlate, bool isPaidForCurrentMonth) {
    for (auto& subscription : subscriptions) {
        if (subscription.getLicensePlate() == licensePlate) {
            subscription.setIsPaidForCurrentMonth(isPaidForCurrentMonth);
            break;
        }
    }
}

bool GestPark::hasActiveSubscription(std::string licensePlate) {
    for (const auto& subscription : subscriptions) {
        if (subscription.getLicensePlate() == licensePlate && subscription.getIsPaidForCurrentMonth()) {
            return true;
        }
    }
    return false;
}
