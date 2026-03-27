#include <iostream>
#include <string>
#include <vector>
#include "Sala.h"

///constructor
Sala::Sala(const std::string& numeSalaFitness){
    this->numeSala = new std::string(numeSalaFitness) ;
}
///destructor
Sala::~Sala(){
    delete numeSala;
    for(int i=0; i<persoane.size(); i++){
        delete persoane[i];
    }
}
///copiere
Sala::Sala(const Sala& altul){
    this -> numeSala = new std::string(*altul.numeSala);
    this->echipamente = altul.echipamente;
}
///operator
Sala& Sala::operator=(const Sala& altul){
    if(this == &altul){return *this;}
    delete this->numeSala;
    for(int i=0; i<this->persoane.size(); i++){
        delete this -> persoane[i]; ///sterg obiectele.
    }
    this->persoane.clear(); ///sterg adresele
    this->numeSala = new std::string(*altul.numeSala);
    this->echipamente = altul.echipamente;
    return *this;
}
///adaugare in vectori
void Sala::adaugapersoana(Persoana* p){
    if (p==nullptr) {
        throw ExceptieSala("persoana invalida");
    }
    this->persoane.push_back(p);
}
void Sala::adaugaechipament(const Echipament& e){
    this->echipamente.push_back(e);
}
///afisare
void Sala::info()const{
    std::cout<<"sala: "<<*numeSala<<'\n';
    std::cout<<"echipamente:";
    for (int i=0; i<this->echipamente.size(); i++){

        this->echipamente[i].info();
    }
    std::cout<<"persoane:";
    for (int i=0; i<this->persoane.size(); i++){

        this->persoane[i]->info();
    }
}