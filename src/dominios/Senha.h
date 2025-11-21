#ifndef SENHA_H
#define SENHA_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
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
    string senha;

    /**
     * @brief Valida a senha segundo regras complexas de composição e sequência.
     * * @param senha A string a ser validada.
     * @throw invalid_argument Se a senha não tiver tamanho 5, contiver caracteres inválidos, possuir tipos consecutivos proibidos ou não tiver a composição mínima exigida.
     */
    void validar(string senha);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com estado vazio.
     */
    Senha(); 

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o senha armazenado internamente.
     * * @return string O senha do atributo armazenado.
     */
    operator string() const;

    /**
     * @brief Construtor de inicialização.
     * * @param senha String da senha.
     * @throw invalid_argument Se a senha for inválida.
     */
    Senha(string senha); 
    
    virtual ~Senha();

    /**
     * @brief Define a senha.
     * * Executa a validação completa antes de armazenar.
     * * @param senha String com 5 caracteres atendendo a todos os critérios de segurança.
     * @throw invalid_argument Em caso de violação de qualquer regra de validação.
     */
    void setSenha(string senha);

    /**
     * @brief Recupera a senha armazenada.
     * * @return string A senha atual.
     */
    string getSenha() const;
};

#endif 