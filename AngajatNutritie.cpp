#include <iostream>
#include <string>
#include "AngajatNutritie.h"

AngajatNutritie::AngajatNutritie(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& dietaAngajat) : Angajat(varstaPersoana, numePersoana, salariuAngajat) {
    this->dieta = dietaAngajat;
}

AngajatNutritie::~AngajatNutritie() {}

void AngajatNutritie::info() const {
    std::cout << "angajat: " << getNume() << '\n' << "varsta: " << getVarsta() << '\n' << "salariu: " << getSalariu() << '\n' << "dieta: " << dieta << '\n';
}