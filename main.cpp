#include "Sala.h"
#include "Meniu.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    Sala salaMea("Gym"); 
    Meniu meniu(salaMea); 
    meniu.ruleaza();

    return 0;
}