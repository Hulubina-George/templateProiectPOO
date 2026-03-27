#pragma once
#include "Angajat.h"

class AngajatFitness : virtual public Angajat {
protected:
    std::string antrenament;
public:
    AngajatFitness(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat);
    ~AngajatFitness() override;
    void info() const override;
};