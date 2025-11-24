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

public:
    ContainerHotelaria();
    // CRUD HOTEL
    bool criarHotel(const Hotel& hotel);
    bool lerHotel(const Codigo& codigo, Hotel* hotel);
    bool atualizarHotel(const Hotel& hotel);
    bool excluirHotel(const Codigo& codigo);

    // CRUD QUARTO
    bool criarQuarto(const Quarto& quarto, const Codigo& codigoHotel); 
    bool lerQuarto(const Numero& numero, const Codigo& codigoHotel, Quarto* quarto);
    bool atualizarQuarto(const Quarto& quarto, const Codigo& codigoHotel);
    bool excluirQuarto(const Numero& numero, const Codigo& codigoHotel);

    // LISTAGENS
    std::vector<Hotel> listarHoteis();
    std::vector<Quarto> listarQuartos(const Codigo& codigoHotel);


    bool hotelExiste(const Codigo& codigo);
};

#endif