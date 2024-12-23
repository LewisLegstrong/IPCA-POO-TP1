#ifndef _DATE_TIME_
#define _DATE_TIME_

#include <iostream>
#include <string>

#include "date.hpp"
#include "time.hpp"

class dateTime : public Date, public Time {	
public: 
	/// @brief Constructor for a class derived from Date and Time. meant to simplify the verification process
	dateTime(int registerDay, int registerMonth, int registerYear, int registerHour, int registerMinute, int registerSeconds);
};


#endif 		// _DATE_TIME_