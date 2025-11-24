#include <iostream>
#include "dominios/Email.h"
#include "controladoras/CntrApresentacaoAutenticacao.h"
#include "controladoras/CntrApresentacaoControle.h"

#include "controladoras/ContainerPessoal.h"
#include "controladoras/CntrPessoal.h"
#include "controladoras/ContainerHotelaria.h"
#include "controladoras/CntrlHotelaria.h"
#include "controladoras/ContainerReserva.h"
#include "controladoras/CntrlReservas.h"
#include "controladoras/CntrServicoAutenticacao.h"

using namespace std;

int main() {
    
    //pessoal
    ContainerPessoal containerPessoal;
    CntrServicoPessoal servicoPessoal;
    servicoPessoal.setContainer(&containerPessoal);

    //hotelaria
    ContainerHotelaria ContainerHotelaria;
    CntrServicoHotelaria servicoHotelaria;
    servicoHotelaria.setContainer(&ContainerHotelaria);

    //reservas
    ContainerReserva ContainerReservas;
    CntrServicoReservas servicoReservas;
    servicoReservas.setContainer(&ContainerReservas);
    
    //apresentação & autenticacao
    CntrApresentacaoAutenticacao cntrAutenticacao;
    CntrApresentacaoControle     cntrControle;
    CntrServicoAutenticacao      servicoAutenticacao;
    servicoAutenticacao.setContainer(&containerPessoal);
    //ligar Controladoras aos Serviços
    cntrAutenticacao.setServicoPessoal(&servicoPessoal);
    cntrAutenticacao.setServicoAutenticacao(&servicoAutenticacao);
    cntrControle.setServicoPessoal(&servicoPessoal);
    cntrControle.setServicoHotelaria(&servicoHotelaria);
    cntrControle.setServicoReservas(&servicoReservas);

    //fluxo do Sistema
    Email emailUsuario;
    bool logado = false;

    while (true) {
        logado = cntrAutenticacao.autenticar(&emailUsuario);

        if (logado) {
            cntrControle.executar(emailUsuario);
            cout << "\nEfetuando logout...\n" << endl;
        } else {
            cout << "Encerrando sistema." << endl;
            break;
        }
    }

    return 0;
}