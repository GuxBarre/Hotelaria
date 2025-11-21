#include "CntrApresentacaoAutenticacao.h"
#include <iostream>
#include <limits> 

using namespace std;

static void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void CntrApresentacaoAutenticacao::setServico(IServicoAutenticacao* servico) {
    this->servico = servico;
}

bool CntrApresentacaoAutenticacao::autenticar(Email* email) {
    string emailStr, senhaStr;

    while (true) {
        limparTela();
        cout << "\n----------------------------------------" << endl;
        cout << "          SISTEMA HOTELEIRO - LOGIN     " << endl;
        cout << "----------------------------------------" << endl;

        cout << "Digite o Email: ";
        cin >> emailStr;
        
        cout << "Digite a Senha: ";
        cin >> senhaStr;

        try {
            // 1. Validação de Formato (Camada de Apresentação)
            Email emailDigitado(emailStr);
            Senha senhaDigitada(senhaStr);

            // 2. Chama o Serviço (Camada de Serviço)
            if (servico->autenticar(emailDigitado, senhaDigitada)) {
                *email = emailDigitado; // Retorna o email autenticado
                return true;
            } else {
                cout << "\n[ERRO] Email ou senha incorretos (banco de dados)." << endl;
            }

        } catch (const invalid_argument& e) {
            // Captura erros de formato dos Domínios
            cout << e.what() << endl;
        }

        cout << "Tentar novamente? (S/N): ";
        char op;
        cin >> op;
        if (op == 'N' || op == 'n') return false;
    }
}