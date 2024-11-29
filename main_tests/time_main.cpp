#include "time.hpp"

int main() {

    // Hora entre antes das 08:00 e sai antes das 08:00
    Time entryTime1(1, 15, 0);
    Time exitTime1(7, 0, 0);

    // Hora entre antes das 08:00 e sai depois 08:00 mas antes das 20:00
    Time entryTime2(7, 45, 0);
    Time exitTime2(11, 15, 0);

    // Hora entre depois das 08:00 e sai antes das 20:00 
    Time entryTime3(10, 30, 0);
    Time exitTime3(19, 0, 0);

    // Hora entre antes das 20:00 e sai antes da 00:00
    Time entryTime4(18, 0, 0);
    Time exitTime4(21, 45, 0);

    // Hora entre depois das 20:00 e sai antes da 00:00
    Time entryTime5(20, 37, 0);
    Time exitTime5(22, 37, 0);

    // Hora entre depois das 20:00 e sai depois da 00:00 mas antes das 08:00
    Time entryTime6(23, 30, 0);
    Time exitTime6(6, 15, 0);

    // Hora de entrada inválida
    Time entryTime7(25, 30, 0);
    Time exitTime7(5, 0, 0);

    // Hora de saída inválida
    Time entryTime8(22, 30, 0);
    Time exitTime8(25, 0, 0);
}