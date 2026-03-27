#include <iostream>
#include "Sala.h"
#include "Meniu.h"

int main(){
    Sala gym("Sala Fitness");
    Meniu meniuInteractiv(gym);
    meniuInteractiv.ruleaza();
    return 0;
}