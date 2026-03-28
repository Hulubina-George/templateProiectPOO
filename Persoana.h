#pragma once
#include <string>

class Persoana {
protected:
    int varsta;
    std::string nume;
public:
    Persoana(int varstaPersoana, const std::string& numePersoana); /// constructor
    virtual ~Persoana(); /// destructor virtual

    std::string getNume() const; /// getter pentru nume
    int getVarsta() const; /// getter pentru varsta
    
    virtual void info() const = 0; /// metoda virtuala pura pentru afisare
};