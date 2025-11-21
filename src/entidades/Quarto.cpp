#include "Quarto.h"

// Número
void Quarto::setNumero(const Numero &numero) {
    this->numero = numero;
}

Numero Quarto::getNumero() const {
    return numero;
}

// Capacidade
void Quarto::setCapacidade(const Capacidade &capacidade) {
    this->capacidade = capacidade;
}

Capacidade Quarto::getCapacidade() const {
    return capacidade;
}

// Diária
void Quarto::setDiaria(const Dinheiro &diaria) {
    this->diaria = diaria;
}

Dinheiro Quarto::getDiaria() const {
    return diaria;
}
