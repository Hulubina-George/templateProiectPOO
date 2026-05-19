#include "Sala.h"
#include "Meniu.h"

int main() {
    Sala salaMea("Gym"); 
    Meniu meniu(salaMea); 
    meniu.ruleaza();

    return 0;
}