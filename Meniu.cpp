#include "Meniu.h"
#include "Client.h"
#include "AngajatFitness.h"
#include "AngajatNutritie.h"
#include "AngajatDublu.h"
#include "ExceptieSala.h"
#include <iostream>
#include <string>

Meniu::Meniu(Sala& s) : salaMea(s) {}

void Meniu::ruleaza() {
    int optiune = -1;
    while (optiune != 0) {
        std::cout << "\nMENIU GESTIUNE SALA\n1. Creare obiecte\n2. Modificare Salariu\n3. Afisare\n4. Stergere\n0. Iesire\nOptiune: ";
        
        if (!(std::cin >> optiune)) { optiune = 0; continue; }

        switch (optiune) {
            case 1: {
                int sub;
                std::cout << "\n1.Client 2.Fitness 3.Nutritie 4.Dublu 5.Echipament\nAlegere: ";
                if (!(std::cin >> sub)) break;
                std::cin.ignore();

                try {
                    if (sub >= 1 && sub <= 4) {
                        std::string nume;
                        std::cout << "Nume: ";
                        if (!std::getline(std::cin, nume)) break;
                        int v;
                        std::cout << "Varsta: ";
                        if (!(std::cin >> v)) break;

                        if (sub == 1) {
                            int viz;
                            std::cout << "Vizite: ";
                            if (!(std::cin >> viz)) break;
                            salaMea.adaugapersoana(new Client(v, nume, viz, Abonament("Standard", 150, 30)));
                        } else if (sub == 2) {
                            double s;
                            std::cout << "Salariu: ";
                            if (!(std::cin >> s)) break;

                            if (s < 0 || s > 10000) throw ExceptieValidare("Salariu invalid! Trebuie să fie între 0 și 10000.");
                            
                            std::cout << "Antrenament: ";
                            std::cin.ignore();
                            std::string ant;
                            if (!std::getline(std::cin, ant)) break;
                            salaMea.adaugapersoana(new AngajatFitness(v, nume, s, ant));
                        } else if (sub == 3) {
                            double s;
                            std::cout << "Salariu: ";
                            if (!(std::cin >> s)) break;

                            if (s < 0 || s > 10000) throw ExceptieValidare("Salariu invalid! Trebuie să fie între 0 și 10000.");

                            std::cout << "Dieta: ";
                            std::cin.ignore();
                            std::string dieta;
                            if (!std::getline(std::cin, dieta)) break;
                            salaMea.adaugapersoana(new AngajatNutritie(v, nume, s, dieta));
                        } else if (sub == 4) {
                            double s;
                            std::cout << "Salariu: ";
                            if (!(std::cin >> s)) break;

                            if (s < 0 || s > 10000) throw ExceptieValidare("Salariu invalid! Trebuie să fie între 0 și 10000.");

                            std::cin.ignore();
                            std::string ant, dieta;
                            std::cout << "Antrenament: ";
                            if (!std::getline(std::cin, ant)) break;
                            std::cout << "Dieta: ";
                            if (!std::getline(std::cin, dieta)) break;
                            salaMea.adaugapersoana(new AngajatDublu(v, nume, s, ant, dieta));
                        }
                        std::cout << "Succes!\n";
                    } else if (sub == 5) {
                        std::string nE;
                        std::cout << "Nume echipament: ";
                        if (std::getline(std::cin, nE)) {
                            salaMea.adaugaechipament(Echipament(nE));
                        }
                    }
                } catch (const std::exception& e) { std::cout << "Eroare: " << e.what() << "\n"; }
                break;
            }
            case 2: {
                std::string nC;
                double sN;
                std::cout << "Nume angajat: ";
                std::cin.ignore();
                if (!std::getline(std::cin, nC)) break;
                std::cout << "Salariu nou: ";
                if (!(std::cin >> sN)) break;

                try {
                    if (sN < 0 || sN > 10000) {
                        throw ExceptieValidare("Salariu invalid! Trebuie sa fie intre 0 si 10000.");
                    }
                    
                    if (salaMea.modificaSalariu(nC, sN)) {
                        std::cout << "Actualizat!\n";
                    } else {
                        std::cout << "Angajatul nu a fost găsit!\n";
                    }
                } catch (const ExceptieValidare& e) {
                    std::cout << "Eroare: " << e.what() << "\n";
                }
                break;
            }
            case 3:
                salaMea.info();
                break;
            case 4:
                salaMea.stergeUltimaPersoana();
                std::cout << "Sters!\n";
                break;
            case 0:
                std::cout << "Iesire...\n";
                break;
        }
    }
}