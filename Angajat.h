#pragma once
#include <iostream>
#include <string>
#include "Persoana.h"

class Angajat:public Persoana{
protected:
    double salariu;
public:
    Angajat(int varstaPersoana, const std::string& numePersoana, double salariuAngajat); //constructor
    ~Angajat() override; //destructor
    void info() const override;  
};

