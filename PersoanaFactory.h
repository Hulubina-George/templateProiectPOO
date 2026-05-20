#pragma once

#include <string>
#include "Persoana.h"
#include "Client.h"
#include "AngajatFitness.h"
#include "AngajatNutritie.h"
#include "AngajatDublu.h"

#include <nlohmann/json.hpp>

class PersoanaFactory {
public:
    static Persoana* creeazaPersoana(const nlohmann::json& j) {
        std::string tip = j["tip_obiect"];
        std::string nume = j["nume"];
        int varsta = j["varsta"];

        if (tip == "Client"){
            int vizite = j["numarVizite"];
            std::string tipAbo = j["abonament"]["tip"];
            double pretAbo = j["abonament"]["pret"];
            int durataAbo = j["abonament"]["durata"];
            return new Client(varsta, nume, vizite, Abonament(tipAbo, pretAbo, durataAbo));
        }
        else if (tip == "AngajatFitness") {
            double salariu = j["salariu"];
            std::string antrenament = j["antrenament"];
            return new AngajatFitness(varsta, nume, salariu, antrenament);
        }
        else if (tip == "AngajatNutritie") {
            double salariu = j["salariu"];
            std::string dieta = j["dieta"];
            return new AngajatNutritie(varsta, nume, salariu, dieta);
        }
        else if (tip == "AngajatDublu") {
            double salariu = j["salariu"];
            std::string antrenament = j["antrenament"];
            std::string dieta = j["dieta"];
            return new AngajatDublu(varsta, nume, salariu, antrenament, dieta);
        }
        
        return nullptr;
    }
};