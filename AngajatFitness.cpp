#include <iostream>
#include <string>
#include "AngajatFitness.h"

AngajatFitness::AngajatFitness(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat) : Angajat(varstaPersoana, numePersoana, salariuAngajat) {
    this->antrenament = antrenamentAngajat;
}

AngajatFitness::~AngajatFitness() {}

void AngajatFitness::info() const {
    std::cout << "angajat: " << getNume() << '\n' << "varsta: " << getVarsta() << '\n' << "salariu: " << getSalariu() << '\n' << "antrenament: " << antrenament << '\n';
}