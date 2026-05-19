#include "Angajat.h"
#include <iostream>

Angajat::Angajat(int varstaPersoana, const std::string& numePersoana, double salariuAngajat) : Persoana(varstaPersoana, numePersoana), salariu(salariuAngajat) {}
Angajat::~Angajat() {}
double Angajat::getSalariu() const { return salariu; }
void Angajat::setSalariu(double salariuNou) { salariu = salariuNou; }
void Angajat::info() const {
    std::cout << "Nume: " << getNume() << ", Varsta: " << getVarsta() << ", Salariu: " << getSalariu() << "\n";
}

nlohmann::json Angajat::toJson() const {
    return nlohmann::json{
        {"tip_obiect", "Angajat"},
        {"nume", getNume()},
        {"varsta", getVarsta()},
        {"salariu", getSalariu()}
    };
}