#include "Capacidade.h"
#include <string> 

using namespace std;

void Capacidade::validar(int capacidade) const {
    if (capacidade < 1 || capacidade > 4) {
        throw std::invalid_argument("Capacidade invalida. capacidadees permitidos: 1, 2, 3 ou 4.");
    }
}

Capacidade::Capacidade() {
    this->capacidade = 1;
}

Capacidade::Capacidade(int capacidade) {
    setCapacidade(capacidade);
}

void Capacidade::setCapacidade(int capacidade) {
    validar(capacidade);
    this->capacidade = capacidade;
}

int Capacidade::getCapacidade() const {
    return this->capacidade;
}

Capacidade::operator string() const {
    return std::to_string(capacidade);
}