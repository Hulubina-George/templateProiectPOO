#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Echipament{
private:
    std::string numeEchipament;
    static int numarTotalEchipamente;
public:
    explicit Echipament(const std::string& nume);
    static int getNumarTotal();
    void info() const;
    nlohmann::json toJson() const;
};