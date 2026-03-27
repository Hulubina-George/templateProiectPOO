#pragma once
#include <stdexcept>
#include <string>

class ExceptieSala : public std::runtime_error {
public:
    explicit ExceptieSala(const std::string& mesaj) : std::runtime_error(mesaj) {}
};

class ExceptieValidare : public std::runtime_error {
public:
    explicit ExceptieValidare(const std::string& mesaj) : std::runtime_error(mesaj) {}
};