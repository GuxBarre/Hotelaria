#include "Codigo.h"
#include <cctype>

void Codigo::validar(const std::string& codigo) const {
    if (codigo.length() != 10) {
        throw std::invalid_argument("Codigo deve ter exatamente 10 caracteres.");
    }

    for (char c : codigo) {
        if (!isalnum(c)) {
            throw std::invalid_argument("Codigo deve conter apenas letras e numeros.");
        }
    }
}

Codigo::Codigo() {
    this->valor = "";
}

Codigo::Codigo(const std::string& codigo) {
    setCodigo(codigo);
}

void Codigo::setCodigo(const std::string& codigo) {
    validar(codigo);
    this->valor = codigo;
}

std::string Codigo::getCodigo() const {
    return this->valor;
}