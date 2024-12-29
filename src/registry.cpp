#include "registry.hpp"

IORegistry::IORegistry(Vehicle &v, DateTime &in) : information(v), entry(in), exit(0, 0, 0, 0, 0, 0) {
    this->priceToPay = 0.0;
}

void IORegistry::setExitTime(DateTime &out) {
	this->exit = out;
    this->calculateTicket();
    this->writeToFile();
}

std::string IORegistry::getDetails() { // Function to get the details of the vehicle
    std::ostringstream oss; // String stream to concatenate the information
    oss << "License Plate: " << this->information.getLicensePlate()
        << ", Entry Date: " << this->entry.getDay() << "/" << this->entry.getMonth() << "/" << this-> entry.getYear()
        << ", Entry Time: " << this->entry.getHour() << ":" << this->entry.getMinute() << ":" << this->entry.getSeconds();
    return oss.str();
}


void IORegistry::calculateTicket( ) {
    // Verificar se o parque foi mais de 24h 
    uint64_t parkDurationTimeStamp = this-> exit.getTimeStamp() - this->entry.getTimeStamp();
    if ( parkDurationTimeStamp >= DAY_TO_SECONDS ) {
        int times24h = parkDurationTimeStamp / DAY_TO_SECONDS;    //Verify how many times 24h were completed
        this->priceToPay +=( calculate24hValue( this->getEntryTime() ) * times24h );
    }  

    switch ( this->getParkPeriod( ) ) {
        case ( parkPeriod::EVENING ):
            this->priceToPay = ( this->getParkedTime() / 15 ) * 0.2;
            break;

        case ( parkPeriod::DAY ):
            this->getParkedTime() <= 60 ? this->priceToPay = ( ( this->getParkedTime() / 15 ) * 0.2 ) 
                                        : this->priceToPay = ( ( 0.8 + ( ( this->getParkedTime() - 60 ) / 15 ) * 0.3 ) ); //0.8eur equivale a 4 tempos completos de 15min a 0.2eur
            break;

        case ( parkPeriod::MIXED ):
            int parkDurationDayPeriod = 0;
            int parkDurationNightPeriod = 0;
            
            // Separa o tempo de parque das 8-20 e das 20-8
            if ( this->getEntryTime() >= 480 && this->getEntryTime() < 1200) {          //Caso entre de manha
                parkDurationDayPeriod = 1200 - this->getEntryTime();                    //Periodo de parque matinal e sempre as 20 - hora de entrada

                if (this->getExitTime() >= 0 && this->getExitTime() <= 480 )            // Entre a 00_00 e as 8:00    
                    parkDurationNightPeriod = 240 + ( this->getExitTime() );            // Soma o valor das 20:00 às 24:00 em minutos ao valor daa hora de saída                                                               
                else
                    parkDurationNightPeriod = this->getExitTime() - 1200;               // 1200 equivale as 20h da noite em ponto 
            }

            else if ( this->getEntryTime() >= 1200 || this->getEntryTime() < 480){
                if ( this->getEntryTime() >= 1200 && this->getEntryTime() < 1440) {       
                    parkDurationNightPeriod = ( 1440 - this->getEntryTime() ) + 480 ;   //Se entrar antes da meia noite, eu ja sei que la passa a noite. Logo somo as 8h da manha a partir da madrugada mais o valor em minutos desde que entrou ate a meia noite
                }
                else if ( this->getEntryTime() >= 0 && this->getEntryTime() < 480) {
                    parkDurationNightPeriod = 480 - this->getEntryTime();               //Se entrou depois da meia noite, o tempo que la passou e so desde as 8 ate a hora que entrou
                }
                
                std::cout << "Hora de saida e: " << this->getExitTime() << std::endl;
                parkDurationDayPeriod = this->getExitTime() - 480;
            }


            // Calcula o valor a pagar
            if ( parkDurationDayPeriod <= 60 ) {
                this->priceToPay = ( ( parkDurationDayPeriod / 15 ) * 0.2 );
            }
            else {
                this->priceToPay = ( ( 0.8 + ( ( parkDurationDayPeriod - 60 ) / 15 ) * 0.3 ) );
            }

            this->priceToPay += ( parkDurationNightPeriod / 15 ) * 0.2;
            break;
    }
}

void IORegistry::writeToFile() {
    std::string fileContent = "Hora de entrada " + this->entry.getTime() + " Hora de saida " + this->exit.getTime() + " Preco a pagar " + std::to_string(this->priceToPay) + "\n";
    appendToFile(information.getLicensePlate() + ".txt", fileContent);
    
}

int IORegistry::getTimeInPark(DateTime &current) {
    return (current - entry);
}

int IORegistry::getParkedTime() {
    return (this->exit - this->entry); 
}

int IORegistry::getEntryTime() {
    return ( ( this->entry.getHour() * 60 ) + this->entry.getMinute()  ); // Returns the time of entrance in minutes
}

int IORegistry::getExitTime() {
    return ( ( this->exit.getHour() * 60 ) + this->exit.getMinute() ); // Returns the time of exit in minutes
}

float IORegistry::simCalculateTicket( DateTime &exitTimeSimulated ) {
    // Verificar se o parque foi mais de 24h 
    uint64_t parkDurationTimeStamp = exitTimeSimulated.getTimeStamp() - this->entry.getTimeStamp();
    if ( parkDurationTimeStamp >= DAY_TO_SECONDS ) {
        int times24h = parkDurationTimeStamp / DAY_TO_SECONDS;    //Verify how many times 24h were completed
        this->priceToPay +=( calculate24hValue( this->getEntryTime() ) * times24h );
    }  

    int parkedTime = exitTimeSimulated - this->entry;
    float priceToPaySim = 0.00;

    switch ( simGetParkPeriod( ( exitTimeSimulated.getHour() * 60 ) ) ) {
        case ( parkPeriod::EVENING ):
            std::cout << "Afteroon" << std::endl;        
            priceToPaySim = ( parkedTime  / 15 ) * 0.2;
            break;

        case ( parkPeriod::DAY ):
            std::cout << "DAY" << std::endl;
            parkedTime <= 60 ? priceToPaySim = ( ( parkedTime / 15 ) * 0.2 ) 
                             : priceToPaySim = ( ( 0.8 + ( ( parkedTime - 60 ) / 15 ) * 0.3 ) ); //0.8eur equivale a 4 tempos completos de 15min a 0.2eur

            break;

        case ( parkPeriod::MIXED ):
            std::cout << "Misgendered" << std::endl;
            int parkDurationDayPeriod = 0;
            int parkDurationNightPeriod = 0;
            
            // Separa o tempo de parque das 8-20 e das 20-8
            if ( this->getEntryTime() >= 8 ) {
                parkDurationDayPeriod = 1200 - this->getEntryTime();
                parkDurationNightPeriod = ( ( exitTimeSimulated.getHour() * 60 ) + ( exitTimeSimulated.getMinute() ) ) - 1200;  // 1200 equivale as 20h da noite em ponto 
            }
            else if ( this->getEntryTime() >= 20 ){
                parkDurationDayPeriod = 1200 - ( ( exitTimeSimulated.getHour() * 60 ) + ( exitTimeSimulated.getMinute() ) );
                parkDurationNightPeriod = this->getEntryTime() - 1200;  // 1200 equivale as 20h da noite em ponto 
            }

            if ( parkDurationDayPeriod <= 60 ) {
                priceToPaySim = ( ( parkDurationDayPeriod / 15 ) * 0.2 );
            }
            else {
                priceToPaySim = ( ( 0.8 + ( ( parkDurationDayPeriod - 60 ) / 15 ) * 0.3 ) );
            }
            priceToPaySim += ( parkDurationNightPeriod / 15 ) * 0.2;
            break;
    }

    std::cout << priceToPaySim << std::endl; 
    return priceToPaySim;
}


float IORegistry::calculate24hValue( int exitTime ) {
    if ( exitTime < 420 ) {
        return ( 23.90 );
    }
    else if ( exitTime < 435 ) {
        return ( 23.80 );
    }
    else if ( exitTime < 450 ) {
        return ( 23.70 );
    }
    else if ( exitTime < 480 ) {
        return ( 23.60 );
    }
    else if ( exitTime < 1140) {
        return ( 23.60 );
    }
    else if ( exitTime < 1155 ) {
        return ( 23.70 );
    }
    else if ( exitTime < 1170 ) {
        return ( 23.80 );
    }
    else if ( exitTime < 1185 ) {
        return ( 23.90 );
    }
    else if ( exitTime < 1200 ) {
        return ( 24.00 );
    }
} 


float IORegistry::getPricePaid() {
    return this->priceToPay;
}

parkPeriod IORegistry::getParkPeriod() {
    if ( ( this->getEntryTime() >= 480  && this->getEntryTime() < 1200) && ( this->getExitTime() <= 1200 && this->getExitTime() > 480 ) ) {
        return parkPeriod::DAY;
    }
    else if ( this->getEntryTime() >= 1200 && this->getExitTime() <= 480 ) {
        return parkPeriod::EVENING;
    }
    else {
        return parkPeriod::MIXED;
    }
}

parkPeriod IORegistry::simGetParkPeriod( int exitTimeSimulated ) { 
    if ( ( this->getEntryTime() >= 480 && this->getEntryTime() < 1200 ) && ( exitTimeSimulated <= 1200 && exitTimeSimulated > 480) ) {
        return parkPeriod::DAY;
    }
    else if ( this->getEntryTime() >= 1200 && exitTimeSimulated <= 480 ) {
        return parkPeriod::EVENING;
    }
    else {
        return parkPeriod::MIXED;
    }
}

Vehicle IORegistry::getVehicle() const {
    return information;
}

