#pragma once
#include "Angajat.h"
#include <nlohmann/json.hpp>

class AngajatNutritie : virtual public Angajat{
protected:
    std::string dieta;
public:
    AngajatNutritie(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& dietaAngajat);
    ~AngajatNutritie() override;
    void info() const override;
    nlohmann::json toJson() const override;
};