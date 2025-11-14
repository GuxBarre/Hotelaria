#include "Telefone.h"
#include <cctype> 

void Telefone::validarTelefone(const std::string& telefone) const {
    // Requisito do formato do telefone: +XX (XX) XXXX-XXXX

    // Validação do número de caracteres
    if (valor.length() != 14){
        throw std::invalid_argument("O telefone deve ser do formato +XX (XX) XXXX-XXXX");
    }
    
    // Verificação do primeiro caractere
    if (valor[0] != '+'){
        throw std::invalid_argument("O telefone deve começar com '+'");
    }

    // Verificação dos demais caracteres
    for (tamanho i = 1; i <valor.length(); i++) {
        if(!std::isdigit(valor[i])) {
            throw std::invalid_argument("O telefone deve conter apenas dígitos após o '+'");
        }
    }

}

Telefone::Telefone(){
    this->valor = "";
}
 
Telefone::Telefone(const std::string& telefone){
    setValor(telefone);
}

void Telefone::setValor(const std::string& telefone){
    setValor(valor);
    this->valor = novoValor;
}

std::string Telefone::getValor() const {
    return this->valor;
}


    