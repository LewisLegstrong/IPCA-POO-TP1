#ifndef _PARK_
#define _PARK_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "time.hpp"
#include "vehicle_reg.hpp"

class Park {
public: 
    Park(int capacity);  //Constructor

private: 
	int maxCapacity;
	int currentVehicles;

	std::vector<IORegistry> parkedVehicles; 

public:
	void listVehicles();
	void newEntry (Vehicle &v, Time &in);
	void removeEntry(const std::string &licensePlate, Time &out);
	
    int getEmptySpots();
    int getOccupiedSpots();
	int getTimeSpentInPark(const std::string &licensePlate, Time &current) const;

	//void calculateTicket( std::string license	);
} ;

#endif 		// _PARK_
