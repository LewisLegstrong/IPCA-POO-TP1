#ifndef _MONTHLY_PARK_SUBSCRIPTION_
#define _MONTHLY_PARK_SUBSCRIPTION_

#include <iostream>

#include "vehicle.hpp"
#include "registry.hpp"

class Subscription {
public:
    Subscription( std::string customerName, std::string lp, int NIF, bool isPaidForCurrentMonth );

private:
	int 		NIF;
	bool		isPaidForCurrentMonth;
    std::string customerName;
	std::string licensePlate;

public:
	void setIsPaidForCurrentMonth( bool isPaid );
    bool getIsPaidForCurrentMonth( ) const ;
	int getNIF( ) const ;
	std::string getCustomerName( ) const ;
    std::string getLicensePlate( ) const ;
};

#endif // _MONTHLY_PARK_SUBSCRIPTION_