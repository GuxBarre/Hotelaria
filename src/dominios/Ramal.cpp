#include "Ramal.h"

using namespace std;

Ramal::Ramal() {
    this->valor = 0; 
}

Ramal::Ramal(int valor) {
    setRamal(valor);
}

Ramal::~Ramal() {
}

void Ramal::validar(int valor) {
    if (valor < 0 || valor > 50) {
        throw invalid_argument("Erro: Ramal deve estar entre 0 e 50.");
    }
}

void Ramal::setRamal(int valor) {
    validar(valor);
    this->valor = valor;
}

int Ramal::getRamal() const {
    return valor;
}