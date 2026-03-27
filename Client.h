#pragma once
#include <iostream>
#include <string>

#include "Persoana.h"
#include "Abonament.h"

class Client:public Persoana{
private:
    int numarVizite;
    Abonament abonament;
public:
    Client(int varstaPersoana, const std::string& numePersoana, int numarVizite, Abonament abonament);
    ~Client() override;
    
    void info() const override;
};