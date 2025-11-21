#ifndef RESERVA_H
#define RESERVA_H

#include "../dominios/Codigo.h"
#include "../dominios/Data.h"
#include "../dominios/Dinheiro.h"

/**
 * @brief Entidade que representa uma Reserva.
 * Contém Código, Datas de Chegada/Partida e o Valor total.
 */
class Reserva {
private:
    Codigo codigo;
    Data chegada;
    Data partida;
    Dinheiro valor;

public:
    Reserva();
    virtual ~Reserva();

    void setCodigo(const Codigo& codigo);
    Codigo getCodigo() const;

    void setChegada(const Data& chegada);
    Data getChegada() const;

    void setPartida(const Data& partida);
    Data getPartida() const;

    void setValor(const Dinheiro& valor);
    Dinheiro getValor() const;
};

#endif // RESERVA_H