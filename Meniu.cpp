#include <iostream>
#include <string>
#include "Meniu.h"
#include "Client.h"
#include "AngajatFitness.h"
#include "AngajatNutritie.h"
#include "AngajatDublu.h"
#include "Abonament.h"
#include "ExceptieSala.h"

Meniu::Meniu(Sala& s):salaMea(s){}

void Meniu::ruleaza(){
    int optiune = -1;

    while (optiune != 0) {
        std::cout << '\n' << "MENIU GESTIUNE SALA" << '\n';
        std::cout << "1. Crearea de obiecte noi" << '\n';
        std::cout << "2. Modificare Salariu Angajat" << '\n';
        std::cout << "3. Afisare informatii" << '\n';
        std::cout << "4. Stergerea elementelor" << '\n';
        std::cout << "0. Iesire" << '\n';
        std::cout << "Alege o optiune: ";
        
        // REPARAȚIA 1: Dacă citirea eșuează (cazul robotului), setăm optiune = 0 ca să ieșim
        if (!(std::cin >> optiune)) {
            optiune = 0;
            continue;
        }

        switch(optiune) {
            case 1: {
                int subOptiune;
                std::cout << '\n' << "Ce doresti sa creezi?" << '\n';
                std::cout << "1. Client" << '\n' << "2. Angajat Fitness" << '\n' << "3. Angajat Nutritie" << '\n' << "4. Angajat Dublu" << '\n' << "5. Echipament" << '\n';
                std::cout << "Alegerea ta: ";
                
                // REPARAȚIA 2: Verificăm și aici citirea
                if (!(std::cin >> subOptiune)) break;

                std::string nume;
                std::cin.ignore(); 
                
                try {
                    if (subOptiune >= 1 && subOptiune <= 4) {
                        std::cout << "Nume persoana: ";
                        if (!std::getline(std::cin, nume)) break;
                        
                        int varsta;
                        std::cout << "Varsta: ";
                        if (!(std::cin >> varsta)) break;

                        if (subOptiune == 1) {
                            int vizite;
                            std::cout << "Numar vizite: ";
                            if (!(std::cin >> vizite)) break;
                            Abonament ab("Standard", 150.0, 30);
                            salaMea.adaugapersoana(new Client(varsta, nume, vizite, ab));
                        } 
                        else if (subOptiune == 2) {
                            double salariu; 
                            std::string antrenament;
                            std::cout << "Salariu: "; 
                            if (!(std::cin >> salariu)) break;
                            if (salariu < 0 || salariu > 10000) 
                                throw ExceptieValidare("Salariul trebuie sa fie intre 0 si 10000");

                            std::cout << "Tip antrenament: "; 
                            std::cin.ignore(); 
                            if (!std::getline(std::cin, antrenament)) break;
                            salaMea.adaugapersoana(new AngajatFitness(varsta, nume, salariu, antrenament));
                        }
                        else if (subOptiune == 3) {
                            double salariu; std::string dieta;
                            std::cout << "Salariu: "; 
                            if (!(std::cin >> salariu)) break;
                            if (salariu < 0 || salariu > 10000) 
                                throw ExceptieValidare("Salariul trebuie sa fie intre 0 si 10000");
                            
                            std::cout << "Tip dieta:";
                            std::cin.ignore();
                            if (!std::getline(std::cin, dieta)) break;
                            salaMea.adaugapersoana(new AngajatNutritie(varsta, nume, salariu, dieta));
                        }
                        else if (subOptiune == 4) {
                            double salariu; std::string antrenament, dieta;
                            std::cout << "Salariu: "; 
                            if (!(std::cin >> salariu)) break;
                            if (salariu < 0 || salariu > 10000) 
                                throw ExceptieValidare("Salariul trebuie sa fie intre 0 si 10.000");
                            std::cout << "Tip antrenament: "; 
                            std::cin.ignore(); 
                            if (!std::getline(std::cin, antrenament)) break;

                            std::cout << "Tip dieta: "; 
                            if (!std::getline(std::cin, dieta)) break;
                            salaMea.adaugapersoana(new AngajatDublu(varsta, nume, salariu, antrenament, dieta));
                        }
                        std::cout << "Persoana creata cu succes!" << '\n';
                    } 
                    else if (subOptiune == 5) {
                        std::cout << "Nume echipament: ";
                        std::cin.ignore(); // Avem nevoie de ignore înainte de getline
                        if (!std::getline(std::cin, nume)) break;
                        salaMea.adaugaechipament(Echipament(nume));
                        std::cout << "Echipament adaugat\n";
                    }
                } 
                catch (const ExceptieValidare& e) {
                    std::cout << "eroare: " << e.what() << "\n";
                }
                break;
            }
            case 2: {
                std::string numeCautat;
                double salariuNou;
                std::cout << "Modificare Salariu" << '\n';
                std::cout << "Nume angajat: ";
                std::cin.ignore();
                if (!std::getline(std::cin, numeCautat)) break;

                std::cout << "Salariu nou: ";
                if (!(std::cin >> salariuNou)) break;

                try {
                    if (salariuNou < 0 || salariuNou > 10000) {
                        throw ExceptieValidare("eroare, salariu invalid.");
                    }
                    
                    bool gasit = salaMea.modificaSalariu(numeCautat, salariuNou);
                    if (gasit) {
                        std::cout << "salariul actualizat" << '\n';
                    } else {
                        std::cout << "angajatul inexistent" << '\n';
                    }
                } 
                catch (const ExceptieValidare& e) {
                    std::cout << "eroare: " << e.what() << "\n";
                }
                break;
            }
            case 3:
                std::cout << '\n' << "Afisare baza de date" << '\n';
                salaMea.info();
                break;
            case 4:
                std::cout << '\n' << "Stergere ultima persoana adaugata" << '\n';
                salaMea.stergeUltimaPersoana();
                break;
            case 0:
                std::cout << "Am iesit din program" << '\n';
                break;
            default:
                std::cout << "optiune invalida" << '\n';
                break;
        }
    }
}