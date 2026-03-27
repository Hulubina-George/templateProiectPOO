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
    
    double getSalariu()const{return salariu;}
    void setSalariu(double salariuNou){salariu=salariuNou;}
    
    void info() const override;  
};

