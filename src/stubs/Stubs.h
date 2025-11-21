#ifndef STUBS_H
#define STUBS_H

#include "Interfaces.h"
#include <iostream>
#include <vector>

using namespace std;

// --- STUB AUTENTICAÇÃO ---
class StubServicoAutenticacao : public IServicoAutenticacao {
public:
    bool autenticar(const Email& email, const Senha& senha) override {
        // Simulação: Aceita qualquer login válido para facilitar o teste
        // Ou você pode forçar um específico:
        // if (email.getValor() == "admin@email.com") return true;
        cout << "[STUB] Autenticando usuario: " << string(email) << endl;
        return true; 
    }
};

// --- STUB PESSOAL ---
class StubServicoPessoal : public IServicoPessoal {
public:
    bool criarGerente(const Gerente& gerente) override { cout << "[STUB] Gerente criado." << endl; return true; }
    bool lerGerente(const Email& email, Gerente* gerente) override { return true; }
    bool atualizarGerente(const Gerente& gerente) override { return true; }
    bool excluirGerente(const Email& email) override { return true; }

    bool criarHospede(const Hospede& hospede) override { cout << "[STUB] Hospede criado." << endl; return true; }
    bool lerHospede(const Email& email, Hospede* hospede) override { return true; }
    bool atualizarHospede(const Hospede& hospede) override { return true; }
    bool excluirHospede(const Email& email) override { return true; }

    vector<Hospede> listarHospedes() override {
    // Cria uma lista falsa para testar a tela
    vector<Hospede> listaFalsa;

    // Hóspede 1
    Hospede h1;
    h1.setNome(Nome("Joao Da Silva"));
    h1.setEmail(Email("joao@teste.com"));
    h1.setEndereco(Endereco("Rua A, 100"));
    h1.setCartao(Cartao("4000000000000002"));
    listaFalsa.push_back(h1);

    // Hóspede 2
    Hospede h2;
    h2.setNome(Nome("Maria Souza"));
    h2.setEmail(Email("maria@teste.com"));
    h2.setEndereco(Endereco("Av Brasil, 2000"));
    h2.setCartao(Cartao("4000000000000002"));
    listaFalsa.push_back(h2);

    return listaFalsa;
}
};

// --- STUB HOTELARIA ---
class StubServicoHotelaria : public IServicoHotelaria {
public:
    bool criarHotel(const Hotel& hotel) override { cout << "[STUB] Hotel criado." << endl; return true; }
    bool lerHotel(const Codigo& codigo, Hotel* hotel) override { return true; }
    bool atualizarHotel(const Hotel& hotel) override { return true; }
    bool excluirHotel(const Codigo& codigo) override { return true; }

    bool criarQuarto(const Quarto& quarto) override { cout << "[STUB] Quarto criado." << endl; return true; }
    bool lerQuarto(const Numero& numero, Quarto* quarto) override { return true; }
    bool atualizarQuarto(const Quarto& quarto) override { return true; }
    bool excluirQuarto(const Numero& numero) override { return true; }

    vector<Hotel> listarHoteis() override { return vector<Hotel>(); }
    vector<Quarto> listarQuartos() override { return vector<Quarto>(); }
};

// --- STUB RESERVAS ---
class StubServicoReservas : public IServicoReservas {
public:
    bool criarReserva(const Reserva& reserva) override { cout << "[STUB] Reserva criada." << endl; return true; }
    bool lerReserva(const Codigo& codigo, Reserva* reserva) override { return true; }
    bool atualizarReserva(const Reserva& reserva) override { return true; }
    bool excluirReserva(const Codigo& codigo) override { return true; }

    vector<Reserva> listarReservas() override {
    vector<Reserva> listaFalsa;
    Reserva r1;
    r1.setCodigo(Codigo("RES0000001"));
    r1.setChegada(Data("01/01/2026"));
    r1.setPartida(Data("05/01/2026"));
    r1.setValor(Dinheiro(550.00));
    listaFalsa.push_back(r1);

    return listaFalsa;
}
};

#endif // STUBS_H