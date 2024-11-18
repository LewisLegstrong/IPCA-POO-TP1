#ifndef _PARK_
#define _PARK_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "time.hpp"
#include "vehicle_reg.hpp"

class Park {
private: 
	int maxCapacity;
	int currentVehicles;

	std::vector<IORegistry> parkedVehicles; 
public: 
	void listVehicles();
	void newEntry (Vehicle &v, Time &in);
} ;

#endif 		// _PARK_
