#include "Hotel.h"

Hotel::Hotel() {}

Hotel::~Hotel() {
}

void Hotel::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Hotel::getNome() const {
    return this->nome;
}

void Hotel::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

Endereco Hotel::getEndereco() const {
    return this->endereco;
}

void Hotel::setTelefone(const Telefone& telefone) {
    this->telefone = telefone;
}

Telefone Hotel::getTelefone() const {
    return this->telefone;
}

void Hotel::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo Hotel::getCodigo() const {
    return this->codigo;
}