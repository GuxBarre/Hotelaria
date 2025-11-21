#ifndef TELEFONE_H
#define TELEFONE_H

#include <string>
#include <stdexcept>
using namespace std;

/**
 * @brief Classe responsável por armazenar e validar um número de telefone.
 * Formato esperado: +XXYYZZZZZZZZZ (Ex: +5511988887777) - Total 14 caracteres.
 * Nota: O código valida apenas dígitos após o '+', ignorando formatação visual como '(', ')' ou '-'.
 */
class Telefone {
    private:
        string telefone; ///< Armazena o número do telefone.

        /**
         * @brief Valida o formato do telefone.
         * Regras:
         * 1. Deve ter exatamente 14 caracteres.
         * 2. Deve começar com '+'.
         * 3. O restante deve ser apenas números.
         * @param telefone A string a ser verificada.
         * @throw invalid_argument Se o formato for inválido.
         */
        void validarTelefone(const string& telefone) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa vazio.
         */
        Telefone();

        /**
         * @brief Sobrecarga do operador de conversão para string.
         * * Permite que o objeto seja convertido implicitamente para uma string,
         * retornando o telefone armazenado internamente.
         * * @return string O telefone do atributo armazenado.
         */
        operator string() const;

        /**
         * @brief Construtor com validação.
         * @param telefone O número a ser armazenado.
         * @throw invalid_argument Se o telefone for inválido.
         */
        explicit Telefone(const string& telefone);

        /**
         * @brief Define um novo número.
         * @param telefone O novo número.
         * @throw invalid_argument Se o formato for incorreto.
         */
        void setTelefone(const string& telefone);

        /**
         * @brief Retorna o telefone armazenado.
         * @return string O número do telefone.
         */
        string getTelefone() const;
};

#endif