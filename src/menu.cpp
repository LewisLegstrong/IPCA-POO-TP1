#include "menu.hpp"

GestPark gestPark;

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
    std::cout << "9. Find NIF Monthly Payments" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void Menu::handleUserInput() {
    int choice;
    std::string city;
    std::string licensePlate;
    std::string name;
    int nif;
    bool isPaid;
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

            case menuOptions::MANAGE_SUBSCRIPTION:
                int menu_subscription;
                std::cout << "Manage Subscription selected." << std::endl;
                std::cout << "Enter your choice: " << std::endl;
                std::cout << "1 - Add Subscription " << std::endl;
                std::cout << "2 - Check Payment Received " << std::endl;
                std::cout << "3 - Update Payment Subscription " << std::endl;
                std::cin >> menu_subscription;
                if (menu_subscription == 1){
                    std::cout << " Write Propertie Name : " << std::endl;
                    std::cin >> name;
                    std::cout << " Write NIF : " << std::endl;
                    std::cin >> nif;
                    std::cout << " License Plate : " << std::endl;
                    std::cin >> licensePlate;
                    std::cout << " Is Paid (1 -> true/ 2 -> false): " << std::endl;
                    std::cin >> isPaid;
                    gestPark.registerMonthlySubscription(name, nif, licensePlate, isPaid);
                    break;
                }
                else if (menu_subscription == 2){
                    std::cout << " Write NIF : " << std::endl;
                    std::cin >> nif;
                    std::cout << gestPark.paymentsReceivedByClient(nif);
                    break;
                }
                else if (menu_subscription == 3){
                    std::cout << " License Plate : " << std::endl;
                    std::cin >> licensePlate;
                    std::cout << " Is Paid (1 -> true/ 2 -> false): " << std::endl;
                    std::cin >> isPaid;
                    gestPark.updateSubscriptionPaymentStatus(licensePlate, isPaid);
                    break;
                }
                break;

            case menuOptions::FIND_ATIVE_SUBSCRIPTION:
                std::cout << "Find Ative Subscription selected." << std::endl;
                std::cout << "Insert License Plate:"<< std::endl;
                std::cin >>  licensePlate;
                if (gestPark.hasActiveSubscription(licensePlate)) {
                    std::cout << "The car with license plate " << licensePlate << " has an active subscription." << std::endl;
                        }  
                else {
                    std::cout << "The car with license plate " << licensePlate << " does not have an active subscription." << std::endl;
                    }
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