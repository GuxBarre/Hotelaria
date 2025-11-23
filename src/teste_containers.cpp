#include <iostream>
#include <vector>
#include <string>

// Includes dos Domínios
#include "dominios/Data.h"
#include "dominios/Numero.h"
#include "dominios/Codigo.h"
#include "dominios/Email.h"
#include "dominios/Senha.h"
#include "dominios/Nome.h"
#include "dominios/Capacidade.h"
#include "dominios/Dinheiro.h"

// Includes das Entidades
#include "entidades/Reserva.h"
#include "entidades/Quarto.h"
#include "entidades/Hotel.h"
#include "entidades/Gerente.h"
#include "entidades/Hospede.h"

// Includes das Controladoras (Containers)
#include "controladoras/ContainerReserva.h"
#include "controladoras/ContainerPessoal.h"
#include "controladoras/ContainerHotelaria.h"

using namespace std;

// --- Função Auxiliar para Relatório de Testes ---
void ASSERT(bool condicao, string nomeDoTeste) {
    if (condicao) {
        cout << "   [OK] " << nomeDoTeste << endl;
    } else {
        cout << "   [FALHA] " << nomeDoTeste << " (Resultado inesperado)" << endl;
    }
}

int main() {
    cout << "=======================================" << endl;
    cout << "   TESTE CONTAINERS      " << endl;
    cout << "=======================================" << endl;

    try {
        // ------------------------------------------------------------------
        // 1. TESTE: HOTELARIA (Quartos e Hoteis)
        // ------------------------------------------------------------------
        cout << "\n[1] TESTE HOTELARIA" << endl;
        ContainerHotelaria ch;
        
        // Preparar Quarto
        Quarto q1;
        q1.setNumero(Numero(101));         // Int (Corrigido)
        q1.setCapacidade(Capacidade(2));
        q1.setDiaria(Dinheiro(200.00));
        
        // Teste de Inclusão
        ASSERT(ch.criarQuarto(q1), "Criar Quarto 101");

        // Teste de Duplicidade (Deve falhar se tentar criar o mesmo número)
        ASSERT(!ch.criarQuarto(q1), "Bloquear Quarto 101 duplicado");

        // Teste de Listagem
        vector<Quarto> listaQ = ch.listarQuartos();
        ASSERT(listaQ.size() == 1, "Listagem retornou 1 quarto");


        // ------------------------------------------------------------------
        // 2. TESTE: RESERVAS (Lógica de Datas)
        // ------------------------------------------------------------------
        cout << "\n[2] TESTE RESERVAS" << endl;
        ContainerReserva cr;

        // Reserva 1: 10/Jan a 20/Jan
        Reserva r1;
        r1.setCodigo(Codigo("RES0000001"));
        r1.setChegada(Data("10/01/2025"));
        r1.setPartida(Data("20/01/2025"));
        r1.setValor(Dinheiro(1000.00));

        ASSERT(cr.criarReserva(r1), "Criar Reserva R1 (10-20 Jan)");

        // Reserva 2: 15/Jan a 25/Jan (Conflito!)
        Reserva r2;
        r2.setCodigo(Codigo("RES0000002"));
        r2.setChegada(Data("15/01/2025")); // Começa antes da R1 terminar
        r2.setPartida(Data("25/01/2025"));

        // Esperamos que retorne FALSE (Conflito detectado)
        ASSERT(!cr.criarReserva(r2), "Bloquear Reserva R2 (Conflito de data)");

        // Reserva 3: 21/Jan a 30/Jan (Sem conflito)
        Reserva r3;
        r3.setCodigo(Codigo("RES0000003"));
        r3.setChegada(Data("21/01/2025")); // Começa depois da R1
        r3.setPartida(Data("30/01/2025"));

        ASSERT(cr.criarReserva(r3), "Criar Reserva R3 (Data livre)");


        // ------------------------------------------------------------------
        // 3. TESTE: PESSOAL (Login e Usuários)
        // ------------------------------------------------------------------
        cout << "\n[3] TESTE PESSOAL" << endl;
        ContainerPessoal cp; // O construtor cria o admin automaticamente

        // Teste de Login Incorreto
        Email emailAdmin("admin@admin.com");
        Senha senhaErrada("1B#d3");
        ASSERT(!cp.validarLogin(emailAdmin, senhaErrada), "Recusar senha incorreta");

        // Teste de Login Correto (Senha ajustada para 5 chars: A1b%2)
        Senha senhaCerta("A1b%2"); 
        ASSERT(cp.validarLogin(emailAdmin, senhaCerta), "Aceitar login Admin correto");

        // Teste de Criação de Gerente
        Gerente gNew;
        gNew.setNome(Nome("Novo Gerente"));
        gNew.setEmail(Email("novo@hotel.com"));
        gNew.setSenha(Senha("G3r#1"));
        
        ASSERT(cp.criarGerente(gNew), "Criar novo Gerente");
        
        // Teste de Busca
        Gerente gBusca;
        ASSERT(cp.lerGerente(Email("novo@hotel.com"), &gBusca), "Recuperar Gerente criado");
        ASSERT(gBusca.getNome().getNome() == "Novo Gerente", "Validar dados recuperados");

    } catch (const invalid_argument& e) {
        cout << "\n[ERRO DE VALIDACAO] " << e.what() << endl;
    } catch (const exception& e) {
        cout << "\n[ERRO DE EXECUCAO] " << e.what() << endl;
    }

    cout << "\n--- FIM DOS TESTES ---" << endl;
    return 0;
}