#ifndef _PARK_
#define _PARK_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "vehicle.hpp"
#include "registry.hpp"
#include "file_manipulation.hpp"
#include "monthlyParkSubscription.hpp"




class Park {
public: 
    /// @brief Park constructor, meant to initialize a park retaining it's location and capacity
    /// @param capacity 
    /// @param parkLocation 
    Park(int capacity, std::string parkLocation);  //Constructor

private: 
	int maxCapacity;
	int currentVehicles;
	float accumulatedValue = 0.0;
	std::string city;
	std::vector<IORegistry> parkedVehicles; 

public:
    /// @brief get the city where the park is located
    std::string getCity() const;

    /// @brief get the maximum capacity of the park
    int getMaxCapacity() const;

	/// @brief list the vehicles parked in the park
	void listVehicles( );

	/// @brief register a new vehicle in the park, saves information about time of entry and vehicle
	/// @param v 
	/// @param in 
	void newEntry ( Vehicle &v, DateTime &in );

	/// @brief remove a vehicle from the park, saves information about time of exit and vehicle and removes the registry from the parkedVehicles vector
	/// @param licensePlate
	/// @param out
	void removeEntry ( const std::string &licensePlate, DateTime &out, bool subscriptionIsPaid );
	
	/// @brief sum the value paid by the vehicle to the accumulated value of the park
	/// @param pricePaid
	void sumAccValue ( float pricePaid );

	/// @brief Verifies the number of empty spots in the park
	/// @return 
	int getEmptySpots ( );
    
	/// @brief Verifies the number of occupied spots in the park
	int getOccupiedSpots ( );
	
	/// @brief Verifies the time spent in the park by a vehicle
	/// @param licensePlate 
	/// @param current 
	/// @return time in minutes
	int getTimeSpentInPark ( const std::string &licensePlate, DateTime &current ) const;

	/// @brief Verifies if a vehicle is parked in the park
	bool isParked ( std::string &licensePlate );

	/// @brief obtain the accumulated value of the park 
	float getAccValue ( );
	
	/// @brief Calculate a simulated price to receive from a vehicle at a simulated exit time
	/// @return The price to be paid by the vehicle
	float getSimulatedPriceToReceive ( DateTime &simulatedTime );


} ;


class GestPark {
public:
	/// @brief GestPark constructor, meant to initialize a park retaining it's location and capacity
	GestPark( );
	/// @brief GestPark destructor
	~GestPark( );

private:
	std::vector<Park> availableParks;
	std::vector<Subscription> subscriptions;
	
public:
	/// @brief Insert a new park in the city
	/// @param city 
	/// @param capacity 
	void insertParkInCity ( std::string city, int capacity );

	/// @brief  List all parks in a city
	/// @param city 
	void listParksInCity ( std::string city );

	/// @brief Print all available parks
    void printAvailableParks();

	void listAllVehicles(); 

	/// @brief Register a new vehicle in the park
	bool getParkInCity(const std::string& city);

	/// @brief Find the city where a vehicle is parked
	/// @param licensePlate
 	std::string findCityVehicleIsParked(std::string& licensePlate);

	// Return the history of a vehicle in a park is included in park.hpp
	
	/// @brief Obtain payments received by a client
	/// @return The months paid by the client
	std::string paymentsReceivedByClient ( int nif, int month);

    /// @brief Register a monthly subscription for a customer, and customer's car
    /// @param customerName 
    /// @param NIF
    /// @param licensePlate 
    /// @param isPaidForCurrentMonth 
    void registerMonthlySubscription( std::string customerName, std::string lp, int nif, int month, bool isPaidForCurrentMonth);

	/// @brief Update the payment status of a subscription
    /// @param licensePlate 
    /// @param isPaidForCurrentMonth 
    void updateSubscriptionPaymentStatus(std::string licensePlate, int month, bool isPaidForCurrentMonth);

    /// @brief Check if a car has an active subscription
    /// @param licensePlate 
    /// @return True if the car has an active subscription, false otherwise
    bool hasActiveSubscription(std::string licensePlate, int month);	

	/// @brief Check where the car is parked and removes it if it exists in any park
	/// @param licensePlate 
	/// @param exitTime 
	void findAndRemoveVehicle ( std::string& licensePlate, DateTime &exitTime );

	/// @brief Check where the car is parked and add a vehicle if it doesn't exist in any park
	/// @param city 
	/// @param v 
	/// @param in 
	void findAndAddVehicle ( std::string city, Vehicle &v, DateTime &in );

	/// @brief consult the history of a vehicle in the park
	/// @param licensePlate
	void consultHistoric ( std::string licensePlate );
};

#endif 		// _PARK_
