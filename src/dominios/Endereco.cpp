#include "Endereco.h"

void Endereco::validarEndereco(const std::string& endereco) const {
    // Texto deve ter 5 a 30 caracteres
    if(valor.length() < 5 || valor.length() > 30) {}
    
}
    
Endereco::Endereco(){
    this->valor = "";
} 

Endereco::Endereco::setValor(const std::string& endereco){
    setValor();
}

Endereco::Endereco(const std::string& endereco){
    validarEndereco(endereco);
    this->valor = endereco;
}

std::string Endereco::getEndereco() const {
    return this->valor;
}