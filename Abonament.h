#pragma once
#include <string>

class Abonament {
private:
    std::string tip;
    double pret;
    int durata;
public:
    Abonament(const std::string& tipAbonament, double pretAbonament, int durataAbonament); /// constructor
    std::string getTip() const; // getter pentru tip
    double getPret() const;// getter pentru pret
    int getDurata() const;// getter pentru durata
    void info() const; /// metoda afisare
};