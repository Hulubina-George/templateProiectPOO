#include "Sala.h"
#include "Angajat.h"
#include "ExceptieSala.h"
#include <iostream>

Sala::Sala(const std::string& nume) { numeSala = new std::string(nume); } // constructor

// destructor
Sala::~Sala() {
    delete numeSala;
    for (size_t i = 0; i < persoane.dimensiune(); ++i) 
        delete persoane[i];
}

/// constructor de copiere
Sala::Sala(const Sala& altul) {
    numeSala = new std::string(*altul.numeSala);
    echipamente = altul.echipamente;
}

/// operator de atribuire
Sala& Sala::operator=(const Sala& altul) {
    if (this != &altul) {
        delete numeSala;
        for (size_t i = 0; i < persoane.dimensiune(); ++i) 
            delete persoane[i];
        persoane.goleste();
        numeSala = new std::string(*altul.numeSala);
        echipamente = altul.echipamente;
    }
    return *this;
}

void Sala::adaugapersoana(Persoana* p) { 
    if (!p) throw ExceptieSala("Persoana nula");
    persoane.adauga(p); 
}

void Sala::adaugaechipament(const Echipament& e) { echipamente.adauga(e); }

void Sala::info() const {
    std::cout << "Sala: " << *numeSala << "\nPersoane:\n";
    for (size_t i = 0; i < persoane.dimensiune(); ++i) persoane[i]->info(); //ia metoda pentru persoana indiferent de tip

    std::cout << "Număr total echipamente: " << echipamente.dimensiune() << "\n";
    for (size_t i = 0; i < echipamente.dimensiune(); ++i) {
        std::cout << " - ";
        echipamente[i].info();
    }
}

//modifica salariul unui angajat dupa nume
bool Sala::modificaSalariu(const std::string& n, double s) {
    for (size_t i = 0; i < persoane.dimensiune(); ++i) {
        if (persoane[i]->getNume() == n) {
            Angajat* a = dynamic_cast<Angajat*>(persoane[i]); //diferentiere client/angajat
            if (a) { a->setSalariu(s); return true; }
        }
    }
    return false;
}

//sterge ultima persoana adaugata in sala
void Sala::stergeUltimaPersoana() {
    if (!persoane.esteGol()) 
        { 
            delete persoane.ultimul(); //elimina obiectul
            persoane.stergeUltimul(); //elimina pointerul
        }
}