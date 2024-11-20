#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <iostream>

class Time {
public:
	Time( int h, int m, int s); // constructor

private:
	int hour;
	int minute;
	int seconds;

public:		
	int getHour();
	int getMinute();
	int getSeconds();

	float operator-( const Time& t ); // overload operator -
};


#endif // _TIME_HPP_