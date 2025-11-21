#include "Codigo.h"
#include <cctype> // Para isalnum (verifica se é letra ou número)

void Codigo::validar(const std::string& codigo) const {
    // 1. Validação de tamanho (Exatamente 10 caracteres)
    if (codigo.length() != 10) {
        throw std::invalid_argument("Codigo deve ter exatamente 10 caracteres.");
    }

    // 2. Validação de conteúdo (Apenas letras e números)
    for (char c : codigo) {
        // isalnum verifica se é letra (A-Z, a-z) ou dígito (0-9)
        if (!isalnum(c)) {
            throw std::invalid_argument("Codigo deve conter apenas letras e numeros.");
        }
    }
}

Codigo::Codigo() {
    this->valor = "";
}

Codigo::Codigo(const std::string& codigo) {
    setValor(codigo);
}

void Codigo::setValor(const std::string& codigo) {
    validar(codigo);
    this->valor = codigo;
}

std::string Codigo::getValor() const {
    return this->valor;
}