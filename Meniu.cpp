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
        std::cout<<'\n'<<"MENIU GESTIUNE SALA"<<'\n';
        std::cout<<"1. Crearea de obiecte noi"<<'\n';
        std::cout<<"2. Modificare Salariu Angajat"<<'\n';
        std::cout<<"3. Afisare informatii"<<'\n';
        std::cout<<"4. Stergerea elementelor"<<'\n';
        std::cout<<"0. Iesire"<<'\n';
        std::cout<<"Alege o optiune: ";
        std::cin>>optiune;

        switch(optiune){
            case 1:{
                int subOptiune;
                std::cout<<'\n'<<"Ce doresti sa creezi?"<<'\n';
                std::cout<<"1. Client"<<'\n'<<"2. Angajat Fitness"<<'\n'<<"3. Angajat Nutritie"<<'\n'<<"4. Angajat Dublu"<<'\n'<<"5. Echipament"<<'\n';
                std::cout << "Alegerea ta: ";
                std::cin >> subOptiune;

                std::string nume;
                std::cin.ignore();
                
                try{
                    if (subOptiune >= 1 && subOptiune <= 4){
                        std::cout<<"Nume persoana: ";
                        std::getline(std::cin, nume);
                        int varsta;
                        std::cout<<"Varsta: ";
                        std::cin>>varsta;

                        if (subOptiune == 1){
                            int vizite;
                            std::cout<<"Numar vizite: ";
                            std::cin>>vizite;
                            Abonament ab("Standard", 150.0, 30);
                            salaMea.adaugapersoana(new Client(varsta, nume, vizite, ab));
                        } 
                        else if (subOptiune == 2){
                            double salariu; 
                            std::string antrenament;
                            std::cout<<"Salariu: "; 
                            std::cin>>salariu;
                            if (salariu<0 || salariu>10000) 
                                throw ExceptieValidare("Salariul trebuie sa fie intre 0 si 10000");

                            std::cout<<"Tip antrenament: "; 
                            std::cin.ignore(); 
                            std::getline(std::cin, antrenament);
                            salaMea.adaugapersoana(new AngajatFitness(varsta, nume, salariu, antrenament));
                        }
                        else if (subOptiune == 3){
                            double salariu; std::string dieta;
                            std::cout<<"Salariu: "; std::cin>>salariu;
                            if (salariu<0 || salariu>10000) 
                                throw ExceptieValidare("Salariul trebuie sa fie intre 0 si 10000");
                            
                            std::cout<<"Tip dieta:";
                            std::cin.ignore();
                            std::getline(std::cin, dieta);
                            salaMea.adaugapersoana(new AngajatNutritie(varsta, nume, salariu, dieta));
                        }
                        else if (subOptiune == 4){
                            double salariu; std::string antrenament, dieta;
                            std::cout << "Salariu: "; std::cin >> salariu;
                            if (salariu < 0 || salariu > 10000) 
                                throw ExceptieValidare("Salariul trebuie sa fie intre 0 si 10.000");
                            std::cout<<"Tip antrenament: "; 
                            std::cin.ignore(); 
                            std::getline(std::cin, antrenament);

                            std::cout << "Tip dieta: "; 
                            std::getline(std::cin, dieta);
                            salaMea.adaugapersoana(new AngajatDublu(varsta, nume, salariu, antrenament, dieta));
                        }
                        std::cout<<"Persoana creata cu succes!"<<'\n';
                    } 
                    else if (subOptiune == 5){
                        std::cout << "Nume echipament: ";
                        std::getline(std::cin, nume);
                        salaMea.adaugaechipament(Echipament(nume));
                        std::cout << "Echipament adaugat\n";
                    }
                } 
                catch (const ExceptieValidare& e){
                    std::cout<<"eroare"<<e.what()<<"\n";
                    std::cout<<"eroare"<<'\n';
                }
                break;
            }
            case 2:{
                std::string numeCautat;
                double salariuNou;
                std::cout<<"Modificare Salariu"<<'\n';
                std::cout<<"Nume angajat: ";
                std::cin.ignore();
                std::getline(std::cin, numeCautat);

                std::cout<<"Salariu nou: ";
                std::cin>>salariuNou;

                try{
                    if (salariuNou < 0 || salariuNou > 10000) {
                        throw ExceptieValidare("eroare, salariu invalid.");
                    }
                    
                    bool gasit = salaMea.modificaSalariu(numeCautat, salariuNou);
                    if (gasit){
                        std::cout<<"salariul actualizat"<<'\n';
                    } else{
                        std::cout<<"angajatul inexistent"<<'\n';
                    }
                } 
                catch (const ExceptieValidare& e) {
                    std::cout<<"eroare"<<e.what()<<"\n";
                }
                break;
            }
            case 3:
                std::cout<<'\n'<<"Afisare baza de date"<<'\n';
                salaMea.info();
                break;
            case 4:
                std::cout<<'\n'<<"Stergere ultima persoana adaugata"<<'\n';
                salaMea.stergeUltimaPersoana();
                break;
            case 0:
                std::cout<<"Am iesit din program"<<'\n';
                break;
            default:
                std::cout<<"optiune invalida"<<'\n';
                break;
        }
    }
}