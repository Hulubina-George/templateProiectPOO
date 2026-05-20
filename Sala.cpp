#include "Sala.h"
#include "Angajat.h"
#include "ExceptieSala.h"
#include <iostream>

#include <fstream>

#include "PersoanaFactory.h"

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

void Sala::salveazaInFisier(const std::string& numeFisier) const {
    nlohmann::json j;
    j["numeSala"] = *numeSala;

    j["persoane"] = nlohmann::json::array();
    for (size_t i = 0; i < persoane.dimensiune(); ++i) {
        j["persoane"].push_back(persoane[i]->toJson());
    }

    j["echipamente"] = nlohmann::json::array();
    for (size_t i = 0; i < echipamente.dimensiune(); ++i) {
        j["echipamente"].push_back(echipamente[i].toJson());
    }

    std::ofstream fisier(numeFisier);
    if (fisier.is_open()) {
        fisier << j.dump(4);
        fisier.close();
    } else {
        throw ExceptieSala("Nu s-a putut deschide fișierul pentru scriere!");
    }
}

void Sala::incarcaDinFisier(const std::string& numeFisier) {
    std::ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        throw ExceptieSala("Fisierul nu exista sau nu a putut fi deschis!");
    }

    nlohmann::json j;
    fisier >> j;

    *numeSala = j["numeSala"];

    for (const auto& item : j["persoane"]) {
        Persoana* p = PersoanaFactory::creeazaPersoana(item);
        if (p != nullptr) {
            adaugapersoana(p);
        }
    }

    for (const auto& item : j["echipamente"]) {
        std::string numeEchipament = item["nume"];
        adaugaechipament(Echipament(numeEchipament));
    }

    fisier.close();
}