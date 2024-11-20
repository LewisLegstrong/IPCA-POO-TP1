#ifndef _PARK_DATA_
#define _PARK_DATA_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "time.hpp"


class Vehicle {
private:
	std::string license_plate;
	std::string type;

public:
	Vehicle(std::string lp);
	std::string getLicensePlate();
};

class IORegistry {
private:
	Vehicle *information;
	Time	*entry;
	Time  	*exit;

public:
	IORegistry (Vehicle &v, Time &in);
	void setExitTime(Time &out);
	Vehicle* getVehicle() const; 
	std::string getDetails() const;
	int getTimeInPark(const Time &current) const;
};

#endif 		// _PARK_DATA_