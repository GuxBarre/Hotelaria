#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
/**
 * @class Email
 * @brief Representa o domínio de endereço de e-mail.
 * * @details
 * Regras de formato válido:
 * - Formato: parte-local@domínio.
 * - **Parte local**: Até 64 caracteres. Pode conter letra (a-z), dígito (0-9), ponto (.) ou hífen (-).
 * Não pode iniciar ou terminar com ponto ou hífen. Ponto ou hífen deve ser seguido por letra ou dígito.
 * - **Domínio**: Até 255 caracteres. Composto por partes separadas por ponto (.).
 * Cada parte pode conter letra (a-z), dígito (0-9) ou hífen (-). Não pode iniciar ou terminar com hífen.
 */
class Email {
private:
    string email;

    /**
     * @brief Valida o formato do e-mail segundo as regras estabelecidas.
     * * @param email A string do e-mail a ser validada.
     * @throw invalid_argument Se o e-mail violar qualquer regra de formatação (tamanho, caracteres proibidos ou posição incorreta de pontuação).
     */
    void validar(string email);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com estado vazio.
     */
    Email(); 

    /**
     * @brief Construtor de inicialização.
     * * Já realiza a validação do e-mail fornecido na criação do objeto.
     * * @param email String contendo o endereço de e-mail.
     * @throw invalid_argument Se o formato for inválido.
     */
    Email(string email);
    
    virtual ~Email();

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o valor armazenado internamente.
     * * @return string O valor do atributo armazenado.
     */
    operator string() const;

    /**
     * @brief Define o endereço de e-mail.
     * * @param email String contendo o e-mail no formato parte-local@domínio.
     * @throw invalid_argument Se o formato for inválido (ex: exceder 64 caracteres na parte local ou 255 no domínio).
     */
    void setEmail(string email);

    /**
     * @brief Recupera o endereço de e-mail armazenado.
     * * @return string O e-mail atual.
     */
    string getEmail() const;
};

#endif