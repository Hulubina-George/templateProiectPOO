#include "Persoana.h"

Persoana::Persoana(int varstaPersoana, const std::string& numePersoana) : varsta(varstaPersoana), nume(numePersoana) {}
Persoana::~Persoana() {}
std::string Persoana::getNume() const { return nume; }
int Persoana::getVarsta() const { return varsta; }