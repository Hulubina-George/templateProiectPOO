#pragma once
#include "Sala.h"

class Meniu {
private:
    Sala& salaMea;
public:
    explicit Meniu(Sala& s);
    void ruleaza();
};