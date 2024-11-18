#include "time.hpp"


Time::Time( int h, int m, int s ) {
	if (( (h <= 23) && (h >= 0) ) && ( (m < 60) && (m >= 0) ) && ( (s < 60) && (s >= 0) )) {	
		this->hour = h;  
		this->minute = m;
		this->seconds = s;
	}
	else {
		std::cerr << "Seu burro!"; //Try Catch implementation here
	}
}

int Time::getHour() {
	return this->hour;
}

int Time::getMinute() {
	return this->minute;
}

int Time::getSeconds () {
	return this->seconds;
}

int Time::operator-(const Time& t){
	int hours_in_park = this->hour - t.hour;
	int seconds_in_park = this->seconds - t.seconds;
	int minutes_in_park = this->minute - t.minute;
	 

	return ((hours_in_park * 60) + minutes_in_park + (seconds_in_park / 60)); //Returns the ammount of minutes in the park
}


