#pragma once
#include <stdexcept>
#include <string>

class ExceptieSala:public std::runtime_error{
public:
    explicit ExceptieSala(const std::string& mesaj);
};

class ExceptieValidare:public std::logic_error{
public:
    explicit ExceptieValidare(const std::string& mesaj);
};