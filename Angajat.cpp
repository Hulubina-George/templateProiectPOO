#include <iostream>
#include <string>
#include "Angajat.h"

Angajat::Angajat(int varstaPersoana, const std::string& numePersoana, double salariuAngajat):Persoana(varstaPersoana, numePersoana){
    this->salariu = salariuAngajat;
}

Angajat::~Angajat() {}

void Angajat::info() const{
    std::cout<<"angajat: "<<nume<<'\n'<<"varsta: " <<varsta<<'\n'<<"salariu: "<<salariu<<'\n';
}