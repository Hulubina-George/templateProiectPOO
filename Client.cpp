#include <iostream>
#include <string>
#include "Client.h"

Client::Client(int varstaPersoana, const std::string& numePersoana, int numarVizite, Abonament abonament):Persoana(varstaPersoana, numePersoana), abonament(abonament){
    this->numarVizite = numarVizite;
}

Client::~Client(){}

void Client::info() const{
    std::cout<<"client: "<<nume<<'\n'<<"varsta: "<<varsta<<'\n'<<"numar vizite: "<<numarVizite<<'\n';
    std::cout << "abonament: ";
    this->abonament.info();
}