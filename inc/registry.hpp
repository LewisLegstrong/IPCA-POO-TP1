#ifndef _PARK_DATA_
#define _PARK_DATA_

#define _8H_IN_SECONDS 480 * 60
#define _20H_IN_SECONDS 1200 * 60

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
	IORegistry (Vehicle &v, DateTime &in);

private:
	float 		priceToPay;
	Vehicle		information;
	DateTime	entry;
	DateTime 	exit;
	
public:
	/// @brief 			Set the exit time of the vehicle. Calls for the calculation of the ticket price and writes to the history file 
	void setExitTime( DateTime &out , bool subscriptionIsPaid );

	/// @brief 			Calculates the ticket price 
	/// @details 		Calculates the ticket price based on the parked time and the period of the day
	void calculateTicket();

	/// @brief 			Creates the string that will go the history file
	void writeToFile();

	/// @brief 			Get the current parking time
	/// @return 		Price paid for the ticket
	int getTimeInPark(DateTime &current);

	/// @brief 			get the parked time
	/// @return 		parked time in seconds using overloaded operator (-) from DateTime Class
	int getParkedTime();

	/// @brief 			get the entry time
	/// @return 		entry time converted in minutes
	int getEntryTime();

	/// @brief 			get the exit time
	/// @return 		exit time converted in minutes
	int getExitTime(); 

	/// @brief 			Calculate value to pay for the ticket if an exit time is given, Overloads the calculateTicket() function if a parameter is given
	/// @param 			exitTimeSimulated 
	/// @return 		Price to pay for the ticket
	float simCalculateTicket( DateTime &exitTimeSimulated );

	/// @brief 			get the price paid
	float getPricePaid();

	/// @brief 			Calculate the value to pay for the ticket if the car is parked for 24h
	/// @param 			exitTime
	/// @return 		Price to pay for the ticket
	float calculate24hValue( int exitTime );

	/// @brief 			Returns the details of the vehicle as well as entry time registered in the object IORegistry
	std::string getDetails();

	/// @brief 			Returns the period of the day the car is parked
	/// @return 		State used to assist in the calculation of the ticket price 
	parkPeriod getParkPeriod();

	/// @brief 			Returns the period of the day the car is parked, Overloads the getParkPeriod() function if a parameter is given
	/// @param 			exitTimeSimulated 
	/// @return 		State used to assist in the calculation of the ticket price
	parkPeriod simGetParkPeriod( int exitTimeSimulated ); 

	/// @brief 			Returns the reference to the vehicle registered in the object IORegistry
	/// @return 		Vehicle registered in the object IORegistry
 	Vehicle& getVehicle();

};

#endif 		// _PARK_DATA_