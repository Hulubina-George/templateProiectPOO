#include "AngajatNutritie.h"
#include <iostream>

AngajatNutritie::AngajatNutritie(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& dietaAngajat) : Persoana(varstaPersoana, numePersoana), Angajat(varstaPersoana, numePersoana, salariuAngajat), dieta(dietaAngajat) {}
AngajatNutritie::~AngajatNutritie() {}
void AngajatNutritie::info() const {
    std::cout << "Angajat Nutritie: " << getNume() << ", Dieta: " << dieta << ", Salariu: " << getSalariu() << "\n";
}

nlohmann::json AngajatNutritie::toJson() const {
    return nlohmann::json{
        {"tip_obiect", "AngajatNutritie"},
        {"nume", getNume()},
        {"varsta", getVarsta()},
        {"salariu", getSalariu()},
        {"dieta", dieta}
    };
}