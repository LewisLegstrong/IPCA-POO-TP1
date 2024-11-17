#include "../inc/park_data.hpp"

Vehicle::Vehicle(std::string lp, std::string t) {
	this->license_plate = lp;
	this->type = t;
}

IORegistry::IORegistry(Vehicle &v, Time &in) {
	this->information = &v;
	this->entry = &in;
}

void IORegistry::setExitTime(Time &out) {
	this->exit = &out;
}