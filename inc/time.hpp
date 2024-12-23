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
	int getHour();
	int getMinute();
	int getSeconds();

	std::string getTime();

	int operator-( const Time& t ); // overload operator -
};


#endif // _TIME_HPP_