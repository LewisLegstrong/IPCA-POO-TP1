#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <iostream>

class Date {
public: 	
	Date (int d, int m, int y);

protected: 
	int day;
	int month;
	int year;
	
public:
	int getDay();
	int getMonth();
	int getYear();
};
	
#endif // _DATE_HPP_
