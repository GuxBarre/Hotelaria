#include "Reserva.h"

// Código da reserva
void Reserva::setCodigo(const Codigo &codigo) {
    this->codigo = codigo;
}

Codigo Reserva::getCodigo() const {
    return codigo;
}

// Código do hotel
void Reserva::setCodigoHotel(const Codigo &codigoHotel) {
    this->codigoHotel = codigoHotel;
}

Codigo Reserva::getCodigoHotel() const {
    return codigoHotel;
}

// Código do hóspede
void Reserva::setCodigoHospede(const Codigo &codigoHospede) {
    this->codigoHospede = codigoHospede;
}

Codigo Reserva::getCodigoHospede() const {
    return codigoHospede;
}

// Número do quarto
void Reserva::setNumeroQuarto(const Numero &numeroQuarto) {
    this->numeroQuarto = numeroQuarto;
}

Numero Reserva::getNumeroQuarto() const {
    return numeroQuarto;
}

// Data de check-in
void Reserva::setDataCheckIn(const Data &dataCheckIn) {
    this->dataCheckIn = dataCheckIn;
}

Data Reserva::getDataCheckIn() const {
    return dataCheckIn;
}

// Data de check-out
void Reserva::setDataCheckOut(const Data &dataCheckOut) {
    this->dataCheckOut = dataCheckOut;
}

Data Reserva::getDataCheckOut() const {
    return dataCheckOut;
}
