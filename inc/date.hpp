#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <iostream>
#include <map>

/// @brief Map with the days of each month, avoids the need to use switch case
static std::map< int , int > monthDays = {
	{1, 31},
	{2, 28},
	{3, 31},
	{4, 30},
	{5, 31},
	{6, 30},
	{7, 31},
	{8, 31},
	{9, 30},
	{10, 31},
	{11, 30},
	{12, 31}
};

class Date {
public: 	
	/// @brief constructor of the class Date
	Date (int d, int m, int y);

protected: 
	int	day;
	int month;
	int	year;
	
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
