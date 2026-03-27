#include "ExceptieSala.h"

ExceptieSala::ExceptieSala(const std::string& mesaj) : std::runtime_error(mesaj) {}

ExceptieValidare::ExceptieValidare(const std::string& mesaj) : std::runtime_error(mesaj) {}