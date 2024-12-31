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
    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
        if (i->getVehicle().getLicensePlate() == licensePlate) {
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
    for (auto& park : availableParks) {
        if (park.getCity() == city) {
            std::cout << "Park with max capacity: " << park.getMaxCapacity() 
                      << ", current live capacity: " << park.getEmptySpots() << std::endl;
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

void GestPark::registerMonthlySubscription( std::string customerName, std::string lp, int nif, int month, bool isPaidForCurrentMonth) {
    Subscription newSubscription( customerName, lp, nif, month, isPaidForCurrentMonth );
    subscriptions.push_back(newSubscription);
}

void GestPark::updateSubscriptionPaymentStatus(std::string licensePlate, int month, bool isPaidForCurrentMonth) {
    for (auto& subscription : subscriptions) {
        if (subscription.getLicensePlate() == licensePlate && subscription.getMonth() == month) {
            subscription.setIsPaidForCurrentMonth(isPaidForCurrentMonth);
            break;
        }
    }
}

std::string GestPark::paymentsReceivedByClient(int nif, int month) {
    std::ostringstream oss;
    for (auto& subscription : subscriptions) {
        if (subscription.getNIF() == nif && subscription.getMonth() == month) {
            oss << "Customer: " << subscription.getCustomerName() << ", License Plate: " << subscription.getLicensePlate()
                << ", Paid for Month " << month << ": " << (subscription.getIsPaidForCurrentMonth() ? "Yes" : "No") << std::endl;
        }
    }
    return oss.str();
}

bool GestPark::hasActiveSubscription(std::string licensePlate, int month) {
    for (auto& subscription : subscriptions) {
        if (subscription.getLicensePlate() == licensePlate && subscription.getMonth() == month && subscription.getIsPaidForCurrentMonth()) {
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

std::string GestPark::findCityVehicleIsParked( std::string& licensePlate) {
    for (auto& park : availableParks) {
        if (park.isParked(licensePlate)) {
            return park.getCity();
        }
    }
    return "Vehicle not found in any park.";
}

void GestPark::findAndRemoveVehicle(std::string& licensePlate, DateTime& exitTime) {
    for (auto park = availableParks.begin(); park != availableParks.end(); park++) {
        if (park->isParked(licensePlate)) {
            int currentMonth = exitTime.getMonth(); // Get the current month
            hasActiveSubscription(licensePlate, currentMonth) ? park->removeEntry(licensePlate, exitTime, true) :
                                                                park->removeEntry(licensePlate, exitTime, false);
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
