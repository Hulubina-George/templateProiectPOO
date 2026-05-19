#include "Client.h"
#include <iostream>

Client::Client(int varstaPersoana, const std::string& numePersoana, int numarVizite, const Abonament& abonament) : Persoana(varstaPersoana, numePersoana), numarVizite(numarVizite), abonament(abonament) {}
Client::~Client() {}
void Client::info() const {
    std::cout << "Client: " << getNume() << ", Varsta: " << getVarsta() << ", Vizite: " << numarVizite << "\n"; /// detali client
    abonament.info(); /// afisare abonament
}

nlohmann::json Client::toJson() const {
    return nlohmann::json{
        {"tip_obiect", "Client"},
        {"nume", getNume()},
        {"varsta", getVarsta()},
        {"numarVizite", numarVizite},
        {"abonament", abonament.toJson()}
    };
}