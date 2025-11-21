#include "Quarto.h"

Quarto::Quarto() {
}

Quarto::~Quarto() {
}

void Quarto::setNumero(const Numero& numero) {
    this->numero = numero;
}
Numero Quarto::getNumero() const {
    return this->numero;
}

void Quarto::setCapacidade(const Capacidade& capacidade) {
    this->capacidade = capacidade;
}
Capacidade Quarto::getCapacidade() const {
    return this->capacidade;
}

void Quarto::setDiaria(const Dinheiro& diaria) {
    this->diaria = diaria;
}
Dinheiro Quarto::getDiaria() const {
    return this->diaria;
}

void Quarto::setRamal(const Ramal& ramal) {
    this->ramal = ramal;
}
Ramal Quarto::getRamal() const {
    return this->ramal;
}