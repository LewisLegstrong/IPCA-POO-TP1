#ifndef _PARK_DATA_
#define _PARK_DATA_

#include <iostream>
#include <string>

#include "time.hpp"

class Registration {
private:
	Time	*entry;
	Time  	*exit;

public:
	Registration (Time &in);
	void setExitTime(Time &out);
};

class Vehicle:Registration {
private:
	std::string license_plate;
	std::string type;

public:
	Vehicle(std::string lp, std::string t);
};

#endif	// PARK_DATA