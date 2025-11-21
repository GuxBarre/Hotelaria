#ifndef CONTAINER_RESERVAS_H
#define CONTAINER_RESERVAS_H

#include "../entidades/Reserva.h"
#include "../dominios/Codigo.h"
#include <map>
#include <vector>
#include <string>

class ContainerReserva {
private:
    std::map<std::string, Reserva> dbReservas;

public:
    ContainerReserva();

    // CRUD Reserva
    bool criarReserva(const Reserva& reserva);
    bool lerReserva(const Codigo& codigo, Reserva* reserva);
    bool atualizarReserva(const Reserva& reserva);
    bool excluirReserva(const Codigo& codigo);

    // Listagem
    std::vector<Reserva> listarReservas();

    // Validação de sobreposição (no seu modelo, Reserva não tem quarto/hotel, então conflito é global)
    bool conflitoDeDatas(const Reserva& r1, const Reserva& r2);
};

#endif
