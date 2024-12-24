#include <iostream>

#include "vehicle.hpp"
#include "registry.hpp"

class monthlyParkSubscription {
public:
	monthlyParkSubscription(int nifRegister, Vehicle *vehicleRegister, std::string name);

private:
	int 		nif;
	bool 		isActive;
	Vehicle 	*registeredVehicle;
	std::string customerName;

public:
	/// @brief Activates the monthly subscription
	void activateSubscription();

	/// @brief Deactivates the monthly subscription
	void revokeSubscription();

	/// @brief Returns if the monthly subscription is active
	/// @return true if the subscription is active, false otherwise
	bool getIsActive();

};
