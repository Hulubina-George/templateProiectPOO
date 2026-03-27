#include <iostream>
#include <string>
#include "AngajatDublu.h"

AngajatDublu::AngajatDublu(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat, const std::string& dietaAngajat) : Angajat(varstaPersoana, numePersoana, salariuAngajat), AngajatFitness(varstaPersoana, numePersoana, salariuAngajat, antrenamentAngajat), AngajatNutritie(varstaPersoana, numePersoana, salariuAngajat, dietaAngajat) {}

AngajatDublu::~AngajatDublu() {}

void AngajatDublu::info() const {
    std::cout << "angajat " << getNume() << '\n' << "varsta: " << getVarsta() << '\n' << "salariu: " << getSalariu() << '\n' << "antrenament: " << antrenament << '\n' << "dieta: " << dieta << '\n';
}