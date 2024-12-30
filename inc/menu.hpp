#ifndef _MENU_
#define _MENU_

#include "registry.hpp"
#include "file_manipulation.hpp"
#include "park.hpp"
#include "dateTime.hpp"
#include "vehicle.hpp"

#include <iostream>

enum class menuOptions{
    REGISTER_PARK_TO_CITY = 1,
    LIST_PARKS,
    REGISTER_ENTRY_VEHICLE,
    REGISTER_EXIT_VEHICLE,
    LIST_VEHICLES,
    FIND_CITY_VEHICLE_IS_PARKED,
    RETURN_VEHICLE_HISTORY,
    MANAGE_SUBSCRIPTION,
    FIND_ATIVE_SUBSCRIPTION
};

class Menu {
private:
    GestPark gestPark;

public:
    /// @brief Constructor of main menu
    Menu();

    /// @brief Destructor of Main Menu
    ~Menu();

    /// @brief Function to display the main menu
    void displayMenu();
    /// @brief Function to handle the user input
    void handleUserInput();
};



#endif // _MENU_