#include  <iostream>
#include "./inc/time.hpp"
#include "./inc/date.hpp"

int main() {
	Date d1(11, 9, 2024);
	Date d2(30, 8, 2024);
		
	std::cout << "Paulo fez anos em: " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << std::endl;
	std::cout << "Paulo fez anos em: " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << std::endl;

	return 0;
}