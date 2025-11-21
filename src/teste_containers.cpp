#include <iostream>

#include "controladoras/ContainerPessoal.h"
#include "controladoras/ContainerHotelaria.h"
#include "controladoras/ContainerReserva.h"

using namespace std;

int main() {
    cout << "===== TESTE DO SISTEMA =====\n\n";

    // ------------------------------------------------------------
    // 1. Testar PESSOAL
    // ------------------------------------------------------------
    cout << ">> Testando ContainerPessoal...\n";

    ContainerPessoal cp;

    // Criar novo gerente
    Gerente g;
    g.setEmail(Email("gerente@hotel.com"));
    g.setSenha(Senha("Abc123"));
    g.setNome(Nome("Gerente Teste"));

    cout << "Criar gerente: " 
         << (cp.criarGerente(g) ? "OK" : "FALHOU") << endl;

    // Ler gerente
    Gerente g2;
    cout << "Ler gerente: "
         << (cp.lerGerente(Email("gerente@hotel.com"), &g2) ? "OK" : "FALHOU")
         << endl;

    // Validar login
    cout << "Autenticar (correto): "
         << (cp.validarLogin(Email("admin@admin.com"), Senha("Admin1")) ? "OK" : "FALHOU")
         << endl;

    cout << "Autenticar (incorreto): "
         << (cp.validarLogin(Email("admin@admin.com"), Senha("Errado1")) ? "FALHOU" : "OK")
         << endl;


    // ------------------------------------------------------------
    // 2. Testar HOTELARIA
    // ------------------------------------------------------------
    cout << "\n>> Testando ContainerHotelaria...\n";

    ContainerHotelaria ch;

    // Criar hotel
    Hotel h;
    h.setCodigo(Codigo("H1"));
    h.setNome(Nome("Hotel Central"));

    cout << "Criar hotel: "
         << (ch.criarHotel(h) ? "OK" : "FALHOU") << endl;

    // Criar quarto
    Quarto q;
    q.setNumero(Numero("101"));
    q.setCodigoHotel(Codigo("H1"));
    q.setCapacidade(Capacidade(2));

    cout << "Criar quarto: "
         << (ch.criarQuarto(q) ? "OK" : "FALHOU") << endl;

    // Tentar excluir hotel que possui quartos
    cout << "Excluir hotel com quartos (esperado FALHAR): "
         << (ch.excluirHotel(Codigo("H1")) ? "FALHOU" : "OK")
         << endl;


    // ------------------------------------------------------------
    // 3. Testar RESERVAS
    // ------------------------------------------------------------
    cout << "\n>> Testando ContainerReservas...\n";

    ContainerReservas cr;

    // Criar reserva 1
    Reserva r1;
    r1.setCodigo(Codigo("R1"));
    r1.setCodigoHotel(Codigo("H1"));
    r1.setNumeroQuarto(Numero("101"));
    r1.setDataCheckIn(Data("2025-01-10"));
    r1.setDataCheckOut(Data("2025-01-20"));

    cout << "Criar reserva 1: "
         << (cr.criarReserva(r1) ? "OK" : "FALHOU") << endl;

    // Criar reserva 2 com conflito
    Reserva r2;
    r2.setCodigo(Codigo("R2"));
    r2.setCodigoHotel(Codigo("H1"));
    r2.setNumeroQuarto(Numero("101"));
    r2.setDataCheckIn(Data("2025-01-15"));  // conflito
    r2.setDataCheckOut(Data("2025-01-18"));

    cout << "Criar reserva 2 (deve falhar por conflito): "
         << (cr.criarReserva(r2) ? "FALHOU" : "OK")
         << endl;

    // Criar reserva 3 sem conflito
    Reserva r3;
    r3.setCodigo(Codigo("R3"));
    r3.setCodigoHotel(Codigo("H1"));
    r3.setNumeroQuarto(Numero("101"));
    r3.setDataCheckIn(Data("2025-01-21"));
    r3.setDataCheckOut(Data("2025-01-30"));

    cout << "Criar reserva 3: "
         << (cr.criarReserva(r3) ? "OK" : "FALHOU") << endl;

    // Listar reservas
    auto lista = cr.listarReservas();
    cout << "\nListando reservas:\n";
    for (auto& r : lista) {
        cout << "- Reserva " << r.getCodigo().getValor() << endl;
    }

    cout << "\n===== FIM DOS TESTES =====\n";
    return 0;
}
