#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <iostream>
#include <string>

class Time {
public:
	Time( int h, int m, int s ); // constructor

protected:
	int hour;
	int minute;
	int seconds;

public:		
	/// @brief obtain the hour of the registry
	/// @return 
	int getHour();

	/// @brief obtain the minute of the registry
	/// @return
	int getMinute();

	/// @brief obtain the seconds of the registry
	/// @return
	int getSeconds();

	/// @brief obtain the time of the registry
	/// @return string with the time
	std::string getTime();

	/// @brief overload operator - > by using the operator - between two Time objects
	int operator-( const Time& t ); 
};


#endif // _TIME_HPP_