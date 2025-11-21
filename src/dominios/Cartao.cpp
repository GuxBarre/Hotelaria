#include "Cartao.h"
using namespace std;

Cartao::Cartao() {
    this->cartao = ""; 
}

Cartao::Cartao(const string& cartao) {
    setCartao(cartao);
}

void Cartao::setCartao(const string& cartao) {
    validar(cartao); 
    this->cartao = cartao;
}

string Cartao::getCartao() const {
    return this->cartao;
}

void Cartao::validar(const string& cartao) const {
    if (cartao.length() != 16) {
        throw invalid_argument("O cartao deve possuir exatamente 16 digitos.");
    }

    for (char c : cartao) {
        if (!isdigit(c)) {
            throw invalid_argument("O cartao deve conter apenas cartaos.");
        }
    }
    if (!validarLuhn(cartao)) {
        throw invalid_argument("Cartao invalido (Falha na verificacao de Luhn).");
    }
}

bool Cartao::validarLuhn(const string& cartao) const {
    int soma = 0;
    bool dobrar = false;

    for (int i = cartao.length() - 1; i >= 0; i--) {
        int n = cartao[i] - '0';

        if (dobrar) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }

        soma += n;
        dobrar = !dobrar; 
    }

    return (soma % 10 == 0);
}

Cartao::operator string() const {
    return cartao;
}