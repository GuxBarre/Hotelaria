#ifndef QUARTO_H
#define QUARTO_H

#include "../dominios/Numero.h"
#include "../dominios/Capacidade.h"
#include "../dominios/Dinheiro.h"
#include "../dominios/Ramal.h"

/**
 * @brief Entidade que representa um Quarto do hotel.
 * * Armazena as características físicas e financeiras de uma acomodação,
 * incluindo seu número de identificação, quantas pessoas comporta,
 * o valor da diária e o ramal telefônico interno.
 */
class Quarto {
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;

public:
    /**
     * @brief Construtor padrão da classe Quarto.
     * Inicializa uma instância sem valores definidos.
     */
    Quarto();

    /**
     * @brief Destrutor virtual da classe Quarto.
     */
    virtual ~Quarto();

    /**
     * @brief Define o número do quarto.
     * @param numero Objeto da classe domínio Numero.
     */
    void setNumero(const Numero& numero);

    /**
     * @brief Obtém o número do quarto.
     * @return Objeto da classe domínio Numero.
     */
    Numero getNumero() const;

    /**
     * @brief Define a capacidade de hóspedes do quarto.
     * @param capacidade Objeto da classe domínio Capacidade (validado entre 1 e 4).
     */
    void setCapacidade(const Capacidade& capacidade);

    /**
     * @brief Obtém a capacidade do quarto.
     * @return Objeto da classe domínio Capacidade.
     */
    Capacidade getCapacidade() const;

    /**
     * @brief Define o valor da diária.
     * @param diaria Objeto da classe domínio Dinheiro.
     */
    void setDiaria(const Dinheiro& diaria);

    /**
     * @brief Obtém o valor da diária.
     * @return Objeto da classe domínio Dinheiro.
     */
    Dinheiro getDiaria() const;

    /**
     * @brief Define o ramal telefônico do quarto.
     * @param ramal Objeto da classe domínio Ramal.
     */
    void setRamal(const Ramal& ramal);

    /**
     * @brief Obtém o ramal do quarto.
     * @return Objeto da classe domínio Ramal.
     */
    Ramal getRamal() const;
};

#endif // QUARTO_H