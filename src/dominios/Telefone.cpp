#include "Telefone.h"
#include <cctype> 

/**
 * @brief Implementação da validação.
 * Importante: Valida o PARÂMETRO 'telefone', não o atributo 'this->valor'.
 */
void Telefone::validarTelefone(const std::string& telefone) const {
    // Requisito da imagem: +DDDDDDDDDDDDDD (14 dígitos após o +)
    // Total de caracteres: 15

    // 1. Validação do tamanho exato
    if (telefone.length() != 15){
        throw std::invalid_argument("O telefone deve ter exatamente 15 caracteres (Formato: +DDDDDDDDDDDDDD).");
    }
    
    // 2. Começar com '+'
    if (telefone[0] != '+'){
        throw std::invalid_argument("O telefone deve começar com '+'");
    }

    // 3. O restante deve ser digito (0-9)
    for (size_t i = 1; i < telefone.length(); i++) {
        if(!std::isdigit(telefone[i])) {
            throw std::invalid_argument("O telefone deve conter apenas dígitos após o '+'");
        }
    }
}

/**
 * @brief Construtor padrão.
 */
Telefone::Telefone(){
    this->valor = "";
}
 
/**
 * @brief Construtor com parâmetros.
 * Chama setValor para aproveitar a validação.
 */
Telefone::Telefone(const std::string& telefone){
    setValor(telefone);
}

/**
 * @brief Setter do valor.
 */
void Telefone::setValor(const std::string& telefone){
    // Correção: Chama a validação antes de atribuir
    validarTelefone(telefone); 
    
    // Correção: Atribui o parâmetro 'telefone' ao atributo 'valor'.
    // 'novoValor' não existia no escopo.
    this->valor = telefone;
}

/**
 * @brief Getter do valor.
 */
std::string Telefone::getValor() const {
    return this->valor;
}