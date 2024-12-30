#include "vehicle.hpp"


Vehicle::Vehicle( std::string lp) : license_plate( lp ) {}

std::string Vehicle::getLicensePlate() {
	return this->license_plate;
}

