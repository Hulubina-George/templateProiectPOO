#include "Persoana.h"

Persoana::Persoana(int varstaPersoana, const std::string& numePersoana):varsta(varstaPersoana), nume(numePersoana) {} /// constructor, nu am folosit this din cauze eficientei
Persoana::~Persoana() {} /// destructor virtual

std::string Persoana::getNume() const {return nume;} /// getter pentru nume
int Persoana::getVarsta() const {return varsta;} /// getter pentru varsta