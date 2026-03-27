#pragma once
#include <iostream>
#include <string>
#include "Sala.h"

class Meniu{
private:
    Sala& salaMea;
public:
    explicit Meniu(Sala& s); ///constructor
    void ruleaza();
};