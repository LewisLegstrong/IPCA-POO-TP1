#include "vehicle_reg.hpp"

Vehicle::Vehicle(std::string lp) {
	this->license_plate = lp;
}

std::string Vehicle:: getLicensePlate() {
	return this->license_plate;
}

IORegistry::IORegistry(Vehicle &v, Time &in) {
	this->information = &v;
	this->entry = &in;
}

void IORegistry::setExitTime(Time &out) {
	this->exit = &out;
}

Vehicle* IORegistry::getVehicle() const {
    return information;
}


std::string IORegistry::getDetails() const { //Function to get the details of the vehicle
    std::ostringstream oss; //String stream to concatenate the information
    oss << "License Plate: " << information->getLicensePlate()
        << ", Entry Time: " << entry->getHour() << ":" << entry->getMinute();
    return oss.str();
}

int IORegistry::getTimeInPark(const Time &current) const {
    return current - *entry;
}
