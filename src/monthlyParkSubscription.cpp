#include "monthlyParkSubscription.hpp"

Subscription::Subscription( std::string customerName, std::string lp, int NIF, bool isPaidForCurrentMonth = false ) {
    this->licensePlate = lp;
    this->customerName = customerName;
    this->NIF = NIF;
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

std::string Subscription::getCustomerName( ) const {
    return this->customerName;
}

std::string Subscription::getLicensePlate( ) const {
    return this->licensePlate;
}
