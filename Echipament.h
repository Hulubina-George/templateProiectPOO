#pragma once
#include <iostream>
#include <string>

class Echipament{
private:
    std::string nume;
    static int numarTotal;
public:
    Echipament(const std::string& numeEchipament);
    ~Echipament();

    static int getNumarTotal();
    void info() const;
};