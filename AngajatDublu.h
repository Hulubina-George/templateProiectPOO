#pragma once
#include "AngajatFitness.h"
#include "AngajatNutritie.h"

class AngajatDublu : public AngajatFitness, public AngajatNutritie {
public:
    AngajatDublu(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat, const std::string& dietaAngajat);
    ~AngajatDublu() override;
    void info() const override;
};