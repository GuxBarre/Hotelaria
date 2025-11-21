#ifndef QUARTO_H
#define QUARTO_H

#include "../dominios/Numero.h"
#include "../dominios/Capacidade.h"
#include "../dominios/Dinheiro.h"
#include "../dominios/Ramal.h"

/**
 * @brief Entidade que representa um Quarto do hotel.
 */
class Quarto {
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;

public:
    Quarto();
    virtual ~Quarto();

    void setNumero(const Numero& numero);
    Numero getNumero() const;

    void setCapacidade(const Capacidade& capacidade);
    Capacidade getCapacidade() const;

    void setDiaria(const Dinheiro& diaria);
    Dinheiro getDiaria() const;

    void setRamal(const Ramal& ramal);
    Ramal getRamal() const;
};

#endif // QUARTO_H