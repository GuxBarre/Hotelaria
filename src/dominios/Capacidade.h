#ifndef CAPACIDADE_H
#define CAPACIDADE_H
#include <string>
#include <stdexcept>
using namespace std;
/**
 * @class Capacidade
 * @brief Representa o domínio de capacidade de acomodação de um quarto.
 * * @details 
 * Esta classe armazena e valida a capacidade de hóspedes.
 * De acordo com as regras de negócio, o formato válido aceita apenas:
 * - 1, 2, 3 ou 4 pessoas.
 * * Qualquer capacidade fora deste conjunto é considerado inválido.
 */
class Capacidade {
    private:
        int capacidade;

        /**
         * @brief Valida o capacidade da capacidade segundo as regras de negócio.
         * @param capacidade O inteiro a ser validado.
         * @throw std::invalid_argument Se o capacidade não for 1, 2, 3 ou 4.
         */
        void validar(int capacidade) const;

    public:
        /**
         * @brief Construtor padrão.
         * Inicializa a capacidade com um capacidade padrão (0).
         */
        Capacidade();

        /**
         * @brief Sobrecarga do operador de conversão para std::string.
         * * Permite que o objeto seja convertido implicitamente para uma string,
         * retornando o capacidade armazenado internamente.
         * * @return std::string O capacidade do atributo armazenado.
         */
        operator string() const;

        /**
         * @brief Construtor com inicialização de capacidade.
         * * Inicializa a instância já validando o capacidade fornecido.
         * * @param capacidade Inteiro representando a capacidade (1, 2, 3 ou 4).
         * @throw std::invalid_argument Se o capacidade fornecido for inválido.
         */
        explicit Capacidade(int capacidade);

        /**
         * @brief Define o capacidade da capacidade.
         * * Este método valida o capacidade antes de armazená-lo. Se o capacidade for inválido,
         * o atributo não é modificado e uma exceção é lançada.
         * * @param capacidade Inteiro representando a capacidade (1 a 4).
         * @throw std::invalid_argument Se o capacidade for menor que 1 ou maior que 4.
         */
        void setCapacidade(int capacidade);

        /**
         * @brief Recupera o capacidade armazenado da capacidade.
         * * @return int O capacidade atual da capacidade.
         */
        int getCapacidade() const;
};

#endif