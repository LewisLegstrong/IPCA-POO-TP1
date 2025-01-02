#include "date.hpp"

Date::Date(int d, int m, int y) {
	this->year = y;
	
	if ( m > 12 || m < 1 ) {
		throw std::invalid_argument("Invalid month");
	}
	else {
		this->month = m;
	}


	if ( d > monthDays[m]  || d < 1 ) {
		throw std::invalid_argument("Invalid day");
	}
	else {
		this->day = d;
	}
}

int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}
