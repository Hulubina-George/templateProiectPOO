#include <iostream>
#include <string>
#include "AngajatNutritie.h"

AngajatNutritie::AngajatNutritie(int varstaPersoana, const std::string& numePersoana, double salariuAngajat, const std::string& dietaAngajat):Angajat(varstaPersoana, numePersoana, salariuAngajat){
    this->dieta = dietaAngajat;
}

AngajatNutritie::~AngajatNutritie(){}

void AngajatNutritie::info() const{
    std::cout<<"angajat: "<<nume<<'\n'<<"varsta: "<<varsta<<'\n'<<"salariu: "<<salariu<<'\n'<<"dieta: "<<dieta<<'\n';
}