#ifndef CODIGO_H
#define CODIGO_H

#include <string>
#include <stdexcept>

/**
 * @class Codigo
 * @brief Representa o domínio de Código de identificação.
 * * @details
 * Regras de formato válido conforme especificação:
 * - Deve conter exatamente 10 caracteres[cite: 53].
 * - Cada caractere deve ser uma letra (a-z) ou um dígito (0-9)[cite: 54].
 * * Este identificador é utilizado como chave primária para Hotéis e Reservas.
 */
class Codigo {
    private:
        std::string valor; 

        /**
         * @brief Verifica se a string atende às regras de negócio.
         * * @param codigo A string a ser verificada.
         * @throw std::invalid_argument Se o comprimento não for 10 ou se houver caracteres inválidos (não alfanuméricos).
         */
        void validar(const std::string& codigo) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa o objeto com estado vazio.
         */
        Codigo();

        /**
         * @brief Construtor que inicializa com um valor específico.
         * * @param codigo String representando o código (10 caracteres alfanuméricos).
         * @throw std::invalid_argument Se o formato for inválido.
         */
        explicit Codigo(const std::string& codigo);

        /**
         * @brief Define o valor do código.
         * * @param codigo String com 10 caracteres (letras a-z ou dígitos 0-9).
         * @throw std::invalid_argument Caso a regra de validação não seja atendida.
         */
        void setValor(const std::string& codigo);

        /**
         * @brief Obtém o código armazenado.
         * * @return std::string O código atual.
         */
        std::string getValor() const;
};

#endif