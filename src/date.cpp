#include "date.hpp"

Date::Date(int d, int m, int y) {
	this->year = y;
	this->month = m;
	if ( d > monthDays[m] ) {
		throw std::invalid_argument("Invalid day");
	}
}

int Date::getDay() {
	return this->day;
}

int  Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}
