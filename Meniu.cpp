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
                int suboptiune;
                std::cout << "\n1.Client 2.Fitness 3.Nutritie 4.Dublu 5.Echipament\nAlegere: ";
                if (!(std::cin >> suboptiune)) break;
                std::cin.ignore();

                try {
                    if (suboptiune >= 1 && suboptiune <= 4) {
                        std::string nume;
                        std::cout << "Nume: ";
                        if (!std::getline(std::cin, nume)) break;
                        int varsta;
                        std::cout << "Varsta: ";
                        if (!(std::cin >> varsta)) 
                            break;

                        if (suboptiune == 1) { //client
                            int vizite;
                            std::cout << "Vizite: ";
                            if (!(std::cin >> vizite)) break;
                            salaMea.adaugapersoana(new Client(varsta, nume, vizite, Abonament("Standard", 150, 30)));
                        } else if (suboptiune == 2) { //fitness
                            double salariu;
                            std::cout << "Salariu: ";
                            if (!(std::cin >> salariu)) break;

                            if (salariu < 0 || salariu > 10000) throw ExceptieValidare("Salariu invalid! Trebuie să fie între 0 și 10000.");
                            
                            std::cout << "Antrenament: ";
                            std::cin.ignore();
                            std::string antrenament;
                            if (!std::getline(std::cin, antrenament)) break;
                            salaMea.adaugapersoana(new AngajatFitness(varsta, nume, salariu, antrenament));
                        } else if (suboptiune == 3) { //nutritie
                            double salariu;
                            std::cout << "Salariu: ";
                            if (!(std::cin >> salariu)) break;

                            if (salariu < 0 || salariu > 10000) throw ExceptieValidare("Salariu invalid! Trebuie să fie între 0 și 10000.");

                            std::cout << "Dieta: ";
                            std::cin.ignore();
                            std::string dieta;
                            if (!std::getline(std::cin, dieta)) break;
                            salaMea.adaugapersoana(new AngajatNutritie(varsta, nume, salariu, dieta));
                        } else if (suboptiune == 4) { //dublu
                            double salariu;
                            std::cout << "Salariu: ";
                            if (!(std::cin >> salariu)) break;

                            if (salariu < 0 || salariu > 10000) throw ExceptieValidare("Salariu invalid! Trebuie să fie între 0 și 10000.");

                            std::cin.ignore();
                            std::string antrenament, dieta;
                            std::cout << "Antrenament: ";
                            if (!std::getline(std::cin, antrenament)) break;
                            std::cout << "Dieta: ";
                            if (!std::getline(std::cin, dieta)) break;
                            salaMea.adaugapersoana(new AngajatDublu(varsta, nume, salariu, antrenament, dieta));
                        }
                        std::cout << "Succes!\n";
                    } else if (suboptiune == 5) { //echipament
                        std::string numeEchipament;
                        std::cout << "Nume echipament: ";
                        if (std::getline(std::cin, numeEchipament)) {
                            salaMea.adaugaechipament(Echipament(numeEchipament));
                        }
                    }
                } catch (const std::exception& e) { std::cout << "Eroare: " << e.what() << "\n"; }
                break;
            }
            case 2: {
                std::string numeAngajat;
                double salariuNou;
                std::cout << "Nume angajat: ";
                std::cin.ignore();
                if (!std::getline(std::cin, numeAngajat)) break;
                std::cout << "Salariu nou: ";
                if (!(std::cin >> salariuNou)) break;

                try {
                    if (salariuNou < 0 || salariuNou > 10000) {
                        throw ExceptieValidare("Salariu invalid! Trebuie sa fie intre 0 si 10000.");
                    }

                    if (salaMea.modificaSalariu(numeAngajat, salariuNou)) {
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
                std::cout<<"Sters!"<<'\n';
                break;
            case 0:
                std::cout<<"Iesire"<<'\n';
                break;
        }
    }
}