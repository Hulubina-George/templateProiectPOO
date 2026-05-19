#pragma once
#include "Persoana.h"
#include "Abonament.h"
#include <nlohmann/json.hpp>

class Client : public Persoana{
private:
    int numarVizite;
    Abonament abonament;
public:
    Client(int varstaPersoana, const std::string& numePersoana, int numarVizite, const Abonament& abonament);
    ~Client() override;
    void info() const override;
    nlohmann::json toJson() const override;
};