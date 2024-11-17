#ifndef _TIME_HPP_
#define _TIME_HPP_

class Time {
public:
	Time( int h, int m ); // constructor

private:
	int hour;
	int minute;

public:	
	int getHour();
	int getMinute();

	int operator-( const Time& t ); // overload operator -
};


#endif // _TIME_HPP_