#include "Sala.h"
#include "Angajat.h"
#include "ExceptieSala.h"
#include <iostream>

Sala::Sala(const std::string& nume) { numeSala = new std::string(nume); }
Sala::~Sala() {
    delete numeSala;
    for (size_t i = 0; i < persoane.size(); ++i) delete persoane[i];
}
Sala::Sala(const Sala& altul) {
    numeSala = new std::string(*altul.numeSala);
    echipamente = altul.echipamente;
}
Sala& Sala::operator=(const Sala& altul) {
    if (this != &altul) {
        delete numeSala;
        for (size_t i = 0; i < persoane.size(); ++i) delete persoane[i];
        persoane.clear();
        numeSala = new std::string(*altul.numeSala);
        echipamente = altul.echipamente;
    }
    return *this;
}
void Sala::adaugapersoana(Persoana* p) { 
    if (!p) throw ExceptieSala("Persoana nula");
    persoane.push_back(p); 
}
void Sala::adaugaechipament(const Echipament& e) { echipamente.push_back(e); }
void Sala::info() const {
    std::cout << "Sala: " << *numeSala << "\nPersoane:\n";
    for (size_t i = 0; i < persoane.size(); ++i) persoane[i]->info();
}
bool Sala::modificaSalariu(const std::string& n, double s) {
    for (size_t i = 0; i < persoane.size(); ++i) {
        if (persoane[i]->getNume() == n) {
            Angajat* a = dynamic_cast<Angajat*>(persoane[i]);
            if (a) { a->setSalariu(s); return true; }
        }
    }
    return false;
}
void Sala::stergeUltimaPersoana() {
    if (!persoane.empty()) { delete persoane.back(); persoane.pop_back(); }
}