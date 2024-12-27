#ifndef _DATE_TIME_
#define _DATE_TIME_

#include <iostream>
#include <string>
#include <cstdint>

#include "date.hpp"
#include "time.hpp"

#define YEAR_TO_SECONDS 31536000
// Month is dynamically calculated
#define DAY_TO_SECONDS 86400
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60



class DateTime : public Date, public Time {	
public: 
	/// @brief Constructor for a class derived from Date and Time. meant to simplify the verification process
	DateTime(int registerDay, int registerMonth, int registerYear, 
				int registerHour, int registerMinute, int registerSeconds);

private:
	std::uint64_t timeStamp;
	void convertToTimeStamp();

public:
	/// @brief Overload operator (-) to calculate the time passed between two DateTime objects. Makes use of timeStamp to achieve this
	/// @param entryTime DateTime object to subtract from the current DateTime object
	/// @return the time passed between two DateTime objects in seconds
	uint64_t operator- ( DateTime &entryTime );

	/// @brief Converts the DateTime object to a timeStamp and returns it
	/// Assists the operator- in calculating the time passed between two DateTime objects
	/// @return the timeStamp of the DateTime object in seconds
	uint64_t getTimeStamp();
};

#endif 		// _DATE_TIME_