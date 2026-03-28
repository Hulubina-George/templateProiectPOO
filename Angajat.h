#pragma once
#include "Persoana.h"

class Angajat : virtual public Persoana{
protected:
    double salariu;
public:
    Angajat(int varstaPersoana, const std::string& numePersoana, double salariuAngajat);
    ~Angajat() override;
    double getSalariu() const;
    void setSalariu(double salariuNou);
    void info() const override;
};