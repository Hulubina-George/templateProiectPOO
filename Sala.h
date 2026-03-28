#pragma once
#include <string>
#include <vector>
#include "Persoana.h"
#include "Echipament.h"

class Sala {
private:
    std::string* numeSala;
    std::vector<Persoana*> persoane;
    std::vector<Echipament> echipamente;
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