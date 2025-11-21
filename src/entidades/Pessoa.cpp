#include "Pessoa.h"

Pessoa::Pessoa() {
}

Pessoa::~Pessoa() {
}

void Pessoa::setNome(const Nome& nome) {
    this->nome = nome;
}

void Pessoa::setEmail(const Email& email) {
    this->email = email;
}

Nome Pessoa::getNome() const {
    return this->nome;
}

Email Pessoa::getEmail() const {
    return this->email;
}