#pragma once
#include <string>

#include "Persoana.h"
#include "Echipament.h"
#include "ManagerResurse.h"

class Sala {
private:
    std::string* numeSala;
    ManagerResurse<Persoana*> persoane; //polimorfism
    ManagerResurse<Echipament> echipamente;
public:
    explicit Sala(const std::string& nume); /// constructor
    ~Sala();// destructor
    Sala(const Sala& altul); /// constructor de copiere
    Sala& operator=(const Sala& altul); /// operator de atribuire

    void adaugapersoana(Persoana* p);
    void adaugaechipament(const Echipament& e);

    void info() const;
    
    bool modificaSalariu(const std::string& nume, double salariu); 
    void stergeUltimaPersoana();
};