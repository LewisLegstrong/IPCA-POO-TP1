#ifndef _DATE_TIME_
#define _DATE_TIME_

#include <iostream>
#include <string>

#include "date.hpp"
#include "time.hpp"

class dateTime : public Date, public Time {	
public: 
	dateTime(int registerDay, int registerMonth, int registerYear, int registerHour, int registerMinute, int registerSeconds);
};


#endif 		// _DATE_TIME_