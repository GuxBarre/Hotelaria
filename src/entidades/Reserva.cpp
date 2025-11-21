#include "Reserva.h"

Reserva::Reserva() {
}

Reserva::~Reserva() {
}

void Reserva::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo Reserva::getCodigo() const {
    return this->codigo;
}

void Reserva::setChegada(const Data& chegada) {
    this->chegada = chegada;
}

Data Reserva::getChegada() const {
    return this->chegada;
}

void Reserva::setPartida(const Data& partida) {
    this->partida = partida;
}

Data Reserva::getPartida() const {
    return this->partida;
}

void Reserva::setValor(const Dinheiro& valor) {
    this->valor = valor;
}

Dinheiro Reserva::getValor() const {
    return this->valor;
}