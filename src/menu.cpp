#include "menu.hpp"

GestPark gestPark;

Menu::Menu() {
    // Constructor implementation
}

Menu::~Menu() {
    // Destructor implementation
}

void Menu::displayMenu() {
    std::cout << "1. Register Park to Cit" << std::endl;
    std::cout << "2. List Parks" << std::endl;;
    std::cout << "3. Register Entry Vehicle" << std::endl;
    std::cout << "4. Register Exit Vehicle" << std::endl;
    std::cout << "5. List Vehicles" << std::endl;
    std::cout << "6. Find City Vehicle is Parked" << std::endl;
    std::cout << "7. Return Vehicle History" << std::endl;
    std::cout << "8. Find NIF Monthly Payments" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void Menu::handleUserInput() {
    int choice;
    std::string city;
    int capacity;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (static_cast<menuOptions>(choice)) {

            case menuOptions::REGISTER_PARK_TO_CITY:
                std::cout << "Register Park to City selected." << std::endl;
                std::cout << "Choose City You Want To Create Park: ";
                std::cin >> city;
                std::cout << "Capacity: ";
                std::cin >> capacity;
                gestPark.insertParkInCity( city, capacity );
                break;

            case menuOptions::LIST_PARKS:
                std::cout << "List Parks selected." << std::endl;
                std::cout << "Choose City You Want To List Park: ";
                std::cin >> city;
                gestPark.listParksInCity (city);
                break;

            case menuOptions::REGISTER_ENTRY_VEHICLE:   
                std::cout << "Register Entry Vehicle selected." << std::endl;
                std::cout << "Em que cidade" << std::endl;
                std::cout << "Não tem parque nessa cidade cria um se quiseres burro" << std::endl;


                std::cout << "License Plate of Car:" << std::endl;
                
                //newEntry(licensePlate, entryTime);
                break;

            case menuOptions::REGISTER_EXIT_VEHICLE:
                std::cout << "Register Exit Vehicle selected." << std::endl;
                break;

            case menuOptions::LIST_VEHICLES:
                std::cout << "List Vehicles selected." << std::endl;
                break;

            case menuOptions::FIND_CITY_VEHICLE_IS_PARKED:
                std::cout << "Find City Vehicle is Parked selected." << std::endl;
                break;

            case menuOptions::RETURN_VEHICLE_HISTORY:
                std::cout << "Return Vehicle History selected." << std::endl;
                break;

            case menuOptions::FIND_NIF_MONTHLY_PAYMENTS:
                std::cout << "Find NIF Monthly Payments selected." << std::endl;
                break;

            case static_cast<menuOptions>(0):
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);
}