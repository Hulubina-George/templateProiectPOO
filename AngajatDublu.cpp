#include "AngajatDublu.h"
#include <iostream>

AngajatDublu::AngajatDublu(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat, const std::string& dietaAngajat) 
    : Persoana(varstaPersoana, numePersoana), Angajat(varstaPersoana, numePersoana, salariuAngajat), 
      AngajatFitness(varstaPersoana, numePersoana, salariuAngajat, antrenamentAngajat), 
      AngajatNutritie(varstaPersoana, numePersoana, salariuAngajat, dietaAngajat) {}
AngajatDublu::~AngajatDublu() {}
void AngajatDublu::info() const {
    std::cout << "Angajat Dublu: " << getNume() << ", Fitness & Nutritie, Salariu: " << getSalariu() << "\n";
}