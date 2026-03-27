#pragma once
#include <iostream>
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
    explicit Sala(const std::string& numeSalaFitness);
    ~Sala();
    Sala(const Sala& altul);
    Sala& operator=(const Sala& altul);

    void adaugapersoana(Persoana* p);
    void adaugaechipament(const Echipament& e);
    void info() const;
    bool modificaSalariu(const std::string& numeAngajat, double salariuNou);
    void stergeUltimaPersoana();
};