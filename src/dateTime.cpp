#include "dateTime.hpp"

dateTime::dateTime(int registerDay, int registerMonth, int registerYear, int registerHour, int registerMinute, int registerSeconds) :	
	Date(registerDay, registerMonth, registerYear), Time(registerHour, registerMinute, registerSeconds) {
}

