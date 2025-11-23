#include "ContainerReserva.h"
#include <iostream>
#include <string>

using namespace std;

ContainerReserva::ContainerReserva() {}

// Helper: Converte "DD/MM/AAAA" para "AAAA-MM-DD" para comparação de strings funcionar
static string converterParaISO(const string& dataBR) {
    // Formato esperado: DD/MM/AAAA (10 chars)
    if (dataBR.length() != 10) return dataBR; 
    
    string dia = dataBR.substr(0, 2);
    string mes = dataBR.substr(3, 2);
    string ano = dataBR.substr(6, 4);
    
    return ano + "-" + mes + "-" + dia;
}

static bool overlap(const string& aStartBR, const string& aEndBR, const string& bStartBR, const string& bEndBR) {
    string aStart = converterParaISO(aStartBR);
    string aEnd   = converterParaISO(aEndBR);
    string bStart = converterParaISO(bStartBR);
    string bEnd   = converterParaISO(bEndBR);

    return !(aEnd < bStart || bEnd < aStart);
}

bool ContainerReserva::criarReserva(const Reserva& reserva) {
    string chave = reserva.getCodigo().getCodigo();
    if (dbReservas.count(chave) > 0) return false;

    // Verificar conflito global de datas (Simplificado pois Reserva nao tem ID do quarto no modelo)
    for (auto& par : dbReservas) {
        const Reserva& r2 = par.second;
        if (conflitoDeDatas(reserva, r2)) return false;
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

    // Verificar conflitos ignorando a própria reserva
    for (auto& par : dbReservas) {
        if (par.first == chave) continue;
        const Reserva& r2 = par.second;
        if (conflitoDeDatas(reserva, r2)) return false;
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
    return overlap(r1.getChegada().getData(), r1.getPartida().getData(),
                   r2.getChegada().getData(), r2.getPartida().getData());
}