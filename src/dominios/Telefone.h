#ifndef TELEFONE_H
#define TELEFONE_H

#include <string>
#include <stdexcept>

/**
 * @brief Classe responsável por armazenar e validar um número de telefone.
 * Formato esperado: +XXYYZZZZZZZZZ (Ex: +5511988887777) - Total 14 caracteres.
 * Nota: O código valida apenas dígitos após o '+', ignorando formatação visual como '(', ')' ou '-'.
 */
class Telefone {
    private:
        std::string valor; ///< Armazena o número do telefone.

        /**
         * @brief Valida o formato do telefone.
         * Regras:
         * 1. Deve ter exatamente 14 caracteres.
         * 2. Deve começar com '+'.
         * 3. O restante deve ser apenas números.
         * @param telefone A string a ser verificada.
         * @throw std::invalid_argument Se o formato for inválido.
         */
        void validarTelefone(const std::string& telefone) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa vazio.
         */
        Telefone();

        /**
         * @brief Construtor com validação.
         * @param telefone O número a ser armazenado.
         * @throw std::invalid_argument Se o telefone for inválido.
         */
        explicit Telefone(const std::string& telefone);

        /**
         * @brief Define um novo número.
         * @param telefone O novo número.
         * @throw std::invalid_argument Se o formato for incorreto.
         */
        void setTelefone(const std::string& telefone);

        /**
         * @brief Retorna o telefone armazenado.
         * @return std::string O número do telefone.
         */
        std::string getTelefone() const;
};

#endif