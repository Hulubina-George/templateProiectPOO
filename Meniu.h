#pragma once
#include <iostream>
#include <string>
#include "Sala.h"

class Meniu{
private:
    Sala& salaMea;
public:
    Meniu(Sala& s); ///constructor
    void ruleaza();
};