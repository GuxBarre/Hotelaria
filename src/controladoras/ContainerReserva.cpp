#include "ContainerReserva.h"
#include <iostream>

using namespace std;

ContainerReserva::ContainerReserva() {}

// Helper: compara strings de data retornadas por Data::getData()
// ATENÇÃO: funciona corretamente se Data::getData() retorna formato lexicograficamente ordenável,
// por exemplo \"YYYY-MM-DD\". Se for \"DD/MM/YYYY\" a comparação precisa de normalização.
static bool overlap(const string& aStart, const string& aEnd, const string& bStart, const string& bEnd) {
    return !(aEnd < bStart || bEnd < aStart);
}

bool ContainerReserva::criarReserva(const Reserva& reserva) {
    string chave = reserva.getCodigo().getCodigo();
    if (dbReservas.count(chave) > 0) return false;

    // verificar conflito global (modelo atual da entidade)
    for (auto& par : dbReservas) {
        const Reserva& r2 = par.second;
        string s1 = reserva.getChegada().getData();
        string e1 = reserva.getPartida().getData();
        string s2 = r2.getChegada().getData();
        string e2 = r2.getPartida().getData();
        if (overlap(s1,e1,s2,e2)) return false;
    }

    dbReservas[chave] = reserva;
    return true;
}

bool ContainerReserva::lerReserva(const Codigo& codigo, Reserva* reserva) {
    string chave = codigo.getCodigo();
    if (dbReservas.count(chave) == 0) return false;
    *reserva = dbReservas[chave];
    return true;
}

bool ContainerReserva::atualizarReserva(const Reserva& reserva) {
    string chave = reserva.getCodigo().getCodigo();
    if (dbReservas.count(chave) == 0) return false;

    // verificar conflitos com outras reservas (excluindo a própria)
    for (auto& par : dbReservas) {
        if (par.first == chave) continue;
        const Reserva& r2 = par.second;
        string s1 = reserva.getChegada().getData();
        string e1 = reserva.getPartida().getData();
        string s2 = r2.getChegada().getData();
        string e2 = r2.getPartida().getData();
        if (overlap(s1,e1,s2,e2)) return false;
    }

    dbReservas[chave] = reserva;
    return true;
}

bool ContainerReserva::excluirReserva(const Codigo& codigo) {
    string chave = codigo.getCodigo();
    if (dbReservas.count(chave) == 0) return false;
    dbReservas.erase(chave);
    return true;
}

vector<Reserva> ContainerReserva::listarReservas() {
    vector<Reserva> lista;
    for (auto& par : dbReservas) lista.push_back(par.second);
    return lista;
}

bool ContainerReserva::conflitoDeDatas(const Reserva& r1, const Reserva& r2) {
    string ini1 = r1.getChegada().getData();
    string fim1 = r1.getPartida().getData();
    string ini2 = r2.getChegada().getData();
    string fim2 = r2.getPartida().getData();
    return overlap(ini1,fim1,ini2,fim2);
}
