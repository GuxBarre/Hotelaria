#include "Cartao.h"

Cartao::Cartao() {
    this->numero = ""; 
}

Cartao::Cartao(const string& numero) {
    setCartao(numero);
}

void Cartao::setCartao(const string& numero) {
    validar(numero); 
    this->numero = numero;
}

string Cartao::getCartao() const {
    return this->numero;
}

void Cartao::validar(const string& numero) const {
    if (numero.length() != 16) {
        throw invalid_argument("Erro: O cartao deve possuir exatamente 16 digitos.");
    }

    for (char c : numero) {
        if (!isdigit(c)) {
            throw invalid_argument("Erro: O cartao deve conter apenas numeros.");
        }
    }
    if (!validarLuhn(numero)) {
        throw invalid_argument("Erro: Numero de cartao invalido (Falha na verificacao de Luhn).");
    }
}

bool Cartao::validarLuhn(const string& numero) const {
    int soma = 0;
    bool dobrar = false;

    for (int i = numero.length() - 1; i >= 0; i--) {
        int n = numero[i] - '0';

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