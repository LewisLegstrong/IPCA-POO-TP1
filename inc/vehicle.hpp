#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>
#include <iostream>



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


#endif // _VEHICLE_HPP_