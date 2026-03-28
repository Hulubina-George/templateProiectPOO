#include "Abonament.h"
#include <iostream>

Abonament::Abonament(const std::string& tipAbonament, double pretAbonament, int durataAbonament) : tip(tipAbonament), pret(pretAbonament), durata(durataAbonament) {} /// constructor

/// getters
std::string Abonament::getTip() const { return tip; }
double Abonament::getPret() const { return pret; }
int Abonament::getDurata() const { return durata; }

void Abonament::info() const {
    std::cout << "Tip: " << getTip() << ", Pret: " << getPret() << ", Durata: " << getDurata() << " zile\n";
}