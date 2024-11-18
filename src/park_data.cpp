#include "park_data.hpp"

Vehicle::Vehicle(std::string lp) {
	this->license_plate = lp;
}





IORegistry::IORegistry(Vehicle &v, Time &in) {
	this->information = &v;
	this->entry = &in;
}

void IORegistry::setExitTime(Time &out) {
	this->exit = &out;
}