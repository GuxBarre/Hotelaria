#include "Numero.h"

using namespace std;

Numero::Numero() {
    this->valor = 1;
}

Numero::Numero(int valor) {
    setNumero(valor);
}

Numero::~Numero() {
}

void Numero::validar(int valor) {
    if (valor < 1 || valor > 999) {
        throw invalid_argument("Erro: Numero deve estar entre 1 e 999.");
    }
}

void Numero::setNumero(int valor) {
    validar(valor);
    this->valor = valor;
}

int Numero::getNumero() const {
    return valor;
}