#include "Persoana.h"
#include <iostream>
#include <string>

Persoana::Persoana(int varstaPersoana, const std::string& numePersoana) {
    this->varsta = varstaPersoana;
    this->nume = numePersoana;
}

Persoana::~Persoana() {}

std::string Persoana::getNume() const {
    return nume;
}

int Persoana::getVarsta() const {
    return varsta;
}