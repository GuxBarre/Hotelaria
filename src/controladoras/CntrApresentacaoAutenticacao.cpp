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

void CntrApresentacaoAutenticacao::setServicoAutenticacao(IServicoAutenticacao* servico) {
    this->servicoAuth = servico;
}

void CntrApresentacaoAutenticacao::setServicoPessoal(IServicoPessoal* servico) {
    this->servicoPessoal = servico;
}

void CntrApresentacaoAutenticacao::cadastrar() {
    limparTela();
    cout << "\n----------------------------------------" << endl;
    cout << "        CADASTRO DE NOVO GERENTE        " << endl;
    cout << "----------------------------------------" << endl;

    string nomeStr, emailStr, senhaStr;
    int ramal;

    try {
        cout << "Digite o Nome Completo: ";
        cin.ignore();
        getline(cin, nomeStr); 
        Nome nome(nomeStr);

        cout << "Digite o Email: ";
        cin >> emailStr;
        Email email(emailStr);

        cout << "Digite a Senha: ";
        cin >> senhaStr;
        Senha senha(senhaStr);
        
        cout << "Digite o Ramal: ";
        cin >> ramal;
        Ramal ramal(ramal);

        Gerente novoGerente;
        novoGerente.setNome(nome);
        novoGerente.setEmail(email);
        novoGerente.setSenha(senha);
        novoGerente.setRamal(ramal);

        if (servicoPessoal->criarGerente(novoGerente)) {
            cout << "\nGerente cadastrado com sucesso!" << endl;
            cout << "Pressione qualquer tecla para voltar ao login...";
            cin.ignore(); cin.get();
        } else {
            cout << "\n[FALHA] Não foi possível cadastrar (email já existe?)." << endl;
            cout << "Pressione qualquer tecla para voltar...";
            cin.ignore(); cin.get();
        }

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
        cout << "Pressione qualquer tecla para tentar novamente...";
        cin.get();
    }
}

bool CntrApresentacaoAutenticacao::autenticar(Email* email) {
    string emailStr, senhaStr;

    while (true) {
        limparTela();
        cout << "\n----------------------------------------" << endl;
        cout << "         SISTEMA HOTELEIRO        " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Fazer Login" << endl;
        cout << "2. Criar Nova Conta (Gerente)" << endl;
        cout << "3. Sair" << endl;
        cout << "Opcao: ";
        
        int opcao;
        cin >> opcao;

        if (opcao == 2) {
            cadastrar();
            continue;
        }
        else if (opcao == 3) {
            return false;
        }
        else if (opcao == 1) {
            cout << "\n--- LOGIN ---" << endl;
            cout << "Digite o Email: ";
            cin >> emailStr;
            cout << "Digite a Senha: ";
            cin >> senhaStr;

            try {
                Email emailDigitado(emailStr);
                Senha senhaDigitada(senhaStr);
                if (servicoAuth->autenticar(emailDigitado, senhaDigitada)) {
                    *email = emailDigitado;
                    return true;
                } else {
                    cout << "\n[ERRO] Email ou senha incorretos." << endl;
                    cout << "Pressione Enter para continuar...";
                    cin.ignore(); cin.get(); 
                }
            } catch (const invalid_argument& e) {
                cout << "\n[ERRO] " << e.what() << endl;
                cin.ignore(); cin.get();
            }
        }
    }
}