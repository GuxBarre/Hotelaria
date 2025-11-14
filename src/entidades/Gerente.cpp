#include "Gerente.h"

Gerente::Gerente(const Nome& nome, const Email& email, const Ramal& ramal, const Senha& senha)
    : Pessoa(nome, email), ramal(ramal), senha(senha) {

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