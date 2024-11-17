#ifndef _PARK_DATA_
#define _PARK_DATA_

#include <iostream>
#include <string>

#include "time.hpp"

class Vehicle {
private:
	std::string license_plate;
	std::string type;

public:
	Vehicle(std::string lp, std::string t);
};

class IORegistry {
private:
	Vehicle *information;
	Time	*entry;
	Time  	*exit;

public:
	IORegistry (Vehicle &v, Time &in);
	void setExitTime(Time &out);
};



#endif 		// _PARK_DATA_