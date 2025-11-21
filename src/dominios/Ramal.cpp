#include "Ramal.h"

using namespace std;

Ramal::Ramal() {
    this->valor = 0; // Inicializa com um valor válido padrão (00)
}

Ramal::Ramal(int valor) {
    setValor(valor);
}

Ramal::~Ramal() {
}

void Ramal::validar(int valor) {
    // Regra: 00 a 50
    if (valor < 0 || valor > 50) {
        throw invalid_argument("Erro: Ramal deve estar entre 0 e 50.");
    }
}

void Ramal::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

int Ramal::getValor() const {
    return valor;
}