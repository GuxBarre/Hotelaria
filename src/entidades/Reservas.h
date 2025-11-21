#ifndef RESERVA_H
#define RESERVA_H

#include "Codigo.h"
#include "Numero.h"
#include "Data.h"

/**
 * Entidade que representa uma reserva em um hotel.
 * Todos os atributos são domínios.
 */
class Reserva {
private:
    Codigo codigo;          ///< Identificador da reserva (chave primária).
    Codigo codigoHotel;     ///< Código do hotel onde a reserva foi feita.
    Codigo codigoHospede;   ///< Código do hóspede que fez a reserva.
    Numero numeroQuarto;    ///< Número do quarto reservado.
    Data dataCheckIn;       ///< Data de entrada.
    Data dataCheckOut;      ///< Data de saída.

public:
    Reserva() = default;

    // Código da reserva
    void setCodigo(const Codigo &codigo);
    Codigo getCodigo() const;

    // Código do hotel
    void setCodigoHotel(const Codigo &codigoHotel);
    Codigo getCodigoHotel() const;

    // Código do hóspede
    void setCodigoHospede(const Codigo &codigoHospede);
    Codigo getCodigoHospede() const;

    // Número do quarto
    void setNumeroQuarto(const Numero &numeroQuarto);
    Numero getNumeroQuarto() const;

    // Data de check-in
    void setDataCheckIn(const Data &dataCheckIn);
    Data getDataCheckIn() const;

    // Data de check-out
    void setDataCheckOut(const Data &dataCheckOut);
    Data getDataCheckOut() const;
};

#endif // RESERVA_H
