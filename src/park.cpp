#include "park.hpp"

void Park::listVehicles() {
    for (const IORegistry &unit : this->parkedVehicles) {
        std::cout << unit.getDetails() << std::endl;
    }
}

Park::Park(int capacity)
{
    maxCapacity = capacity;
    currentVehicles = 0;
}

void Park::newEntry(Vehicle &v, Time &in) {
    if (currentVehicles < maxCapacity) {
        IORegistry newRegistry(v, in);
        parkedVehicles.push_back(newRegistry);
        currentVehicles++;
    } else {
        std::cout << "Park is at full capacity!" << std::endl;
    }
}

void Park::removeEntry(const std::string &licensePlate, Time &out) {
    for (auto i = parkedVehicles.begin(); i != parkedVehicles.end(); ++i) {
        if (i->getVehicle()->getLicensePlate() == licensePlate) {
            i->setExitTime(out); // Set the exit time
            std::cout << "Vehicle with license plate " << licensePlate << " has been removed at " 
                      << out.getHour() << ":" << out.getMinute() << ":" << out.getSeconds() << std::endl;
            parkedVehicles.erase(i);
            currentVehicles--;
            return;
        }
    }
    std::cout << "Vehicle with license plate " << licensePlate << " not found." << std::endl;
}

int Park::getEmptySpots() {
    return maxCapacity - currentVehicles;
}

int Park::getOccupiedSpots() {
    return currentVehicles;
}

// float Park::calculateTicket(std::string license) {
//     float priceToPay = 0.0;

//     //Find registry associated to license plate
//     for (IORegistry &registry : parkedVehicles) {
//         if (registry.getVehicle()->getLicensePlate() == license) {             // The vehicle is found
//             switch ( registry.getParkPeriod() ) {
//                 case ( parkPeriod::EVENING ):
//                     priceToPay = ( registry.getParkedTime() / 15 ) * 0.2;
//                     break;

//                 case ( parkPeriod::DAY ):
//                     registry.getParkedTime() <= 60 ? priceToPay = ( ( registry.getParkedTime() / 15 ) * 0.2 ) 
//                                                     : priceToPay = ( ( 0.8 + ( ( registry.getParkedTime() - 60 ) / 15 ) * 0.3 ) ); //0.8eur equivale a 4 tempos completos de 15min a 0.2eur
//                     break;

//                 case ( parkPeriod::MIXED ):
//                     int parkDurationDayPeriod = 0;
//                     int parkDurationNightPeriod = 0;
                    
//                     // Separa o tempo de parque das 8-20 e das 20-8
//                     if ( registry.getEntryTime() >= 8 ) {
//                         parkDurationDayPeriod = 1200 - registry.getEntryTime();
//                         parkDurationNightPeriod = registry.getExitTime() - 1200;  // 1200 equivale as 20h da noite em ponto 
//                     }
//                     else if ( registry.getEntryTime() >= 20 ){
//                         parkDurationDayPeriod = 1200 - registry.getExitTime();
//                         parkDurationNightPeriod = registry.getEntryTime() - 1200;  // 1200 equivale as 20h da noite em ponto 
//                     }

//                     if ( parkDurationDayPeriod <= 60 ) {
//                         priceToPay = ( ( parkDurationDayPeriod / 15 ) * 0.2 );
//                     }
//                     else {
//                         priceToPay = ( ( 0.8 + ( ( parkDurationDayPeriod - 60 ) / 15 ) * 0.3 ) );
//                     }
//                     priceToPay += ( parkDurationNightPeriod / 15 ) * 0.2;
//                     break;
//             }
//         }
//     }
//     return priceToPay;
// }
   
