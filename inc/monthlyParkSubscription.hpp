#include <iostream>

#include "vehicle_reg.hpp"



class monthlyParkSubscription {
public:
	monthlyParkSubscription(int nifRegister, Vehicle *vehicleRegister);

private:
	int 		nif;
	bool 		isActive;
	Vehicle 	*registeredVehicle;

public:
	bool 	getIsActive();
	 



};
