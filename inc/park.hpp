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
    /// @brief Park constructor, meant to initialize a park retaining it's location and capacity
    /// @param capacity 
    /// @param parkLocation 
    Park(int capacity, std::string parkLocation);  //Constructor

private: 
	int maxCapacity;
	int currentVehicles;
	float accumulatedValue = 0.0 ;
	std::string city;
	std::vector<IORegistry> parkedVehicles; 

public:
	/// @brief list the vehicles parked in the park
	void listVehicles();

	/// @brief register a new vehicle in the park, saves information about time of entry and vehicle
	/// @param v 
	/// @param in 
	void newEntry (Vehicle &v, Time &in);

	/// @brief remove a vehicle from the park, saves information about time of exit and vehicle and removes the registry from the parkedVehicles vector
	/// @param licensePlate
	/// @param out
	void removeEntry(const std::string &licensePlate, Time &out);
	
	/// @brief sum the value paid by the vehicle to the accumulated value of the park
	/// @param pricePaid
	void sumAccValue( float pricePaid );
	
	/// @brief consult the history of a vehicle in the park
	/// @param licensePlate 
	void consultHistoric( std::string licensePlate );

	/// @brief Verifies the number of empty spots in the park
	/// @return 
	int getEmptySpots();
    
	/// @brief Verifies the number of occupied spots in the park
	int getOccupiedSpots();
	
	/// @brief Verifies the time spent in the park by a vehicle
	/// @param licensePlate 
	/// @param current 
	/// @return 
	int getTimeSpentInPark(const std::string &licensePlate, Time &current) const;

	/// @brief Verifies if a vehicle is parked in the park
	bool isParked(std::string &licensePlate);

	/// @brief obtain the accumulated value of the park 
	float getAccValue();
	
	/// @brief Calculate a simulated price to receive from a vehicle at a simulated exit time
	float getSimulatedPriceToReceive( Time &simulatedTime );
} ;

#endif 		// _PARK_
