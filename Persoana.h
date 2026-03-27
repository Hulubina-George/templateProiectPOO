#pragma once
#include <string>

class Persoana {
protected:
    int varsta;
    std::string nume;
public:
    Persoana(int varstaPersoana, const std::string& numePersoana);
    virtual ~Persoana();
    std::string getNume() const;
    int getVarsta() const;
    virtual void info() const = 0;
};