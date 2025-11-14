#include "Pessoa.h"

// Implementando a classe Pessoa
Pessoa::Pessoa(const Nome& nome, const Email& email) : nome(nome), email(email){

    //Definir email
}

void Pessoa::setNome(const Nome& nome) {
    this->nome = novoNome;
}

Nome Pessoa::getNome() const {
    return this->nome;
}

Email Pessoa::getEmail() const {
    return this->email;
}