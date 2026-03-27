#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Echipament.h"
#include "Persoana.h"
#include "ExceptieSala.h"

class Sala {
private:
    std::string* numeSala;
    std::vector<Echipament> echipamente;
    std::vector<Persoana*> persoane;

public:
    Sala(const std::string& numeSalaFitness);

    ~Sala();
    Sala(const Sala& altul);
    Sala& operator=(const Sala& altul);

    void adaugapersoana(Persoana* p);
    void adaugaechipament(const Echipament& e);
    void info() const;
};