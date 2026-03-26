#pragma once
#include <iostream>
#include <string>
#include "Persoana.h"

class Client:public Persoana{
private:
    int numarVizite;
    int *vizite;
public:
    Client(int varstaPersoana, const std::string& numePersoana, int numarVizite, const int* vectorVizite); //constructor

    ~Client() override; ///destructor           
    Client(const Client& altul); ///copiere
    Client& operator=(const Client& altul);///operator             

    void info() const override;
};