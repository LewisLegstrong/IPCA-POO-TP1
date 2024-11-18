#include "park.hpp"

void Park::listVehicles() {
    for (const IORegistry &unit : this -> parkedVehicles) {
        std::cout << unit.getDetails() << std::endl;
    }
}

void Park::newEntry(Vehicle &v, Time &in) {
	IORegistry newRegistry(v, in);
	this->parkedVehicles.push_back(newRegistry);
}