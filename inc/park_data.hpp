#ifndef _PARK_DATA_
#define _PARK_DATA_

#include <iostream>
#include <string>
#include <vector>

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
	const Vehicle *information;
	Time	*entry;
	Time  	*exit;

public:
	IORegistry (Vehicle &v, Time &in);
	void setExitTime(Time &out);
};

class Park {
private: 
	int maxCapacity;
	int currentVehicles;

	std::vector<IORegistry> parkedVehicles; 
public: 
	
} ;

#endif 		// _PARK_DATA_