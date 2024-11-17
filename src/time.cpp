#include "../inc/time.hpp"

Time::Time( int h, int m ) {
	this->hour = h;
	this->minute = m;
}

int Time::getHour() {
	return this->hour;
}

int Time::getMinute() {
	return this->minute;
}

int Time::operator-(const Time& t){
	int hours_in_park = this->hour - t.hour;
	int minutes_in_park = this->minute - t.minute;

	return ((hours_in_park * 60) + minutes_in_park); //Returns the ammount of minutes in the park
}


