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
    explicit Sala(const std::string& nume);
    ~Sala();
    Sala(const Sala& altul);
    Sala& operator=(const Sala& altul);
    void adaugapersoana(Persoana* p);
    void adaugaechipament(const Echipament& e);
    void info() const;
    bool modificaSalariu(const std::string& nume, double salariu);
    void stergeUltimaPersoana();
};