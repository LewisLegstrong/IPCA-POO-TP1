#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <iostream>

class Date {
public: 	
	/// @brief constructor of the class Date
	/// @param d is the day of the registry 
	/// @param m is the month of the registry
	/// @param y is the year of the registry
	Date (int d, int m, int y);

protected: 
	int day;
	int month;
	int year;
	
public:
	/// @brief 
	/// @return the registry day
	int getDay();
	
	/// @brief
	/// @return the registry month
	int getMonth();

	/// @brief
	/// @return the registry year
	int getYear();
};
	
#endif // _DATE_HPP_
