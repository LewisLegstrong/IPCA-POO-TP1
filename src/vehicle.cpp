#include "vehicle.hpp"


Vehicle::Vehicle(std::string lp) {
	this->license_plate = lp;
}

std::string Vehicle::getLicensePlate() {
	return this->license_plate;
}

