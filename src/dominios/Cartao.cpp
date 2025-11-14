#include "Cartao.h"
#include <cctype> 
#include <algorithm> 

bool Cartao::validarLuhn(const std::string& numero) const {
    int soma = 0;
    bool dobrar = false;

    for (int i = numero.length() - 1; i >= 0; i--) {
        int digito = numero[i] - '0';

        if (dobrar) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }

        soma += digito;
        dobrar = !dobrar;
    }
    return (soma % 10) == 0;
}

void Cartao::validar(const std::string& numero) const {
    // Verifica o comprimento
    if (valor.length() != 16) {
        throw std::invalid_argument("O cartão deve possuir 16 dígitos");
    }

    // Verifica se todos são dígitos
    for (char c : valor){
        if (!std::isdigit(c)){
            throw std::invalid_argument("O cartão deve conter apenas dígitos");
        }
    }

    // Valida pelo algoritmo de Luhn
    if (!validarLuhn(valor)){
        throw std::invalid_argument("Número de cartão inválido pelo algoritmo de Luhn");
    }
}

Cartao::Cartao(){
    this->numero = "";
}

Cartao::Cartao(const std::string& numero){
    setValor(numero);
}
    
void Cartao::setValor(const std::string& numero){
    validar(numero);
    this->numero = numero
}

std::string Cartao::getValor() const {
    return this->numero;
}