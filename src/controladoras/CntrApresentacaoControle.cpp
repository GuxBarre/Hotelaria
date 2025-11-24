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

    do {
        limparTela();
        cout << "\n========================================" << endl;
        cout << "           MENU PRINCIPAL               " << endl;
        cout << "   Usuario: " << string(emailGerente) << endl;
        cout << "========================================" << endl;
        cout << "1. Gestao de Pessoas (Gerentes/Hospedes)" << endl;
        cout << "2. Gestao de Hotelaria (Hoteis/Quartos)" << endl;
        cout << "3. Gestao de Reservas" << endl;
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
        cout << "0. Voltar" << endl;
        
        int op;
        cout << "Opcao: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERRO] Digite apenas numeros." << endl;
            continue;
        }

        if (op == 0) break;

        if (op == 1) {
            cadastrarHospede();
            cout << "\nPressione Enter para continuar...";
            cin.get();
        } else if (op == 2) {
             listarHospedes();
        } else {
            cout << "Opcao invalida." << endl;
            cin.ignore(); cin.get();
        }
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
        cout << "Nenhum hospede encontrado no sistema." << endl;
        cout << "Pressione Enter para voltar...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Total encontrado: " << lista.size() << endl;
    
    for (const auto& h : lista) {
        cout << "--------------------------------------------------" << endl;
        cout << "Nome:     " << string(h.getNome()) << endl;
        cout << "Email:    " << string(h.getEmail()) << endl;
        cout << "Endereco: " << string(h.getEndereco()) << endl;
        cout << "Cartao:   " << string(h.getCartao()) << endl;
    }
    cout << "--------------------------------------------------" << endl;
    
    cout << "Pressione Enter para voltar...";
    cin.ignore(); 
    cin.get();
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
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cout << "\nOpcao invalida. Digite apenas NUMEROS (0-4)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pressione Enter para continuar...";
            cin.get(); 
            
            continue;
        }

        switch (opcao) {
            case 1: cadastrarHotel(); break; 
            case 2: listarHoteis(); break;   
            case 3: criarQuarto(); break; 
            case 4: listarQuartos(); break;   
            case 0: break;
            default: cout << "\nOpcao invalida!";
        }
        if (opcao != 0)
        {
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
        cout << "Nome (5-20 chars, iniciais maiusculas): ";
        getline(cin, nomeStr);
        Nome nome(nomeStr);

        cout << "Endereco (5-30 chars): ";
        getline(cin, enderecoStr);
        Endereco endereco(enderecoStr);

        cout << "Telefone (+DDNNNNNNNNNNNN): ";
        getline(cin, telefoneStr);
        Telefone telefone(telefoneStr);

        cout << "Codigo (10 alfanumericos): ";
        getline(cin, codigoStr);
        Codigo codigo(codigoStr);

        Hotel novoHotel;
        novoHotel.setNome(nome);
        novoHotel.setEndereco(endereco);
        novoHotel.setTelefone(telefone);
        novoHotel.setCodigo(codigo);

        if (servicoHotelaria->criarHotel(novoHotel)) {
            cout << "\nHotel cadastrado: " << nomeStr << endl;
        } else {
            cout << "\nFalha ao cadastrar no sistema (Verifique se o codigo ja existe)." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void CntrApresentacaoControle::criarQuarto() {
    limparTela();
    cout << "\n=== CADASTRO DE QUARTO ===" << endl;
    cout << "\n[Hoteis Disponiveis]:" << endl;
    vector<Hotel> hoteis = servicoHotelaria->listarHoteis();
    if (hoteis.empty()) {
        cout << "Nenhum hotel cadastrado. Cadastre um hotel primeiro!" << endl;
        cout << "Pressione Enter para voltar...";
        cin.ignore(); cin.get();
        return;
    }

    for (const auto& h : hoteis) {
        cout << "- " << h.getNome().getNome() 
             << " (Codigo: " << h.getCodigo().getCodigo() << ")" << endl;
    }
    cout << "--------------------------" << endl;

    string codigoHotelStr, numeroStr, diariaStr, capacidadeStr;

    try {
        cout << "Digite o CODIGO do Hotel para este quarto: ";
        cin >> codigoHotelStr;
        Codigo codigoHotel(codigoHotelStr);

        cout << "Numero do Quarto: ";
        cin >> numeroStr;
        Numero numero(stoi(numeroStr));

        cout << "Capacidade (1-4): ";
        cin >> capacidadeStr;
        Capacidade capacidade(stoi(capacidadeStr));

        cout << "Diaria: ";
        cin >> diariaStr;
        Dinheiro diaria(stod(diariaStr)); 

        Quarto novoQuarto;
        novoQuarto.setNumero(numero);
        novoQuarto.setCapacidade(capacidade);
        novoQuarto.setDiaria(diaria);
        if (servicoHotelaria->criarQuarto(novoQuarto, codigoHotel)) {
            cout << "\n[SUCESSO] Quarto criado e vinculado ao hotel!" << endl;
        } else {
            cout << "\n[ERRO] Hotel nao encontrado ou quarto ja existe." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n[ERRO DE VALIDACAO] " << e.what() << endl;
    } catch (...) {
        cout << "\n[ERRO] Entrada invalida." << endl;
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
            cout << "Codigo:   " << string(h.getCodigo()) << endl;
            cout << "Nome:     " << string(h.getNome()) << endl;
            cout << "Endereco: " << string(h.getEndereco()) << endl;
            cout << "Telefone: " << string(h.getTelefone()) << endl;
        }
        cout << "------------------------------------------" << endl;
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
    cout << "Digite o CODIGO do Hotel para ver os quartos: ";
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
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cout << "\nOpcao invalida. Digite apenas NUMEROS (0-4)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pressione Enter para continuar...";
            cin.get(); 
            
            continue;
        }

        switch (opcao) {
            case 1: cadastrarReserva(); break; 
            case 2: listarReservas(); break;   
            case 0: break;
            default: cout << "\nOpcao invalida!";
        }
        if (opcao != 0)
        {
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
        cout << "Codigo (10 alfanumericos): ";
        getline(cin, codigoStr);
        Codigo codigo(codigoStr);

        cout << "Data Chegada (DD/MM/AAAA, ano 2000-2999): ";
        getline(cin, chegadaStr);
        Data chegada(chegadaStr);

        cout << "Data Partida (DD/MM/AAAA, ano 2000-2999): ";
        getline(cin, partidaStr);
        Data partida(partidaStr);
        
        cout << "Valor Total (R$): ";
        if (!(cin >> valorDouble)) {
            throw std::invalid_argument("Valor total deve ser numerico.");
        }
        Dinheiro valor(valorDouble);

        Reserva novaReserva;
        novaReserva.setCodigo(codigo);
        novaReserva.setChegada(chegada);
        novaReserva.setPartida(partida);
        novaReserva.setValor(valor);

        if (servicoReservas->criarReserva(novaReserva)) {
            cout << "\nReserva criada com Codigo: " << codigoStr << endl;
        } else {
            cout << "\nFalha ao cadastrar no sistema." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << "\n Falha na entrada de dados: " << e.what() << endl;
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
            cout << "Codigo:    " << string(r.getCodigo()) << endl;
            cout << "Chegada:   " << string(r.getChegada()) << endl;
            cout << "Partida:   " << string(r.getPartida()) << endl;
            cout << "Valor:     R$ " << string(r.getValor()) << endl;
        }
        cout << "------------------------------------------" << endl;
    }
}