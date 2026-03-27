#include "Sala.h"
#include "Meniu.h"
#include <iostream>

int main() {
    try {
        Sala salaMea("Gym");
        Meniu meniu(salaMea);
        meniu.ruleaza();
    }
    catch (const std::exception& e) {
        std::cerr << "Eroare fatala: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}