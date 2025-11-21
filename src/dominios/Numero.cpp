#include "Numero.h"
#include <string> 

using namespace std;

Numero::Numero() {
    this->numero = 1;
}

Numero::Numero(int numero) {
    setNumero(numero);
}

Numero::~Numero() {
}

void Numero::validar(int numero) {
    if (numero < 1 || numero > 999) {
        throw invalid_argument("Numero deve estar entre 1 e 999.");
    }
}

void Numero::setNumero(int numero) {
    validar(numero);
    this->numero = numero;
}

int Numero::getNumero() const {
    return numero;
}

Numero::operator string() const {
    return to_string(numero);
}