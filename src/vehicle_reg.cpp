#include "vehicle_reg.hpp"

Vehicle::Vehicle(std::string lp) {
	this->license_plate = lp;
}

std::string Vehicle:: getLicensePlate() {
	return this->license_plate;
}

IORegistry::IORegistry(Vehicle &v, Time &in) {
	this->information = &v;
	this->entry = &in;
}

void IORegistry::setExitTime(Time &out) {
	this->exit = &out;
    this->calculateTicket();
}

Vehicle* IORegistry::getVehicle() const {
    return information;
}


std::string IORegistry::getDetails() const { //Function to get the details of the vehicle
    std::ostringstream oss; //String stream to concatenate the information
    oss << "License Plate: " << information->getLicensePlate()
        << ", Entry Time: " << entry->getHour() << ":" << entry->getMinute();
    return oss.str();
}

int IORegistry::getTimeInPark(Time &current) {
    return (current - *entry);
}

int IORegistry::getParkedTime() {
    return (this->exit->getHour() - this->entry->getHour()); // Returns the parked time in minutes
}

int IORegistry::getEntryTime() {
    return ( ( this->entry->getHour() * 60 ) + this->entry->getMinute()  ); // Returns the time of entrance in minutes
}

int IORegistry::getExitTime() {
    return ( ( this->exit->getHour() * 60 ) + this->entry->getMinute() ); // Returns the time of exit in minutes
}

parkPeriod IORegistry::getParkPeriod() {
    if ( this->entry->getHour() >= 8 && this->exit->getHour() <= 20 ) {
        return parkPeriod::DAY;
    }
    else if ( this->entry->getHour() >= 20 && this->exit->getHour() <= 8 ) {
        return parkPeriod::EVENING;
    }
    else {
        return parkPeriod::MIXED;
    }
}

void IORegistry::calculateTicket() {
    switch ( this->getParkPeriod() ) {
        case ( parkPeriod::EVENING ):
            this->priceToPay = ( this->getParkedTime() / 15 ) * 0.2;
            break;

        case ( parkPeriod::DAY ):
            this->getParkedTime() <= 60 ? this->priceToPay = ( ( this->getParkedTime() / 15 ) * 0.2 ) 
                                            : this->priceToPay = ( ( 0.8 + ( ( this->getParkedTime() - 60 ) / 15 ) * 0.3 ) ); //0.8eur equivale a 4 tempos completos de 15min a 0.2eur
            break;

        case ( parkPeriod::MIXED ):
            int parkDurationDayPeriod = 0;
            int parkDurationNightPeriod = 0;
            
            // Separa o tempo de parque das 8-20 e das 20-8
            if ( this->getEntryTime() >= 8 ) {
                parkDurationDayPeriod = 1200 - this->getEntryTime();
                parkDurationNightPeriod = this->getExitTime() - 1200;  // 1200 equivale as 20h da noite em ponto 
            }
            else if ( this->getEntryTime() >= 20 ){
                parkDurationDayPeriod = 1200 - this->getExitTime();
                parkDurationNightPeriod = this->getEntryTime() - 1200;  // 1200 equivale as 20h da noite em ponto 
            }

            if ( parkDurationDayPeriod <= 60 ) {
                this->priceToPay = ( ( parkDurationDayPeriod / 15 ) * 0.2 );
            }
            else {
                this->priceToPay = ( ( 0.8 + ( ( parkDurationDayPeriod - 60 ) / 15 ) * 0.3 ) );
            }
            this->priceToPay += ( parkDurationNightPeriod / 15 ) * 0.2;
            break;
    }
    std::cout << "Price to pay: " << this->priceToPay << std::endl;
}

	int IORegistry::getPriceToPay() {
		return this->priceToPay;
	}