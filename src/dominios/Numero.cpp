#include "Numero.h"

using namespace std;

Numero::Numero() {
    this->valor = 1; // Inicializa com um valor válido padrão
}

Numero::Numero(int valor) {
    setValor(valor);
}

Numero::~Numero() {
}

void Numero::validar(int valor) {
    // Regra: 001 a 999
    if (valor < 1 || valor > 999) {
        throw invalid_argument("Erro: Numero deve estar entre 1 e 999.");
    }
}

void Numero::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

int Numero::getValor() const {
    return valor;
}