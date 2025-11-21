#include "Capacidade.h"
#include <string> 

void Capacidade::validar(int valor) const {
    if (valor < 1 || valor > 4) {
        throw std::invalid_argument("Capacidade invalida. Valores permitidos: 1, 2, 3 ou 4.");
    }
}

Capacidade::Capacidade() {
    this->valor = 0;
}

Capacidade::Capacidade(int valor) {
    setValor(valor);
}

void Capacidade::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

int Capacidade::getValor() const {
    return this->valor;
}