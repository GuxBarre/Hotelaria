#include <iostream>
#include <vector>
#include <string>

#include "dominios/Data.h"
#include "dominios/Numero.h"
#include "dominios/Codigo.h"
#include "dominios/Email.h"
#include "dominios/Senha.h"
#include "dominios/Nome.h"
#include "dominios/Capacidade.h"
#include "dominios/Dinheiro.h"
#include "dominios/Ramal.h"
#include "dominios/Endereco.h"
#include "dominios/Telefone.h"

#include "entidades/Reserva.h"
#include "entidades/Quarto.h"
#include "entidades/Hotel.h"
#include "entidades/Gerente.h"
#include "entidades/Hospede.h"

#include "controladoras/ContainerReserva.h"
#include "controladoras/ContainerPessoal.h"
#include "controladoras/ContainerHotelaria.h"

using namespace std;

void ASSERT(bool condicao, string nomeDoTeste) {
    if (condicao) {
        cout << "   [OK] " << nomeDoTeste << endl;
    } else {
        cout << "   [FALHA] " << nomeDoTeste << " (Resultado inesperado)" << endl;
    }
}

int main() {
    cout << "=======================================" << endl;
    cout << "      TESTE DE INTEGRAÇÃO (CONTAINERS) " << endl;
    cout << "=======================================" << endl;

    try {
        cout << "\n[1] TESTE HOTELARIA" << endl;
        ContainerHotelaria ch;
        Hotel h1;
        Codigo codHotel("RIO0000001");
        h1.setCodigo(codHotel);
        h1.setNome(Nome("Hotel Teste"));
        h1.setEndereco(Endereco("Rua Teste, 100"));
        h1.setTelefone(Telefone("+5521999998888"));
        
        ASSERT(ch.criarHotel(h1), "Criar Hotel 'RIO0000001'");
        Quarto q1;
        q1.setNumero(Numero(101));       
        q1.setCapacidade(Capacidade(2));
        q1.setDiaria(Dinheiro(200.00));
        ASSERT(ch.criarQuarto(q1, codHotel), "Criar Quarto 101 no Hotel RIO0000001");
        ASSERT(!ch.criarQuarto(q1, codHotel), "Bloquear Quarto 101 duplicado");
        vector<Quarto> listaQ = ch.listarQuartos(codHotel);
        ASSERT(listaQ.size() == 1, "Listagem retornou 1 quarto");
        vector<Quarto> listaVazia = ch.listarQuartos(Codigo("XYZ0000000"));
        ASSERT(listaVazia.empty(), "Listagem de hotel inexistente vazia");
        cout << "\n[2] TESTE RESERVAS" << endl;
        ContainerReserva cr;
        Reserva r1;
        r1.setCodigo(Codigo("RES0000001"));
        r1.setChegada(Data("10/01/2025"));
        r1.setPartida(Data("20/01/2025"));
        r1.setValor(Dinheiro(1000.00));

        ASSERT(cr.criarReserva(r1), "Criar Reserva R1 (10-20 Jan)");
        Reserva r2;
        r2.setCodigo(Codigo("RES0000002"));
        r2.setChegada(Data("15/01/2025"));
        r2.setPartida(Data("25/01/2025"));
        ASSERT(!cr.criarReserva(r2), "Bloquear Reserva R2 (Conflito de data)");

        Reserva r3;
        r3.setCodigo(Codigo("RES0000003"));
        r3.setChegada(Data("21/01/2025"));
        r3.setPartida(Data("30/01/2025"));

        ASSERT(cr.criarReserva(r3), "Criar Reserva R3 (Data livre)");
        cout << "\n[3] TESTE PESSOAL" << endl;
        ContainerPessoal cp; 
        Gerente gNew;
        gNew.setNome(Nome("Gerente Teste"));
        gNew.setEmail(Email("teste@hotel.com"));
        gNew.setSenha(Senha("X1y%2"));
        gNew.setRamal(Ramal(2));

        ASSERT(cp.criarGerente(gNew), "Criar novo Gerente");
        Gerente gRecuperado;
        Email emailLogin("teste@hotel.com");
        bool achou = cp.lerGerente(emailLogin, &gRecuperado);
        ASSERT(achou, "Encontrar email no banco");
        if (achou) {
            string senhaBanco = gRecuperado.getSenha().getSenha();
            ASSERT(senhaBanco == "X1y%2", "Senha armazenada confere");
            ASSERT(senhaBanco != "Errado1", "Senha errada nao confere");
        }
        ASSERT(gRecuperado.getNome().getNome() == "Gerente Teste", "Nome recuperado correto");

    } catch (const invalid_argument& e) {
        cout << "\n[ERRO DE VALIDACAO] " << e.what() << endl;
    } catch (const exception& e) {
        cout << "\n[ERRO DE EXECUCAO] " << e.what() << endl;
    }

    cout << "\n--- FIM DOS TESTES ---" << endl;
    return 0;
}