#include "Echipament.h"
#include <iostream>

int Echipament::numarTotalEchipamente = 0;

Echipament::Echipament(const std::string& nume) : numeEchipament(nume) { numarTotalEchipamente++; }

int Echipament::getNumarTotal() { return numarTotalEchipamente; }

void Echipament::info() const {
    std::cout << "Echipament: " << numeEchipament  << "\n" << "Numar total echipamente: " << getNumarTotal() << "\n";
}