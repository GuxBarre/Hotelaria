#include <iostream>
#include "dominios/Email.h"
#include "controladoras/CntrApresentacaoAutenticacao.h"
#include "controladoras/CntrApresentacaoControle.h"
#include "stubs/Stubs.h" // Inclui nossos serviços falsos

using namespace std;

int main() {
    // 1. Instanciar os Serviços (Stubs por enquanto)
    StubServicoAutenticacao stubAuth;
    StubServicoPessoal      stubPessoal;
    StubServicoHotelaria    stubHotelaria;
    StubServicoReservas     stubReservas;

    // 2. Instanciar as Controladoras de Apresentação
    CntrApresentacaoAutenticacao cntrAutenticacao;
    CntrApresentacaoControle     cntrControle;

    // 3. Ligar Controladoras aos Serviços (Injeção de Dependência)
    cntrAutenticacao.setServico(&stubAuth);
    
    cntrControle.setServicoPessoal(&stubPessoal);
    cntrControle.setServicoHotelaria(&stubHotelaria);
    cntrControle.setServicoReservas(&stubReservas);

    // 4. Executar o Fluxo do Sistema
    Email emailUsuario;
    bool logado = false;

    while (true) {
        // Tela de Login
        logado = cntrAutenticacao.autenticar(&emailUsuario);

        if (logado) {
            // Se logou, vai para o Menu Principal
            cntrControle.executar(emailUsuario);
            
            // Ao sair do menu principal (Logout), o loop reinicia e pede login de novo
            cout << "\nEfetuando logout...\n" << endl;
        } else {
            // Se usuário escolheu sair na tela de login
            cout << "Encerrando sistema." << endl;
            break;
        }
    }

    return 0;
}