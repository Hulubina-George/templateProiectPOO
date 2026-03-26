#include <iostream>
#include <string>

class Persoana{
protected:
    std::string nume;
    int varsta;

public:
    Persoana(int varstaPersoana, const std::string& numePersoana); ///constructor
    virtual ~Persoana(); ///destructor
    virtual void info() const=0; ///clasa abstract
};