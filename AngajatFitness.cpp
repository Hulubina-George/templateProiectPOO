#include "AngajatFitness.h"
#include <iostream>

AngajatFitness::AngajatFitness(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat) 
    : Persoana(varstaPersoana, numePersoana), Angajat(varstaPersoana, numePersoana, salariuAngajat), antrenament(antrenamentAngajat) {}
AngajatFitness::~AngajatFitness() {}
void AngajatFitness::info() const {
    std::cout << "Angajat Fitness: " << getNume() << ", Antrenament: " << antrenament << ", Salariu: " << getSalariu() << "\n";
}