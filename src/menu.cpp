#include "menu.hpp"

Menu::Menu() {
    // Constructor implementation
}

Menu::~Menu() {
    // Destructor implementation
}

void Menu::displayMenu() {
    std::cout << "=========================" << std::endl;
    std::cout << "   Welcome to the Menu" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Register Park to City" << std::endl;
    std::cout << "2. List Parks" << std::endl;;
    std::cout << "3. Register Entry Vehicle" << std::endl;
    std::cout << "4. Register Exit Vehicle" << std::endl;
    std::cout << "5. List Vehicles" << std::endl;
    std::cout << "6. Find City Vehicle is Parked" << std::endl;
    std::cout << "7. Return Vehicle History" << std::endl;
    std::cout << "8. Manage Subscription " << std::endl;
    std::cout << "9. Find Active Subscription" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void Menu::handleUserInput() {
    int choice;
    int capacity;
    int day, month, year, hour, minute, second;
    int nif;
    std::string city;
    std::string licensePlate;
    std::string name;
    bool isPaid ;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (static_cast<menuOptions>(choice)) {

            case menuOptions::REGISTER_PARK_TO_CITY: {
                std::cout << "Register Park to City selected." << std::endl;
                std::cout << "Choose City You Want To Create Park: ";
                std::cin >> city;
                std::cout << "Capacity: ";
                std::cin >> capacity;
                gestPark.insertParkInCity( city, capacity );
                break;
            }

            case menuOptions::LIST_PARKS: {
                std::cout << "List Parks selected." << std::endl;
                std::cout << "Choose City You Want To List Park: ";
                std::cin >> city;
                gestPark.listParksInCity (city);
                break;
            }

            case menuOptions::REGISTER_ENTRY_VEHICLE: {
                std::cout << "Register Entry Vehicle selected." << std::endl;

                std::cout << "License Plate of Car:" << std::endl;
                std::cin >> licensePlate;
                std::cout << "Day: " << std::endl;
                std::cin >> day;
                std::cout << "Month: " << std::endl;
                std::cin >> month;
                std::cout << "Year: " << std::endl;
                std::cin >> year;
                std::cout << "Hour: " << std::endl;
                std::cin >> hour;
                std::cout << "Minute: " << std::endl;
                std::cin >> minute;
                std::cout << "Second: " << std::endl;
                std::cin >> second;
                std::cout << "Enter city park name: " << std::endl;
                std::cin >> city;

                Vehicle newVehicle( licensePlate );
                DateTime entryTime( day, month, year, hour, minute, second );
 
                if (gestPark.getParkInCity(city)) {
                    gestPark.findAndAddVehicle( city, newVehicle, entryTime );
                } 
                else {
                    std::cout << "No park found in " << city << std::endl;
                }
                break;
            }

            case menuOptions::REGISTER_EXIT_VEHICLE: {
                std::cout << "Register Exit Vehicle selected." << std::endl;
                std::cout << "License Plate of Car:" << std::endl;
                std::cin >> licensePlate;
                std::cout << "Day: " << std::endl;
                std::cin >> day;
                std::cout << "Month: " << std::endl;
                std::cin >> month;
                std::cout << "Year: " << std::endl;
                std::cin >> year;
                std::cout << "Hour: " << std::endl;
                std::cin >> hour;
                std::cout << "Minute: " << std::endl;
                std::cin >> minute;
                std::cout << "Second: " << std::endl;
                std::cin >> second;

                DateTime exitTime(day, month, year, hour, minute, second);
                gestPark.findAndRemoveVehicle( licensePlate, exitTime );

                break;
            }

            case menuOptions::LIST_VEHICLES: {
                std::cout << "List Vehicles selected." << std::endl;
                gestPark.listAllVehicles();
                break;
            }

            case menuOptions::FIND_CITY_VEHICLE_IS_PARKED: {
                std::cout << "Find City Vehicle is Parked selected." << std::endl;
                std::cout << "Enter License Plate: ";
                std::cin >> licensePlate;
                std::string city = gestPark.findCityVehicleIsParked(licensePlate);
                if (city == "Vehicle not found in any park.") {
                    std::cout << city << std::endl;
                } else {
                    std::cout << "The vehicle with license plate " << licensePlate << " is parked in " << city << "." << std::endl;
                }
                break;
            }

            case menuOptions::RETURN_VEHICLE_HISTORY:{
                std::cout << "Enter License Plate:";
                std::cin >> licensePlate;
                gestPark.consultHistoric(licensePlate);
                break;
            }

            case menuOptions::MANAGE_SUBSCRIPTION:{
                int menu_subscription;
                std::cout << "Manage Subscription selected." << std::endl;
                std::cout << "Enter your choice: " << std::endl;
                std::cout << "1 - Add Subscription " << std::endl;
                std::cout << "2 - Check Payment Received " << std::endl;
                std::cout << "3 - Update Payment Subscription " << std::endl;
                std::cin >> menu_subscription;
                if (menu_subscription == 1){
                    std::cout << "Write Name: " << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Write NIF: " << std::endl;
                    std::cin >> nif;
                    std::cout << "License Plate: " << std::endl;
                    std::cin >> licensePlate;
                    std::cout << "Write Month for subscription: " << std::endl;
                    std::cin >> month;
                    std::cout << "Is Paid (1 -> true / 0 -> false): " << std::endl;
                    std::cin >> isPaid;
                    gestPark.registerMonthlySubscription(name, licensePlate, nif, month, isPaid);
                }
                else if (menu_subscription == 2){
                    std::cout << " Write NIF : " << std::endl;
                    std::cin >> nif;
                    std::cout << " Write Month for subscription : " << std::endl;
                    std::cout << gestPark.paymentsReceivedByClient(nif, month);
                }
                else if (menu_subscription == 3){
                    std::cout << " License Plate : " << std::endl;
                    std::cin >> licensePlate;
                    std::cout << " Write Month update for subscription : " << std::endl;
                    std::cin >> month;
                    std::cout << " Is Paid (1 -> true/ 2 -> false): " << std::endl;
                    std::cin >> isPaid;
                    gestPark.updateSubscriptionPaymentStatus(licensePlate, month, isPaid);
                }
                break;
            }

            case menuOptions::FIND_ATIVE_SUBSCRIPTION:{
                std::cout << "Find Ative Subscription selected." << std::endl;
                std::cout << "Insert License Plate:"<< std::endl;
                std::cin >>  licensePlate;
                std::cout << "Insert Month:"<< std::endl;
                std::cin >> month;
                if (gestPark.hasActiveSubscription(licensePlate, month)) {
                    std::cout << "The car with license plate " << licensePlate << " has an active subscription for month " << month << "." << std::endl;
                } else {
                    std::cout << "The car with license plate " << licensePlate << " does not have an active subscription for month " << month << "." << std::endl;
                }
                break;
            }

            case static_cast<menuOptions>(0):{
                std::cout << "Exiting..." << std::endl;
                break;
            }

            default:{
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 0);
}