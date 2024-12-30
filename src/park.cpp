#include "park.hpp"

Park::Park(int capacity, std::string parkLocation) {
    this->city = parkLocation;
    this->maxCapacity = capacity;
    this->currentVehicles = 0;
}

void Park::listVehicles() {
    for (IORegistry &unit : this->parkedVehicles) {
        std::cout << unit.getDetails() << std::endl;
    }
}

void Park::newEntry(Vehicle &v, DateTime &in) {
    if (currentVehicles < maxCapacity) {
        IORegistry newRegistry(v, in);
        parkedVehicles.push_back(newRegistry);
        currentVehicles++;
    } else {
        std::cout << "Park is at full capacity!" << std::endl;
    }
}

void Park::sumAccValue( float pricePaid ) {
    this->accumulatedValue += pricePaid;
}

void Park::consultHistoric(std::string licensePlate) {
    readFile(licensePlate);
}

void Park::removeEntry(const std::string &licensePlate, DateTime &out, bool subscriptionIsPaid) {
    std::cout << "Dentro do remove entry " << std::endl;
    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
        std::cout << "Dentro do for remove entry " << std::endl;
        out.outputTime();
        if (i->getVehicle().getLicensePlate() == licensePlate) {
            std::cout << "Dentro do if do remove entry antes do exit time " << std::endl;
            out.outputTime();
            i->setExitTime(out, subscriptionIsPaid); // Set the exit time
            std::cout << "Vehicle with license plate " << licensePlate << " has been removed at " 
                      << out.getHour() << ":" << out.getMinute() << ":" << out.getSeconds() << std::endl;
            sumAccValue(i->getPricePaid());
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

int Park::getMaxCapacity() const {
    return maxCapacity;
}

int Park::getTimeSpentInPark(const std::string &licensePlate, DateTime &current) const{
    for (auto unit : parkedVehicles) {
        if (unit.getVehicle().getLicensePlate() == licensePlate) {
            return unit.getTimeInPark(current);
        }
    }
    std::cerr << "Vehicle with license plate " << licensePlate << " not found." << std::endl;
    return -1;
}

bool Park::isParked(std::string &licensePlate) {
    for ( auto unit : parkedVehicles ) {
        if (unit.getVehicle().getLicensePlate() == licensePlate)
            return true;
    }
    return false;
}

float Park::getAccValue() {
    return this->accumulatedValue;
}

float Park::getSimulatedPriceToReceive( DateTime &simulatedTime ) {
    float toBeReceivedSim = 0.0;

    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) { 
        std::cout << "IM IN " << std::endl;
        toBeReceivedSim += i->simCalculateTicket( simulatedTime );
    }

    return toBeReceivedSim;
}

std::string Park::getCity() const {
    return city;
}





GestPark::GestPark() {
    // Constructor implementation
}

void GestPark::listAllVehicles() {
    for (Park& park : availableParks) {
        std::cout << "Vehicles in park at " << park.getCity() << ":" << std::endl;
        park.listVehicles();
    }
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

void GestPark::registerMonthlySubscription( std::string customerName, std::string lp, int nif, bool isPaidForCurrentMonth) {
    Subscription newSubscription( customerName, lp, nif, isPaidForCurrentMonth );
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

bool GestPark::hasActiveSubscription(std::string licensePlate) {
    for (const auto& subscription : subscriptions) {
        if (subscription.getLicensePlate() == licensePlate && subscription.getIsPaidForCurrentMonth()) {
            return true;
        }
    }
    return false;
}

bool GestPark::getParkInCity(const std::string& city) {
    for (Park& park : availableParks) {
        if (park.getCity() == city) {
            return true;
        }
    }
    return false;
}

void GestPark::findAndRemoveVehicle( std::string& licensePlate, DateTime &exitTime ) {
    exitTime.outputTime();
    for ( auto park = availableParks.begin(); park != availableParks.end(); park++) {
        std::cout << "Dentro do for " << std::endl;
        exitTime.outputTime();
        if (park->isParked(licensePlate)) {
            std::cout << "Dentro do if " << std::endl;
            exitTime.outputTime();
            hasActiveSubscription(licensePlate) ? park->removeEntry(licensePlate, exitTime, true) :
                                                  park->removeEntry(licensePlate, exitTime, false );
            std::cout << "Fim if " << std::endl;
            exitTime.outputTime();
            break;
        }
    }
}

void GestPark::findAndAddVehicle ( std::string city, Vehicle &v, DateTime &in ) {
    for ( auto park = availableParks.begin(); park != availableParks.end(); park++) {
        if (park->getCity() == city) {
            park->newEntry ( v, in );    
        break;
        }
    }
}

GestPark::~GestPark() {
    // Destructor implementation
}
