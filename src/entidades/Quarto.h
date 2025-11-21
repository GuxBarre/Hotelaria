#ifndef QUARTO_H
#define QUARTO_H

#include "Numero.h"
#include "Capacidade.h"
#include "Dinheiro.h"

/**
 * Entidade que representa um quarto de hotel.
 * Cada atributo é uma classe de domínio.
 */
class Quarto {
private:
    Numero     numero;      ///< Identificador do quarto dentro do hotel (001 a 999).
    Capacidade capacidade;  ///< Quantidade de hóspedes (1, 2, 3 ou 4).
    Dinheiro   diaria;      ///< Valor da diária do quarto.

public:
    Quarto() = default;

    // Número do quarto
    void setNumero(const Numero &numero);
    Numero getNumero() const;

    // Capacidade
    void setCapacidade(const Capacidade &capacidade);
    Capacidade getCapacidade() const;

    // Diária
    void setDiaria(const Dinheiro &diaria);
    Dinheiro getDiaria() const;
};

#endif // QUARTO_H
