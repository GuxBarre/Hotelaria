#ifndef CNTR_SERVICO_RESERVAS_H
#define CNTR_SERVICO_RESERVAS_H

#include "../Interfaces.h"
#include "ContainerReserva.h"

class CntrServicoReservas : public IServicoReservas {
private:
    ContainerReserva* container;

public:
    void setContainer(ContainerReserva* c) { container = c; }

    bool criarReserva(const Reserva& reserva) override { return container->criarReserva(reserva); }
    bool lerReserva(const Codigo& codigo, Reserva* reserva) override { return container->lerReserva(codigo, reserva); }
    bool atualizarReserva(const Reserva& reserva) override { return container->atualizarReserva(reserva); }
    bool excluirReserva(const Codigo& codigo) override { return container->excluirReserva(codigo); }
    std::vector<Reserva> listarReservas() override { return container->listarReservas(); }
};
#endif