#ifndef _PARK_DATA_
#define _PARK_DATA_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "dateTime.hpp"
#include "vehicle.hpp"
#include "file_manipulation.hpp"

/// @brief Enum class to define the period of the day the car is parked
enum class parkPeriod {   // enforces type
	DAY,
	EVENING,
	MIXED
}; 

/// @brief Class to define the vehicle registry in the park
class IORegistry {
public:
	/// @brief Constructor
	IORegistry (Vehicle &v, dateTime &in);

private:
	Vehicle *information;
	dateTime	*entry;
	dateTime  	*exit;
	float 	priceToPay;

public:
	/// @brief Set the exit time of the vehicle
	void setExitTime(dateTime &out);

	/// @brief Calculates the ticket price
	/// @details Calculates the ticket price based on the parked time and the period of the day
	/// @return void
	void calculateTicket();

	/// @brief Creates the string that will go the history file
	void writeToFile();

	int getTimeInPark(dateTime &current);

	/// @brief get the parked time
	/// @return parked time in minutes 
	int getParkedTime();

	/// @brief get the entry time
	/// @return entry time converted in minutes
	int getEntryTime();

	/// @brief get the exit time
	/// @return exit time converted in minutes
	int getExitTime();

	/// @brief Calculate value to pay for the ticket if an exit time is given
	/// @param exitTimeSimulated 
	/// @return 
	float simCalculateTicket( dateTime &exitTimeSimulated );

	/// @brief get the price paid
	float getPricePaid();

	/// @brief 		Returns the details of the vehicle as well as entry time registered in the object IORegistry
	std::string getDetails() const;

	/// @brief 			Returns the period of the day the car is parked
	/// @return State used to assist in the calculation of the ticket price 
	parkPeriod getParkPeriod();
	parkPeriod simGetParkPeriod( int exitTimeSimulated ); 

	/// @brief 		Returns the vehicle registered in the object IORegistry
	/// @return 		Vehicle registered in the object IORegistry
	Vehicle* getVehicle() const; 

};

#endif 		// _PARK_DATA_