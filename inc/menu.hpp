#ifndef _MENU_
#define _MENU_

#include <iostream>

enum class menuOptions{
    REGISTER_PARK_TO_CITY = 1,
    LIST_PARKS,
    REGISTER_VEHICLE,
    FIND_CITY_VEHICLE_IS_PARKED,
    RETURN_VEHICLE_HISTORY,
    FIND_NIF_MONTHLY_PAYMENTS
};

class Menu {
public:
    /// @brief Constructor of main menu
    Menu();





    /// @brief Destructor of Main Menu
    ~Menu();
};



#endif // _MENU_