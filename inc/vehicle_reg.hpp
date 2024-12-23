#ifndef _PARK_DATA_
#define _PARK_DATA_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "time.hpp"
#include "file_manipulation.hpp"

/// @brief Enum class to define the period of the day the car is parked
enum class parkPeriod {   // enforces type
	DAY,
	EVENING,
	MIXED
}; 


/// @brief Class to define the vehicle
class Vehicle {
public:
	/// @brief 		Constructor
	/// @param lp -> License plate of the vehicle 
	Vehicle(std::string lp);

private:
	std::string license_plate;

public:
	/// @brief 		Returns the license plate of the vehicle registered in the object Vehicle
	/// @return 	License plate of the vehicle
	std::string getLicensePlate();
};


/// @brief Class to define the vehicle registry in the park
class IORegistry {
public:
	/// @brief Constructor
	IORegistry (Vehicle &v, Time &in);

private:
	Vehicle *information;
	Time	*entry;
	Time  	*exit;
	float 	priceToPay;

public:
	/// @brief Set the exit time of the vehicle
	void setExitTime(Time &out);

	/// @brief 			Returns the period of the day the car is parked
	/// @return State used to assist in the calculation of the ticket price 
	parkPeriod getParkPeriod();
	parkPeriod simGetParkPeriod( int exitTimeSimulated ); 

	/// @brief Calculates the ticket price
	/// @details Calculates the ticket price based on the parked time and the period of the day
	/// @return void
	void calculateTicket();
	float simCalculateTicket( Time &exitTimeSimulated );

// Get data functions
	/// @brief 		Returns the vehicle registered in the object IORegistry
	/// @return 		Vehicle registered in the object IORegistry
	Vehicle* getVehicle() const; 

	/// @brief 		Returns the details of the vehicle as well as entry time registered in the object IORegistry
	std::string getDetails() const;

	int getTimeInPark(Time &current);

	/// @brief get the parked time
	/// @return parked time in minutes 
	int getParkedTime();

	/// @brief get the entry time
	/// @return entry time converted in minutes
	int getEntryTime();

	/// @brief get the exit time
	/// @return exit time converted in minutes
	int getExitTime();

	/// @brief get the price paid
	float getPricePaid();

	/// @brief Creates the string that will go the history file
	void writeToFile();
};

#endif 		// _PARK_DATA_