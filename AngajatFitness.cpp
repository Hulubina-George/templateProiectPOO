#include <iostream>
#include <string>
#include "AngajatFitness.h"

AngajatFitness::AngajatFitness(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& antrenamentAngajat):Angajat(varstaPersoana, numePersoana, salariuAngajat){
    this->antrenament = antrenamentAngajat;
}

AngajatFitness::~AngajatFitness(){}

void AngajatFitness::info() const{
    std::cout<<"angajat: "<<nume<<'\n'<<"varsta: "<<varsta<<'\n'<<"salariu: "<<salariu<<'\n'<<"antrenament: "<<antrenament<<'\n';
}