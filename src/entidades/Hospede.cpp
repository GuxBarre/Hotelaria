#include "Hospede.h"

Hospede::Hospede(const Nome& nome, const Email& email, const Endereco& endereco, const Cartao& cartao)
    : Pessoa(nome, email), 
    endereco(endereco), 
    cartao(cartao) {
}

void Hospede::setEndereco(const Endereco& endereco) {
    this->endereco = novoEndereco;
}

Endereco Hospede::getEndereco() const {
    return this->endereco;
}

void Hospede::setCartao(const Cartao& cartao) {
    this->cartao = novoCartao;
}

Cartao Hospede::getCartao() const {
    return this->cartao;
}