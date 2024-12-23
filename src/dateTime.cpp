#include "dateTime.hpp"

dateTime::dateTime(int registerDay, int registerMonth, int registerYear, int registerHour, int registerMinute, int registerSeconds) :	
	Date(registerDay, registerMonth, registerYear), Time(registerHour, registerMinute, registerSeconds) {
}

timePassed_t dateTime::operator-(const dateTime &toSubtract) {
	timePassed_t timePassed = {
		.year 		= this->year - toSubtract.year,
		.month		= this->month - toSubtract.month,
		.day 		= this->day - toSubtract.day,
		.hour 		= this->hour - toSubtract.hour,
		.minute 	= this->minute - toSubtract.minute,
		.seconds 	= this->seconds - toSubtract.seconds
	};

	return timePassed;
}

