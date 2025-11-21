#ifndef SENHA_H
#define SENHA_H

#include <string>
#include <stdexcept>
#include <iostream>

/**
 * @class Senha
 * @brief Representa o domínio de senha para autenticação de gerentes.
 * * @details
 * Regras de formato válido conforme especificação:
 * - **Tamanho**: Exatamente 5 caracteres.
 * - **Caracteres permitidos**: Letras (A-Z, a-z), dígitos (0-9) e caracteres especiais (! " # $ % & ?).
 * - **Regras de Sequência**: 
 * - Letra não pode ser seguida por letra.
 * - Dígito não pode ser seguido por dígito.
 * - **Regras de Composição**: Deve conter pelo menos uma letra maiúscula, uma letra minúscula, um dígito e um caractere especial.
 */
class Senha {
private:
    std::string valor;

    /**
     * @brief Valida a senha segundo regras complexas de composição e sequência.
     * * @param senha A string a ser validada.
     * @throw std::invalid_argument Se a senha não tiver tamanho 5, contiver caracteres inválidos, possuir tipos consecutivos proibidos ou não tiver a composição mínima exigida.
     */
    void validar(std::string senha);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com estado vazio.
     */
    Senha(); 

    /**
     * @brief Construtor de inicialização.
     * * @param senha String da senha.
     * @throw std::invalid_argument Se a senha for inválida.
     */
    Senha(std::string senha); 
    
    virtual ~Senha();

    /**
     * @brief Define a senha.
     * * Executa a validação completa antes de armazenar.
     * * @param senha String com 5 caracteres atendendo a todos os critérios de segurança.
     * @throw std::invalid_argument Em caso de violação de qualquer regra de validação.
     */
    void setValor(std::string senha);

    /**
     * @brief Recupera a senha armazenada.
     * * @return std::string A senha atual.
     */
    std::string getValor() const;
};

#endif // SENHA_H