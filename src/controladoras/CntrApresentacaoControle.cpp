#include "CntrApresentacaoControle.h"
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

void CntrApresentacaoControle::setServicoPessoal(IServicoPessoal* servico) {
    this->servicoPessoal = servico;
}
void CntrApresentacaoControle::setServicoHotelaria(IServicoHotelaria* servico) {
    this->servicoHotelaria = servico;
}
void CntrApresentacaoControle::setServicoReservas(IServicoReservas* servico) {
    this->servicoReservas = servico;
}

void CntrApresentacaoControle::executar(const Email& email) {
    this->emailGerente = email;
    int opcao;
    string nomeExibicao = string(email.getEmail());
    Gerente gerenteLogado;
    
    if (servicoPessoal->lerGerente(email, &gerenteLogado)) {
        nomeExibicao = string(gerenteLogado.getNome().getNome()); 
    }

    do {
        limparTela();
        cout << "\n========================================" << endl;
        cout << "           MENU PRINCIPAL               " << endl;
        cout << "   Ola, " << nomeExibicao << endl;
        cout << "========================================" << endl;
        cout << "1. Gestao de Pessoas (Gerentes/Hospedes)" << endl;
        cout << "2. Gestao de Hotelaria (Hoteis/Quartos)" << endl;
        cout << "3. Gestao de Reservas" << endl;
        cout << "4. Editar Meus Dados" << endl;
        cout << "5. Excluir Minha Conta" << endl;
        cout << "0. Sair / Logout" << endl;
        cout << "Escolha: ";
        
        cin >> opcao;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcao) {
            case 1: menuPessoas(); break;
            case 2: menuHotelaria(); break;
            case 3: menuReservas(); break;
            case 4: 
                editarMinhaConta(emailGerente); 
                break;
            case 5:
                if (excluirMinhaConta(emailGerente)) {
                    cout << "Voltando para a tela de login..." << endl;
                    opcao = 0;
                }
                break;
            case 0: cout << "Saindo..." << endl; break;
            default: 
                cout << "Opcao invalida!" << endl;
                cout << "Pressione Enter...";
                cin.ignore(); cin.get();
        }
    } while (opcao != 0);
}

void CntrApresentacaoControle::menuPessoas() {
    while(true) {
        limparTela();
        cout << "\n--- Gestao de Pessoas ---" << endl;
        cout << "1. Criar Hospede" << endl;
        cout << "2. Listar Hospedes" << endl;
        cout << "3. Editar Hospede" << endl;
        cout << "4. Excluir Hospede" << endl;
        cout << "0. Voltar" << endl;
        
        int op;
        cout << "Opcao: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (op == 0) break;

        switch(op) {
            case 1: cadastrarHospede(); break;
            case 2: listarHospedes(); break;
            case 3: editarHospede(); break;
            case 4: excluirHospede(); break;
            default: cout << "Opcao invalida." << endl;
        }
        cout << "\nPressione Enter para continuar...";
        cin.ignore(); cin.get();
    }
}

void CntrApresentacaoControle::cadastrarHospede() {
    string nomeStr, emailStr, enderecoStr, cartaoStr;

    cout << "\n--- Novo Hospede ---" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        cout << "Nome (5-20 chars, iniciais maiusculas): ";
        getline(cin, nomeStr);
        Nome nome(nomeStr);
        cout << "Email (formato valido): ";
        getline(cin, emailStr);
        Email email(emailStr);

        cout << "Endereco (5-30 chars): ";
        getline(cin, enderecoStr); 
        Endereco endereco(enderecoStr);

        cout << "Cartao (16 digitos, Luhn valido): ";
        getline(cin, cartaoStr);
        Cartao cartao(cartaoStr);

        Hospede novoHospede;
        novoHospede.setNome(nome);
        novoHospede.setEmail(email);
        novoHospede.setEndereco(endereco);
        novoHospede.setCartao(cartao);

        if (servicoPessoal->criarHospede(novoHospede)) {
            cout << "\nHospede cadastrado com sucesso!" << endl;
        } else {
            cout << "\nFalha ao cadastrar no sistema." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << "\n[ERRO] " << e.what() << endl;
    }
}

void CntrApresentacaoControle::listarHospedes() {
    cout << "\n--- Listagem de Hospedes ---" << endl;

    vector<Hospede> lista = servicoPessoal->listarHospedes();

    if (lista.empty()) {
        cout << "Nenhum hospede encontrado." << endl;
        return;
    }

    cout << "Total encontrado: " << lista.size() << endl;
    
    for (const auto& h : lista) {
        cout << "--------------------------------------------------" << endl;
        cout << "Nome:     " << h.getNome().getNome() << endl;
        cout << "Email:    " << h.getEmail().getEmail() << endl;
        cout << "Endereco: " << h.getEndereco().getEndereco() << endl;
        cout << "Cartao:   " << h.getCartao().getCartao() << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

void CntrApresentacaoControle::editarHospede() {
    cout << "\n--- Editar Hospede ---" << endl;
    string emailAlvo;
    cout << "Digite o Email do Hospede a editar: ";
    cin >> emailAlvo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        Email email(emailAlvo);
        
        string nomeStr, enderecoStr, cartaoStr;
        cout << "Novo Nome: "; getline(cin, nomeStr);
        cout << "Novo Endereco: "; getline(cin, enderecoStr);
        cout << "Novo Cartao: "; getline(cin, cartaoStr);

        Hospede h;
        h.setEmail(email); // Chave
        h.setNome(Nome(nomeStr));
        h.setEndereco(Endereco(enderecoStr));
        h.setCartao(Cartao(cartaoStr));

        if (servicoPessoal->atualizarHospede(h)) {
            cout << "[SUCESSO] Hospede atualizado." << endl;
        } else {
            cout << "[ERRO] Hospede nao encontrado." << endl;
        }
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::excluirHospede() {
    cout << "\n--- Excluir Hospede ---" << endl;
    string emailAlvo;
    cout << "Digite o Email do Hospede: ";
    cin >> emailAlvo;

    try {
        Email email(emailAlvo);
        char conf;
        cout << "Confirma exclusao? (S/N): "; cin >> conf;
        if (conf == 'S' || conf == 's') {
            if (servicoPessoal->excluirHospede(email)) {
                cout << "[SUCESSO] Hospede excluido." << endl;
            } else {
                cout << "[ERRO] Hospede nao encontrado." << endl;
            }
        }
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::menuHotelaria() {
    int opcao;
    do {
        limparTela();
        cout << "\n--- Gestao de Hotelaria ---" << endl;
        cout << "1. Criar Hotel" << endl;
        cout << "2. Listar Hoteis" << endl;
        cout << "3. Criar Quarto" << endl;
        cout << "4. Listar Quartos" << endl;
        cout << "5. Editar Hotel" << endl;
        cout << "6. Excluir Hotel" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cout << "\nOpcao invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); 
            continue;
        }

        switch (opcao) {
            case 1: cadastrarHotel(); break; 
            case 2: listarHoteis(); break;   
            case 3: criarQuarto(); break; 
            case 4: listarQuartos(); break;   
            case 5: editarHotel(); break;
            case 6: excluirHotel(); break;
            case 0: break;
            default: cout << "\nOpcao invalida!";
        }
        if (opcao != 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 0);
}

void CntrApresentacaoControle::cadastrarHotel() {
    string nomeStr, enderecoStr, telefoneStr, codigoStr;

    cout << "\n--- Novo Hotel ---" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        cout << "Nome: "; getline(cin, nomeStr);
        cout << "Endereco: "; getline(cin, enderecoStr);
        cout << "Telefone: "; getline(cin, telefoneStr);
        cout << "Codigo: "; getline(cin, codigoStr);

        Hotel novoHotel;
        novoHotel.setNome(Nome(nomeStr));
        novoHotel.setEndereco(Endereco(enderecoStr));
        novoHotel.setTelefone(Telefone(telefoneStr));
        novoHotel.setCodigo(Codigo(codigoStr));

        if (servicoHotelaria->criarHotel(novoHotel)) {
            cout << "\nHotel cadastrado: " << nomeStr << endl;
        } else {
            cout << "\nFalha ao cadastrar (Codigo ja existe?)." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void CntrApresentacaoControle::listarHoteis() {
    cout << "\n--- Lista de Hoteis ---" << endl;
    
    std::vector<Hotel> lista = servicoHotelaria->listarHoteis();

    if (lista.empty()) {
        cout << "Nenhum hotel encontrado." << endl;
    } else {
        cout << "Total encontrado: " << lista.size() << endl;
        for (const auto& h : lista) {
            cout << "------------------------------------------" << endl;
            cout << "Codigo:   " << h.getCodigo().getCodigo() << endl;
            cout << "Nome:     " << h.getNome().getNome() << endl;
            cout << "Endereco: " << h.getEndereco().getEndereco() << endl;
            cout << "Telefone: " << h.getTelefone().getTelefone() << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void CntrApresentacaoControle::editarHotel() {
    cout << "\n--- Editar Hotel ---" << endl;
    string codStr;
    cout << "Digite o Codigo do Hotel: ";
    cin >> codStr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        Codigo codigo(codStr);
        
        string nomeStr, enderecoStr, telefoneStr;
        cout << "Novo Nome: "; getline(cin, nomeStr);
        cout << "Novo Endereco: "; getline(cin, enderecoStr);
        cout << "Novo Telefone: "; getline(cin, telefoneStr);

        Hotel h;
        h.setCodigo(codigo);
        h.setNome(Nome(nomeStr));
        h.setEndereco(Endereco(enderecoStr));
        h.setTelefone(Telefone(telefoneStr));

        if (servicoHotelaria->atualizarHotel(h)) {
            cout << "[SUCESSO] Hotel atualizado." << endl;
        } else {
            cout << "[ERRO] Hotel nao encontrado." << endl;
        }
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::excluirHotel() {
    cout << "\n--- Excluir Hotel ---" << endl;
    string codStr;
    cout << "Digite o Codigo do Hotel: ";
    cin >> codStr;

    try {
        Codigo codigo(codStr);
        char conf;
        cout << "Confirma exclusao? (S/N): "; cin >> conf;
        if (conf == 'S' || conf == 's') {
            if (servicoHotelaria->excluirHotel(codigo)) {
                cout << "[SUCESSO] Hotel excluido." << endl;
            } else {
                cout << "[ERRO] Hotel nao encontrado." << endl;
            }
        }
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::criarQuarto() {
    limparTela();
    cout << "\n=== CADASTRO DE QUARTO ===" << endl;
    cout << "\n[Hoteis Disponiveis]:" << endl;
    vector<Hotel> hoteis = servicoHotelaria->listarHoteis();
    if (hoteis.empty()) {
        cout << "Nenhum hotel cadastrado." << endl;
        return;
    }

    for (const auto& h : hoteis) {
        cout << "- " << h.getNome().getNome() 
             << " (Codigo: " << h.getCodigo().getCodigo() << ")" << endl;
    }
    cout << "--------------------------" << endl;

    string codigoHotelStr, numeroStr, diariaStr, capacidadeStr;

    try {
        cout << "Codigo do Hotel: "; cin >> codigoHotelStr;
        Codigo codigoHotel(codigoHotelStr);

        cout << "Numero do Quarto: "; cin >> numeroStr;
        Numero numero(stoi(numeroStr));

        cout << "Capacidade (1-4): "; cin >> capacidadeStr;
        Capacidade capacidade(stoi(capacidadeStr));

        cout << "Diaria: "; cin >> diariaStr;
        Dinheiro diaria(stod(diariaStr)); 

        Quarto novoQuarto;
        novoQuarto.setNumero(numero);
        novoQuarto.setCapacidade(capacidade);
        novoQuarto.setDiaria(diaria);
        
        if (servicoHotelaria->criarQuarto(novoQuarto, codigoHotel)) {
            cout << "\n[SUCESSO] Quarto criado." << endl;
        } else {
            cout << "\n[ERRO] Hotel nao encontrado ou quarto ja existe." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n[ERRO DE VALIDACAO] " << e.what() << endl;
    } catch (...) {
        cout << "\n[ERRO] Entrada invalida." << endl;
    }
}

void CntrApresentacaoControle::listarQuartos() {
    limparTela();
    cout << "\n=== LISTAGEM DE QUARTOS ===" << endl;

    vector<Hotel> hoteis = servicoHotelaria->listarHoteis();
    for (const auto& h : hoteis) {
        cout << "- " << h.getNome().getNome() << " [" << h.getCodigo().getCodigo() << "]" << endl;
    }
    cout << "---------------------------" << endl;

    string codigoStr;
    cout << "Digite o CODIGO do Hotel: ";
    cin >> codigoStr;

    try {
        Codigo codigoHotel(codigoStr);
        vector<Quarto> lista = servicoHotelaria->listarQuartos(codigoHotel);

        if (lista.empty()) {
            cout << "\nNenhum quarto encontrado neste hotel." << endl;
        } else {
            cout << "\n--- Quartos do Hotel " << codigoStr << " ---" << endl;
            for (const auto& q : lista) {
                cout << "Quarto: " << q.getNumero().getNumero() 
                     << " | Cap: " << q.getCapacidade().getCapacidade()
                     << " | R$ " << q.getDiaria().getDinheiro() << endl;
            }
        }

    } catch (const invalid_argument& e) {
        cout << "[ERRO] Codigo de hotel invalido: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::menuReservas() {
    int opcao;
    do {
        limparTela();
        cout << "\n--- Gestao de Reservas ---" << endl;
        cout << "1. Criar Reserva" << endl;
        cout << "2. Listar Reservas" << endl;
        cout << "3. Editar Reserva" << endl;
        cout << "4. Excluir Reserva" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cout << "\nOpcao invalida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); 
            continue;
        }

        switch (opcao) {
            case 1: cadastrarReserva(); break; 
            case 2: listarReservas(); break;   
            case 3: editarReserva(); break;
            case 4: excluirReserva(); break;
            case 0: break;
            default: cout << "\nOpcao invalida!";
        }
        if (opcao != 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 0);
}

void CntrApresentacaoControle::cadastrarReserva() {
    string codigoStr, chegadaStr, partidaStr;
    double valorDouble;

    cout << "\n--- Nova Reserva ---" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        cout << "Codigo: "; getline(cin, codigoStr);
        Codigo codigo(codigoStr);

        cout << "Data Chegada: "; getline(cin, chegadaStr);
        Data chegada(chegadaStr);

        cout << "Data Partida: "; getline(cin, partidaStr);
        Data partida(partidaStr);
        
        cout << "Valor Total (R$): ";
        if (!(cin >> valorDouble)) throw std::invalid_argument("Valor deve ser numerico.");
        Dinheiro valor(valorDouble);

        Reserva novaReserva;
        novaReserva.setCodigo(codigo);
        novaReserva.setChegada(chegada);
        novaReserva.setPartida(partida);
        novaReserva.setValor(valor);

        if (servicoReservas->criarReserva(novaReserva)) {
            cout << "\nReserva criada." << endl;
        } else {
            cout << "\nFalha ao cadastrar." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << "\nErro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::listarReservas() {
    cout << "\n--- Lista de Reservas ---" << endl;
    
    std::vector<Reserva> lista = servicoReservas->listarReservas();

    if (lista.empty()) {
        cout << "Nenhuma reserva encontrada." << endl;
    } else {
        cout << "Total encontrado: " << lista.size() << endl;
        for (const auto& r : lista) {
            cout << "------------------------------------------" << endl;
            cout << "Codigo:    " << r.getCodigo().getCodigo() << endl;
            cout << "Chegada:   " << r.getChegada().getData() << endl;
            cout << "Partida:   " << r.getPartida().getData() << endl;
            cout << "Valor:     R$ " << r.getValor().getDinheiro() << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}

void CntrApresentacaoControle::editarReserva() {
    cout << "\n--- Editar Reserva ---" << endl;
    string codStr;
    cout << "Digite o Codigo da Reserva: ";
    cin >> codStr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        Codigo codigo(codStr);
        
        string chegadaStr, partidaStr;
        double valorDouble;
        cout << "Nova Chegada: "; getline(cin, chegadaStr);
        cout << "Nova Partida: "; getline(cin, partidaStr);
        cout << "Novo Valor: "; cin >> valorDouble;

        Reserva r;
        r.setCodigo(codigo);
        r.setChegada(Data(chegadaStr));
        r.setPartida(Data(partidaStr));
        r.setValor(Dinheiro(valorDouble));

        if (servicoReservas->atualizarReserva(r)) {
            cout << "[SUCESSO] Reserva atualizada." << endl;
        } else {
            cout << "[ERRO] Reserva nao encontrada." << endl;
        }
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::excluirReserva() {
    cout << "\n--- Excluir Reserva ---" << endl;
    string codStr;
    cout << "Digite o Codigo da Reserva: ";
    cin >> codStr;

    try {
        Codigo codigo(codStr);
        char conf;
        cout << "Confirma exclusao? (S/N): "; cin >> conf;
        if (conf == 'S' || conf == 's') {
            if (servicoReservas->excluirReserva(codigo)) {
                cout << "[SUCESSO] Reserva excluida." << endl;
            } else {
                cout << "[ERRO] Reserva nao encontrada." << endl;
            }
        }
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void CntrApresentacaoControle::editarMinhaConta(const Email& email) {
    limparTela();
    cout << "\n=== EDITAR MEUS DADOS ===" << endl;
    cout << "Email (Nao pode ser alterado): " << email.getEmail() << endl;

    string nomeStr, senhaStr;
    int ramal;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        cout << "Novo Nome: "; getline(cin, nomeStr);
        cout << "Nova Senha: "; cin >> senhaStr; 
        cout << "Novo Ramal: "; cin >> ramal;

        Gerente gerenteAtualizado;
        gerenteAtualizado.setEmail(email);
        gerenteAtualizado.setNome(Nome(nomeStr));
        gerenteAtualizado.setSenha(Senha(senhaStr));
        gerenteAtualizado.setRamal(Ramal(ramal));
        
        if (servicoPessoal->atualizarGerente(gerenteAtualizado)) {
            cout << "\n[SUCESSO] Seus dados foram atualizados!" << endl;
        } else {
            cout << "\n[ERRO] Falha ao atualizar dados." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n[ERRO DE VALIDACAO] " << e.what() << endl;
    } catch (...) {
        cout << "\n[ERRO] Entrada invalida." << endl;
    }

    cout << "Pressione Enter para voltar...";
    cin.ignore(); cin.get();
}

bool CntrApresentacaoControle::excluirMinhaConta(const Email& email) {
    limparTela();
    cout << "\n=== EXCLUIR MINHA CONTA ===" << endl;
    cout << "ATENCAO: Esta acao e irreversivel." << endl;
    cout << "Tem certeza que deseja excluir a conta " << email.getEmail() << "? (S/N): ";
    
    char resp;
    cin >> resp;

    if (resp == 'S' || resp == 's') {
        if (servicoPessoal->excluirGerente(email)) {
            cout << "\n[SUCESSO] Conta excluida permanentemente." << endl;
            cout << "Pressione Enter para confirmar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin.get();
            return true;
        } else {
            cout << "\n[ERRO] Nao foi possivel excluir a conta." << endl;
        }
    } else {
        cout << "\nOperacao cancelada." << endl;
    }

    cout << "Pressione Enter para voltar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
    return false;
}