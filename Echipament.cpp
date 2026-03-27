#include <iostream>
#include <string>
#include "Echipament.h"

int Echipament::numarTotal = 0;

Echipament::Echipament(const std::string& numeEchipament){
    this->nume = numeEchipament;
    numarTotal++;
}
Echipament::~Echipament(){
    numarTotal--;
}
int Echipament::getNumarTotal(){
    return numarTotal;
}
void Echipament::info() const{
    std::cout<<"echipament: "<<nume<<'\n';
    std::cout<<"numar total echipamente: "<<getNumarTotal()<<'\n';
}