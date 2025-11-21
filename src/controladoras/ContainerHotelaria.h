#ifndef CONTAINER_HOTELARIA_H
#define CONTAINER_HOTELARIA_H

#include "../entidades/Hotel.h"
#include "../entidades/Quarto.h"
#include "../dominios/Codigo.h"
#include "../dominios/Numero.h"
#include <map>
#include <vector>
#include <string>

class ContainerHotelaria {
private:
    std::map<std::string, Hotel> dbHoteis;
    std::map<std::string, Quarto> dbQuartos;

public:
    ContainerHotelaria();

    // CRUD Hotel
    bool criarHotel(const Hotel& hotel);
    bool lerHotel(const Codigo& codigo, Hotel* hotel);
    bool atualizarHotel(const Hotel& hotel);
    bool excluirHotel(const Codigo& codigo);

    // CRUD Quarto
    bool criarQuarto(const Quarto& quarto);
    bool lerQuarto(const Numero& numero, Quarto* quarto);
    bool atualizarQuarto(const Quarto& quarto);
    bool excluirQuarto(const Numero& numero);

    // Listagens
    std::vector<Hotel> listarHoteis();
    std::vector<Quarto> listarQuartos();

    // Função de apoio
    bool hotelTemQuartos(const Codigo& codigo);
};

#endif
