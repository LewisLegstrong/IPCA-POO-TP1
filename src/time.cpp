#include "time.hpp"


Time::Time( int h, int m, int s ) {
	try {
		if (( (h <= 23) && (h >= 0) ) && ( (m < 60) && (m >= 0) ) && ( (s < 60) && (s >= 0) )) {	
			this->hour = h;  
			this->minute = m;
			this->seconds = s;
		}
		else {
			throw std::invalid_argument("Invalid time");
		}
	} 
	catch (std::exception& e) {
		std::cerr << "Invalid time" << std::endl;
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
	int hours_in_park 	= this->hour - t.hour;
	int seconds_in_park = this->seconds - t.seconds;
	int minutes_in_park = this->minute - t.minute;
	 

	return ((hours_in_park * 60) + minutes_in_park + (seconds_in_park / 60)); //Returns the ammount of minutes 
}

std::string Time::getTime() {
	return (std::to_string(this->hour) + ":" + std::to_string(this->minute) + ":" + std::to_string(this->seconds));
}
