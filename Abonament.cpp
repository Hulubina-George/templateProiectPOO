#include "Abonament.h"
#include <iostream>
#include <string>

Abonament::Abonament(const std::string& tipAbonament, double pretAbonament, int durataAbonament) {
    this->tip = tipAbonament;
    this->pret = pretAbonament;
    this->durata = durataAbonament;
}
//getteres
std::string Abonament::getTip()const{
    return this->tip;
}
double Abonament::getPret()const{
    return this -> pret;
}
int Abonament::getDurata()const{
    return this->durata;
}

void Abonament::info()const{
    std::cout << "Tip: " << getTip() << ", Pret: " << getPret() << ", Durata: " << getDurata() << " zile\n";
}