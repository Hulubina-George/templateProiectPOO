#pragma once
#include "AngajatFitness.h"
#include "AngajatNutritie.h"
#include <nlohmann/json.hpp>

class AngajatDublu : public AngajatFitness, public AngajatNutritie{
public:
    AngajatDublu(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat, const std::string& dietaAngajat);
    ~AngajatDublu() override;
    void info() const override;
    nlohmann::json toJson() const override;
};