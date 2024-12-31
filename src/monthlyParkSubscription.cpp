#include "monthlyParkSubscription.hpp"

Subscription::Subscription( std::string customerName, std::string lp, int NIF, int month, bool isPaidForCurrentMonth = false ) {
    this->licensePlate = lp;
    this->customerName = customerName;
    this->NIF = NIF;
    this->month = month;
    this->isPaidForCurrentMonth = isPaidForCurrentMonth;
}
    
void Subscription::setIsPaidForCurrentMonth( bool isPaid ) {
    this->isPaidForCurrentMonth = isPaid;
}

bool Subscription::getIsPaidForCurrentMonth( ) const {
    return this->isPaidForCurrentMonth;
}

int Subscription::getNIF( ) const {
    return this->NIF;
}

int Subscription::getMonth() {
    return month; 
}

std::string Subscription::getCustomerName( ) const {
    return this->customerName;
}

std::string Subscription::getLicensePlate( ) const {
    return this->licensePlate;
}
