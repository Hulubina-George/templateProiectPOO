#pragma once
#include <iostream>
#include <string>

class Abonament{
private:
    std::string tip;
    double pret;
    int durata;
public:
    Abonament(const std::string& tipAbonament, double pretAbonament, int durataAbonament);

    std::string getTip() const;
    double getPret() const;
    int getDurata() const;

    void info() const;
};