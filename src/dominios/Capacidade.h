#ifndef CAPACIDADE_H
#define CAPACIDADE_H

#include <stdexcept>

/**
 * @class Capacidade
 * @brief Representa o domínio de capacidade de acomodação de um quarto.
 * * @details 
 * Esta classe armazena e valida a capacidade de hóspedes.
 * De acordo com as regras de negócio, o formato válido aceita apenas:
 * - 1, 2, 3 ou 4 pessoas.
 * * Qualquer valor fora deste conjunto é considerado inválido.
 */
class Capacidade {
    private:
        int valor;

        /**
         * @brief Valida o valor da capacidade segundo as regras de negócio.
         * @param valor O inteiro a ser validado.
         * @throw std::invalid_argument Se o valor não for 1, 2, 3 ou 4.
         */
        void validar(int valor) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa a capacidade com um valor padrão (0).
         */
        Capacidade();

        /**
         * @brief Construtor com inicialização de valor.
         * * Inicializa a instância já validando o valor fornecido.
         * * @param valor Inteiro representando a capacidade (1, 2, 3 ou 4).
         * @throw std::invalid_argument Se o valor fornecido for inválido.
         */
        explicit Capacidade(int valor);

        /**
         * @brief Define o valor da capacidade.
         * * Este método valida o valor antes de armazená-lo. Se o valor for inválido,
         * o atributo não é modificado e uma exceção é lançada.
         * * @param valor Inteiro representando a capacidade (1 a 4).
         * @throw std::invalid_argument Se o valor for menor que 1 ou maior que 4.
         */
        void setCapacidade(int valor);

        /**
         * @brief Recupera o valor armazenado da capacidade.
         * * @return int O valor atual da capacidade.
         */
        int getCapacidade() const;
};

#endif