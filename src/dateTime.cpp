#include "dateTime.hpp"

DateTime::DateTime(int registerDay, int registerMonth, int registerYear, int registerHour, int registerMinute, int registerSeconds) :	
	Date(registerDay, registerMonth, registerYear), Time(registerHour, registerMinute, registerSeconds) {
}

void DateTime::convertToTimeStamp() {
	this-> timeStamp = (year * YEAR_TO_SECONDS) + (monthDays.at(month - 1) * DAY_TO_SECONDS) + ( ( day - 1 ) * DAY_TO_SECONDS ) + (hour * MINUTES_IN_HOUR * SECONDS_IN_MINUTE) + (minute * SECONDS_IN_MINUTE) + seconds;
}

uint64_t DateTime::getTimeStamp() {
	convertToTimeStamp();
	return this->timeStamp;
}

uint64_t DateTime::operator- ( DateTime &entryTime ) {	
	convertToTimeStamp();
	return ( this->timeStamp - entryTime.getTimeStamp() );
}

