#include <iostream>
#include <stdexcept>
#include <string>

#include "entidades/Pessoa.h"
#include "entidades/Gerente.h"
#include "entidades/Hospede.h"
#include "entidades/Hotel.h"
#include "entidades/Quarto.h"
#include "entidades/Reserva.h"

using namespace std;

void imprimirCabecalho(const string& titulo) {
    cout << "\n========================================" << endl;
    cout << "       TESTANDO: " << titulo << endl;
    cout << "========================================" << endl;
}

int main() {
    
    imprimirCabecalho("ENTIDADE: PESSOA");

    try {
        cout << "1. Criando Pessoa" << endl;
        Pessoa p;

        p.setNome(Nome("Fulano Da Silva"));
        p.setEmail(Email("fulano@exemplo.com"));

        cout << "   [SUCESSO] Pessoa criada." << endl;
        cout << "   Nome: " << string(p.getNome()) << endl;
        cout << "   Email: " << string(p.getEmail()) << endl;

    } catch (const exception& e) {
        cout << "   [ERRO INESPERADO] " << e.what() << endl;
    }

    imprimirCabecalho("ENTIDADE: GERENTE");

    try {
        cout << "2. Criando Gerente" << endl;
        Gerente g;

        g.setNome(Nome("Gerente Silva"));
        g.setEmail(Email("gerente@hotel.com"));

        g.setRamal(Ramal(22));
        g.setSenha(Senha("A1b%2"));

        cout << "   [SUCESSO] Gerente criado." << endl;
        cout << "   Nome (Herdado): " << string(g.getNome())<< endl;
        cout << "   Email (Herdado): " << string(g.getEmail())<< endl;
        cout << "   Ramal (Proprio): " << string(g.getRamal()) << endl;
        cout << "   Senha (Proprio): " << string(g.getSenha()) << endl;

    } catch (const exception& e) {
        cout << "   [ERRO] " << e.what() << endl;
    }

    imprimirCabecalho("ENTIDADE: HOSPEDE");

    try {
        cout << "3. Criando Hospede" << endl;
        Hospede h;

        h.setNome(Nome("Hospede Exemplo"));
        h.setEmail(Email("hospede@email.com"));

        h.setEndereco(Endereco("Rua das Ferias, 100"));
        h.setCartao(Cartao("4000000000000002")); 

        cout << "   [SUCESSO] Hospede criado." << endl;
        cout << "   Nome (Herdado): " << string(h.getNome()) << endl;
        cout << "   Email (Herdado): " << string(h.getEmail())<< endl;
        cout << "   Endereço (Proprio): " << string(h.getEndereco()) << endl;
        cout << "   Cartão (Proprio): " << string(h.getCartao()) << endl;

    } catch (const exception& e) {
        cout << "   [ERRO] " << e.what() << endl;
    }

    imprimirCabecalho("ENTIDADE: HOTEL");

    try {
        cout << "4. Criando Hotel" << endl;
        Hotel h;

        h.setNome(Nome("Hotel California"));
        h.setEndereco(Endereco("Rua da Praia, 500"));
        h.setTelefone(Telefone("+5521999998888"));
        h.setCodigo(Codigo("HOTEL00001"));

        cout << "   [SUCESSO] Hotel criado." << endl;
        cout << "   Nome (Proprio): " << string(h.getNome()) << endl;
        cout << "   Endereço (Proprio): " << string(h.getEndereco()) << endl;
        cout << "   Telefone (Proprio): " << string(h.getTelefone()) << endl;
        cout << "   Código (Proprio): " << string(h.getCodigo()) << endl;

    } catch (const exception& e) {
        cout << "   [ERRO] " << e.what() << endl;
    }

    imprimirCabecalho("ENTIDADE: QUARTO");

    try {
        cout << "5. Criando Hotel" << endl;
        Quarto q;

        q.setNumero(Numero(101));    
        q.setCapacidade(Capacidade(2));
        q.setDiaria(Dinheiro(250.00));
        q.setRamal(Ramal(15));

        cout << "   [SUCESSO] Quarto criado." << endl;
        cout << "   Numero: " << string(q.getNumero()) << endl;
        cout << "   Capacidade: " << string(q.getCapacidade()) << " pessoas" << endl;
        cout << "   Diaria: R$ " << string(q.getDiaria()) << endl;
        cout << "   Ramal: " << string(q.getRamal()) << endl;

    } catch (const exception& e) {
        cout << "   [FALHA INESPERADA] " << e.what() << endl;
    }

    imprimirCabecalho("ENTIDADE: RESERVA");

    try {
        cout << "6. Criando Reserva" << endl;
        Reserva r;

        // Codigo deve ter 10 chars (alfanumericos)
        r.setCodigo(Codigo("RES0000001")); 
        
        // Datas no formato DD/MM/AAAA
        r.setChegada(Data("24/12/2025"));
        r.setPartida(Data("31/12/2025"));
        
        // Valor total da reserva
        r.setValor(Dinheiro(1500.00));

        cout << "   [SUCESSO] Reserva criada." << endl;
        cout << "   Codigo: " << string(r.getCodigo()) << endl;
        cout << "   Chegada: " << string(r.getChegada()) << endl;
        cout << "   Partida: " << string(r.getPartida()) << endl;
        cout << "   Valor Total: R$ " << string(r.getValor()) << endl;

    } catch (const exception& e) {
        cout << "   [FALHA INESPERADA] " << e.what() << endl;
    }

    return 0;
}