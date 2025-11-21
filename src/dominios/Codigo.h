#ifndef CODIGO_H
#define CODIGO_H

#include <string>
#include <stdexcept>
using namespace std;
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
        string codigo; 

        /**
         * @brief Verifica se a string atende às regras de negócio.
         * * @param codigo A string a ser verificada.
         * @throw invalid_argument Se o comprimento não for 10 ou se houver caracteres inválidos (não alfanuméricos).
         */
        void validar(const string& codigo) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa o objeto com estado vazio.
         */
        Codigo();

        /**
         * @brief Sobrecarga do operador de conversão para string.
         * * Permite que o objeto seja convertido implicitamente para uma string,
         * retornando o codigo armazenado internamente.
         * * @return string O codigo do atributo armazenado.
         */
        operator string() const;

        /**
         * @brief Construtor que inicializa com um codigo específico.
         * * @param codigo String representando o código (10 caracteres alfanuméricos).
         * @throw invalid_argument Se o formato for inválido.
         */
        explicit Codigo(const string& codigo);

        /**
         * @brief Define o codigo do código.
         * * @param codigo String com 10 caracteres (letras a-z ou dígitos 0-9).
         * @throw std::invalid_argument Caso a regra de validação não seja atendida.
         */
        void setCodigo(const string& codigo);

        /**
         * @brief Obtém o código armazenado.
         * * @return string O código atual.
         */
        std::string getCodigo() const;
};

#endif