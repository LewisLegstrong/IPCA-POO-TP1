#include "vehicle_reg.hpp"

int main() {

    // Primeira Matrícula
    std::string licensePlate = "97-97-DJ";
    Vehicle myVehicle(licensePlate);

    // Segunda Matrícula
    std::string licensePlate1 = "69-CU-69";
    Vehicle myVehicle1(licensePlate1);

    
    std::cout << "Matricula do Vehicle1: "  << myVehicle1.getLicensePlate() << std::endl;
}