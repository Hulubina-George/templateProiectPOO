#pragma once

class StrategieBonus{
    public:
        virtual ~StrategieBonus() = default;
        virtual double calculeazaBonus(double salariuBaza) const = 0;
};

class BonusSarbatori : public StrategieBonus {
    public:
        double calculeazaBonus(double salariuBaza) const override {
            return salariuBaza * 0.2; // bonus de 20% sarbatori din salalriul de baza
        }
};

class BonusPerformanta : public StrategieBonus {
    public:
        double calculeazaBonus(double) const override {
            return 1000.0; // bonus fix pentru performanta
        }
};

class FaraBonus : public StrategieBonus {
    public:
        double calculeazaBonus(double) const override {
            return 0.0; // fara bonus
        }
};

