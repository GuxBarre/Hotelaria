#include "Hospede.h"


Hospede::Hospede() {}

Hospede::~Hospede() {
}

void Hospede::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

Endereco Hospede::getEndereco() const {
    return this->endereco;
}

void Hospede::setCartao(const Cartao& cartao) {
    this->cartao = cartao;
}

Cartao Hospede::getCartao() const {
    return this->cartao;
}