Sistem Gestiune Sala de Fitness - Proiect POO

    1. Proiectul este un sistem interactiv de gestiune a unei sali de fitness, in care utilizatorul poate administra baza de date cu angajati, clienti si echipamente.

    2. Proiectul este structurat pe 12 clase interconectate, fiecare servind un rol esential.

    3. Minim 6 clase trebuie sa fie implicate intr-o structura de mostenire. Acestea sunt -Persoana- (Clasa de baza-Nivelul 0), -Client- (Derivă direct din Persoana-Nivelul 1), -Angajat- (Derivă direct din Persoana-Nivelul 1), -AngajatFitness- (Derivă din Angajat-Nivelul 2) -AngajatNutritie- (Derivă din Angajat-Nivelul 2) -AngajatDublu- (Derivă simultan din AngajatFitness și AngajatNutritie-Nivelul 3). Astfel am rezolvat si problema mostenirii in diamant.

    4. Metode si membrii static sunt folosite in interiorul clasei Echipament, avand rol in retinerea numarului Global de echipamente din sala, nu a fiecarui echipament diferit.

    5. Regula celor 3 a fost folosita in clasa -Sala-, unde se si gestioneaza alocarea dinamica si stocarea in vectori a tuturor persoanelor si echipamentelor.

    6.Polimorfism: Utilizarea metodelor virtual si a claselor abstracte (metode virtuale pure). Aceasta cerinta  a fost rezolvata in clasa -Persoana-: virtual void info() const=0; In clasele: -Client-, -Angajat-, -AngajatDublu-, etc, am implementat functia.

    7.Tratarea exceptiilor a fost abordata in interiorul clasei Meniu. Salariul trebuie sa fie mai mare decat 0 si mai mic decat 10.000. Daca nu este introdus un numar ce convine, se returneaza o eroare. blocurile try-catch au fost folosite, asadar, la crearea angajatului si modificarea salariului. Exceptiile au fost derivate din std::exception in clasa -ExceptieSala-.

    8.Meniul aplicatiei se gaseste in clasa -Meniu-, ce are ca rol comunicarea cu utilizatorul si utilizeaza metode din clasa -Sala-. Clasa -Sala- tine evidenta persoanelor si echipamentului, avand metodele prin care se adauga si se sterg perosanele din sistem, etc.