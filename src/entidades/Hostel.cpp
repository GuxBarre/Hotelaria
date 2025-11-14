#include "Hotel.h"

Hotel::Hotel(const Nome& nome, const Endereco& endereco, const Telefone& telefone, const Codigo& codigo)
    : nome(nome), endereco(endereco), telefone(telefone), codigo(codigo) {
}

void Hotel::setNome(const Nome& nome) {
    this->nome = novoNome;
}

Nome Hotel::getNome() const {
    return this->nome;
}

void Hotel::setEndereco(const Endereco& novoEndereco) {
    this->endereco = novoEndereco;
}

Endereco Hotel::getEndereco() const {
    return this->endereco;
}

void Hotel::setTelefone(const Telefone& novoTelefone) {
    this->telefone = novoTelefone;
}

Telefone Hotel::getTelefone() const {
    return this->telefone;
}

Codigo Hotel::getCodigo() const {
    return this->codigo;
}