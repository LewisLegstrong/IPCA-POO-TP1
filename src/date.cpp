#include "date.hpp"

Date::Date(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
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



