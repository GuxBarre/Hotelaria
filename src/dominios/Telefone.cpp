#include "Telefone.h"
#include <cctype> 

void Telefone::validarTelefone(const std::string& telefone) const {
    if (telefone.length() != 15){
        throw std::invalid_argument("O telefone deve ter exatamente 15 caracteres (Formato: +DDDDDDDDDDDDDD).");
    }

    if (telefone[0] != '+'){
        throw std::invalid_argument("O telefone deve começar com '+'");
    }

    for (size_t i = 1; i < telefone.length(); i++) {
        if(!std::isdigit(telefone[i])) {
            throw std::invalid_argument("O telefone deve conter apenas dígitos após o '+'");
        }
    }
}

Telefone::Telefone(){
    this->valor = "";
}

Telefone::Telefone(const std::string& telefone){
    setTelefone(telefone);
}

void Telefone::setTelefone(const std::string& telefone){
    validarTelefone(telefone); 
    this->valor = telefone;
}

std::string Telefone::getTelefone() const {
    return this->valor;
}