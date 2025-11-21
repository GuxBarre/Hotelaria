#ifndef CARTAO_H
#define CARTAO_H

#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

/**
 * @brief Classe responsável por representar e validar um número de cartão de crédito.
 * * Esta classe armazena um número de cartão e garante que ele atenda aos requisitos:
 * - Ter exatamente 16 dígitos numéricos.
 * - Ser válido segundo o algoritmo de Luhn (verificação de dígito verificador).
 */
class Cartao {
    private:
        string numero; ///< Armazena a sequência numérica do cartão.
        
        /**
         * @brief Valida as regras de negócio do cartão.
         * Verifica o tamanho (16 dígitos), se são apenas números e o algoritmo de Luhn.
         * * @param numero A string contendo o número a ser validado.
         * @throw std::invalid_argument Se o número não atender aos critérios de validação.
         */
        void validar(const string& numero) const;

        /**
         * @brief Aplica o Algoritmo de Luhn.
         * Realiza o cálculo matemático para verificar a integridade do número.
         * * @param numero A string numérica.
         * @return true Se o número for válido segundo Luhn.
         * @return false Se o número for inválido.
         */
        bool validarLuhn(const string& numero) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa um objeto Cartao vazio.
         */
        Cartao(); 

        /**
         * @brief Construtor com inicialização de valor.
         * Já realiza a validação no momento da criação.
         * * @param numero O número do cartão desejado.
         * @throw std::invalid_argument Se o formato for inválido.
         */
        explicit Cartao(const string& numero);

        /**
         * @brief Define um novo número para o cartão.
         * Substitui o valor atual se o novo valor passar na validação.
         * * @param numero A string com os 16 dígitos.
         * @throw std::invalid_argument Se o número for inválido.
         */
        void setCartao(const string& numero);

        /**
         * @brief Recupera o número do cartão armazenado.
         * @return string O número atual do cartão.
         */
        string getCartao() const;
};

#endif