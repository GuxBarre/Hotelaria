#include "Dinheiro.h"
#include <cmath> // Necessário para a função round()

Dinheiro::Dinheiro() {
    this->valorCentavos = 0;
}

Dinheiro::Dinheiro(double valor) {
    setValor(valor);
}

Dinheiro::~Dinheiro() {
}

void Dinheiro::validar(long long valor) {
    // Faixa: 0,01 a 1.000.000,00
    // Em centavos: 1 a 100.000.000
    if (valor < 1 || valor > 100000000) {
        throw std::invalid_argument("Erro: Valor monetario deve estar entre 0,01 e 1.000.000,00.");
    }
}

void Dinheiro::setValor(double valor) {
    // AQUI ESTÁ O TRUQUE DO ARMAZENAMENTO INTEIRO:
    // Multiplicamos por 100 e arredondamos para o inteiro mais próximo.
    // Ex: 10.50 vira 1050.
    // Usamos llround (long long round) para evitar truncamento errado de float (ex: 10.499999 virar 1049).
    long long centavos = std::llround(valor * 100);
    
    validar(centavos);
    
    this->valorCentavos = centavos;
}

double Dinheiro::getValor() const {
    // Para devolver, dividimos por 100.0 para voltar a ser decimal
    return valorCentavos / 100.0;
}