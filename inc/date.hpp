#ifndef _DATE_HPP
#define _DATE_HPP

#include <iostream>

class Date {
public: 	
	Date (int d, int m, int y);

private: 
	int day;
	int month;
	int year;
	
public:
	int getDay();
	int getMonth();
	int getYear();
};
	
#endif // _DATE_HPP
