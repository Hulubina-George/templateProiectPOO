#pragma once
#include "Persoana.h"
#include <nlohmann/json.hpp>
#include "StrategieBonus.h"

class Angajat : virtual public Persoana{
protected:
    double salariu;
    StrategieBonus* strategieBonus = nullptr;
public:
    Angajat(int varstaPersoana, const std::string& numePersoana, double salariuAngajat);
    ~Angajat() override;
    double getSalariu() const;
    void setSalariu(double salariuNou);
    void info() const override;
    nlohmann::json toJson() const override;

    void setStrategieBonus(StrategieBonus* nouaStrategie) {
        strategieBonus = nouaStrategie;
    }

    virtual double calculeazaVenitTotal() const {
        double venitFinal = salariu; 
        
        if (strategieBonus != nullptr) {
            venitFinal += strategieBonus->calculeazaBonus(salariu); 
        }
        
        return venitFinal;
    }
};