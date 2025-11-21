#ifndef INTERFACES_H
#define INTERFACES_H

#include "entidades/Gerente.h"
#include "entidades/Hotel.h"
#include "entidades/Quarto.h"
#include "entidades/Hospede.h"
#include "entidades/Reserva.h"

#include <vector>
#include <string>

// ------------------------------------------------------------------
// Interface de Autenticação
// Responsável apenas pelo login do Gerente [cite: 12]
// ------------------------------------------------------------------
class IServicoAutenticacao {
public:
    virtual ~IServicoAutenticacao() {}
    
    // Retorna true se email e senha conferem, false caso contrário
    virtual bool autenticar(const Email& email, const Senha& senha) = 0;
};

// ------------------------------------------------------------------
// Interface de Serviços relacionados a Pessoas (Gerente e Hóspede)
// [cite: 14, 15, 17]
// ------------------------------------------------------------------
class IServicoPessoal {
public:
    virtual ~IServicoPessoal() {}

    // --- CRUD Gerente ---
    virtual bool criarGerente(const Gerente& gerente) = 0;
    virtual bool lerGerente(const Email& email, Gerente* gerente) = 0; // Passar ponteiro para preencher
    virtual bool atualizarGerente(const Gerente& gerente) = 0;
    virtual bool excluirGerente(const Email& email) = 0;

    // --- CRUD Hóspede ---
    virtual bool criarHospede(const Hospede& hospede) = 0;
    virtual bool lerHospede(const Email& email, Hospede* hospede) = 0;
    virtual bool atualizarHospede(const Hospede& hospede) = 0;
    virtual bool excluirHospede(const Email& email) = 0;

    // --- Listagem ---
    virtual std::vector<Hospede> listarHospedes() = 0;
};

// ------------------------------------------------------------------
// Interface de Serviços de Hotelaria (Hotéis e Quartos)
// [cite: 14, 15, 16]
// ------------------------------------------------------------------
class IServicoHotelaria {
public:
    virtual ~IServicoHotelaria() {}

    // --- CRUD Hotel ---
    virtual bool criarHotel(const Hotel& hotel) = 0;
    virtual bool lerHotel(const Codigo& codigo, Hotel* hotel) = 0;
    virtual bool atualizarHotel(const Hotel& hotel) = 0;
    virtual bool excluirHotel(const Codigo& codigo) = 0;

    // --- CRUD Quarto ---
    virtual bool criarQuarto(const Quarto& quarto) = 0;
    virtual bool lerQuarto(const Numero& numero, Quarto* quarto) = 0;
    virtual bool atualizarQuarto(const Quarto& quarto) = 0;
    virtual bool excluirQuarto(const Numero& numero) = 0;

    // --- Listagens ---
    virtual std::vector<Hotel> listarHoteis() = 0;
    virtual std::vector<Quarto> listarQuartos() = 0;
};

// ------------------------------------------------------------------
// Interface de Serviços de Reservas
// [cite: 15, 17]
// ------------------------------------------------------------------
class IServicoReservas {
public:
    virtual ~IServicoReservas() {}

    // --- CRUD Reserva ---
    virtual bool criarReserva(const Reserva& reserva) = 0;
    virtual bool lerReserva(const Codigo& codigo, Reserva* reserva) = 0;
    virtual bool atualizarReserva(const Reserva& reserva) = 0;
    virtual bool excluirReserva(const Codigo& codigo) = 0;

    // --- Listagem ---
    virtual std::vector<Reserva> listarReservas() = 0;
};

#endif // INTERFACES_H