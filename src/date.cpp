#include "date.hpp"

Date::Date(int d, int m, int y) {
	this->year = y;
	this->month = m;
	this->day = d;

	std::cout << "Month: " << m << "; Day: " << d << std::endl;

	// if ( d > monthDays[m]  || d < 1 ) {
	// 	throw std::invalid_argument("Invalid day");
	// }
	// else {
	// 	this->day = d;
	// }
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
