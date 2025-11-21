#include "Dinheiro.h"
#include <cmath>

Dinheiro::Dinheiro() {
    this->valorCentavos = 0;
}

Dinheiro::Dinheiro(double valor) {
    setDinheiro(valor);
}

Dinheiro::~Dinheiro() {
}

void Dinheiro::validar(long long valor) {
    if (valor < 1 || valor > 100000000) {
        throw std::invalid_argument("Erro: Valor monetario deve estar entre 0,01 e 1.000.000,00.");
    }
}

void Dinheiro::setDinheiro(double valor) {
    long long centavos = std::llround(valor * 100);
    
    validar(centavos);
    
    this->valorCentavos = centavos;
}

double Dinheiro::getDinheiro() const {
    return valorCentavos / 100.0;
}