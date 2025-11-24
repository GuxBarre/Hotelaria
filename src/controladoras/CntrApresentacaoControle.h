#ifndef CNTRAPRESENTACAOCONTROLE_H
#define CNTRAPRESENTACAOCONTROLE_H

#include "Interfaces.h"
#include "../dominios/Email.h"

class CntrApresentacaoControle {
private:
    Email emailGerente; 
    
    IServicoPessoal* servicoPessoal;
    IServicoHotelaria* servicoHotelaria;
    IServicoReservas* servicoReservas;

    void menuPessoas();
    void menuHotelaria();
    void menuReservas();

    void editarMinhaConta(const Email& email);
    bool excluirMinhaConta(const Email& email);

    void cadastrarHospede();
    void listarHospedes();
    void editarHospede();
    void excluirHospede();

    void cadastrarHotel();
    void listarHoteis();
    void editarHotel();
    void excluirHotel();
    
    void criarQuarto();
    void listarQuartos();

    void cadastrarReserva();
    void listarReservas();
    void editarReserva();
    void excluirReserva();

public:
    void setServicoPessoal(IServicoPessoal* servico);
    void setServicoHotelaria(IServicoHotelaria* servico);
    void setServicoReservas(IServicoReservas* servico);

    void executar(const Email& email);
};

#endif