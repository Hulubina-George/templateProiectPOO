#include <iostream>
#include <string>
#include <vector>
#include "Sala.h"
#include "Angajat.h"

///constructor
Sala::Sala(const std::string& numeSalaFitness){
    this->numeSala = new std::string(numeSalaFitness);
}

///destructor
Sala::~Sala(){
    delete numeSala;
    for(size_t i = 0; i < persoane.size(); i++){
        delete persoane[i];
    }
}

///copiere
Sala::Sala(const Sala& altul){
    this->numeSala = new std::string(*altul.numeSala);
    this->echipamente = altul.echipamente;
}

///operator
Sala& Sala::operator=(const Sala& altul){
    if(this == &altul){return *this;}
    delete this->numeSala;
    for(size_t i = 0; i < this->persoane.size(); i++){
        delete this->persoane[i]; ///sterg obiectele.
    }
    this->persoane.clear(); ///sterg adresele
    this->numeSala = new std::string(*altul.numeSala);
    this->echipamente = altul.echipamente;
    return *this;
}

///adaugare in vectori
void Sala::adaugapersoana(Persoana* p){
    if (p == nullptr) {
        throw ExceptieSala("persoana invalida");
    }
    this->persoane.push_back(p);
}

void Sala::adaugaechipament(const Echipament& e){
    this->echipamente.push_back(e);
}

///afisare
void Sala::info() const {
    std::cout << "sala: " << *numeSala << '\n';
    std::cout << "numar echipamente: " << echipamente.size() << '\n';
    std::cout << "echipamente:";
    for (size_t i = 0; i < this->echipamente.size(); i++){
        this->echipamente[i].info();
    }
    std::cout << "persoane:";
    for (size_t i = 0; i < this->persoane.size(); i++){
        this->persoane[i]->info();
    }
}

///modificare salariu
bool Sala::modificaSalariu(const std::string& numeAngajat, double salariuNou){
    for (size_t i = 0; i < this->persoane.size(); i++) {
        if (this->persoane[i]->getNume() == numeAngajat) {
            Angajat* angajatGasit = dynamic_cast<Angajat*>(this->persoane[i]);
            if (angajatGasit != nullptr){
                angajatGasit->setSalariu(salariuNou);
                return true;
            }
        }
    }
    return false;
}

///stergere ultima persoana
void Sala::stergeUltimaPersoana() {
    if (!this->persoane.empty()) {
        delete this->persoane.back();
        this->persoane.pop_back();
    }
}