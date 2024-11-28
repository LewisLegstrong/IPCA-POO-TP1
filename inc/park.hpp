#ifndef _PARK_
#define _PARK_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "time.hpp"
#include "vehicle_reg.hpp"
#include "file_manipulation.hpp"

class Park {
public: 
    Park(int capacity);  //Constructor

private: 
	int maxCapacity;
	int currentVehicles;
	float accumulatedValue = 0.0 ;

	std::vector<IORegistry> parkedVehicles; 

public:
	void listVehicles();
	void newEntry (Vehicle &v, Time &in);
	void removeEntry(const std::string &licensePlate, Time &out);
	void sumAccValue( float pricePaid );

    int getEmptySpots();
    int getOccupiedSpots();
	int getTimeSpentInPark(const std::string &licensePlate, Time &current) const;

	bool isParked(std::string &licensePlate);
	
	float getAccValue();
	float getSimulatedPriceToReceive( Time &simulatedTime );
	void consultHistoric(std::string licensePlate);
} ;

#endif 		// _PARK_
