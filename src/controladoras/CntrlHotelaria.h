#ifndef CNTR_SERVICO_HOTELARIA_H
#define CNTR_SERVICO_HOTELARIA_H

#include "../Interfaces.h"
#include "ContainerHotelaria.h"

class CntrServicoHotelaria : public IServicoHotelaria {
private:
    ContainerHotelaria* container;

public:
    void setContainer(ContainerHotelaria* c) { container = c; }

    bool criarHotel(const Hotel& hotel) override { return container->criarHotel(hotel); }
    bool lerHotel(const Codigo& codigo, Hotel* hotel) override { return container->lerHotel(codigo, hotel); }
    bool atualizarHotel(const Hotel& hotel) override { return container->atualizarHotel(hotel); }
    bool excluirHotel(const Codigo& codigo) override { return container->excluirHotel(codigo); }

    bool criarQuarto(const Quarto& quarto) override { return container->criarQuarto(quarto); }
    bool lerQuarto(const Numero& numero, Quarto* quarto) override { return container->lerQuarto(numero, quarto); }
    bool atualizarQuarto(const Quarto& quarto) override { return container->atualizarQuarto(quarto); }
    bool excluirQuarto(const Numero& numero) override { return container->excluirQuarto(numero); }

    std::vector<Hotel> listarHoteis() override { return container->listarHoteis(); }
    std::vector<Quarto> listarQuartos() override { return container->listarQuartos(); }
};
#endif