#include "Gerente.h"


Gerente::Gerente() {
}

Gerente::~Gerente() {
}

void Gerente::setRamal(const Ramal& ramal) {
    this->ramal = ramal;
}

Ramal Gerente::getRamal() const {
    return this->ramal;
}

void Gerente::setSenha(const Senha& senha) {
    this->senha = senha;
}

Senha Gerente::getSenha() const {
    return this->senha;
}