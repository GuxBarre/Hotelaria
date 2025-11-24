#ifndef CNTR_SERVICO_HOTELARIA_H
#define CNTR_SERVICO_HOTELARIA_H

#include "../Interfaces.h"
#include "ContainerHotelaria.h"

class CntrServicoHotelaria : public IServicoHotelaria {
private:
    ContainerHotelaria* container;

public:
    void setContainer(ContainerHotelaria* c) { container = c; }
    bool criarHotel(const Hotel& hotel) override { 
        return container->criarHotel(hotel); 
    }
    
    bool lerHotel(const Codigo& codigo, Hotel* hotel) override { 
        return container->lerHotel(codigo, hotel); 
    }
    
    bool atualizarHotel(const Hotel& hotel) override { 
        return container->atualizarHotel(hotel); 
    }
    
    bool excluirHotel(const Codigo& codigo) override { 
        return container->excluirHotel(codigo); 
    }
    
    std::vector<Hotel> listarHoteis() override { 
        return container->listarHoteis(); 
    }
    bool criarQuarto(const Quarto& quarto, const Codigo& codigoHotel) override { 
        return container->criarQuarto(quarto, codigoHotel); 
    }

    bool lerQuarto(const Numero& numero, const Codigo& codigoHotel, Quarto* quarto) override { 
        return container->lerQuarto(numero, codigoHotel, quarto); 
    }

    bool atualizarQuarto(const Quarto& quarto, const Codigo& codigoHotel) override { 
        return container->atualizarQuarto(quarto, codigoHotel); 
    }

    bool excluirQuarto(const Numero& numero, const Codigo& codigoHotel) override { 
        return container->excluirQuarto(numero, codigoHotel); 
    }

    std::vector<Quarto> listarQuartos(const Codigo& codigoHotel) override { 
        return container->listarQuartos(codigoHotel); 
    }
};
#endif