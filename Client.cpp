#include "Client.h"
#include <iostream>
#include <string>

Client::Client(int varstaPersoana, const std::string& numePersoana, int numarVizite, const Abonament& abonament)
    : Persoana(varstaPersoana, numePersoana), abonament(abonament) {
    this->numarVizite = numarVizite;
}

Client::~Client() {}

void Client::info() const {
    std::cout << "Client: " << getNume() << " | Varsta: " << getVarsta() << " | Vizite: " << numarVizite << "\n";
    abonament.info();
}