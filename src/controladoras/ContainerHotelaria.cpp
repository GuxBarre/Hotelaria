#include "ContainerHotelaria.h"
#include <iostream>

using namespace std;

ContainerHotelaria::ContainerHotelaria() {}

// ------------------------ CRUD HOTEL ----------------------------------

bool ContainerHotelaria::criarHotel(const Hotel& hotel) {
    string chave = hotel.getCodigo().getCodigo();
    if (dbHoteis.count(chave) > 0) return false;
    dbHoteis[chave] = hotel;
    return true;
}

bool ContainerHotelaria::lerHotel(const Codigo& codigo, Hotel* hotel) {
    string chave = codigo.getCodigo();
    if (dbHoteis.count(chave) == 0) return false;
    *hotel = dbHoteis[chave];
    return true;
}

bool ContainerHotelaria::atualizarHotel(const Hotel& hotel) {
    string chave = hotel.getCodigo().getCodigo();
    if (dbHoteis.count(chave) == 0) return false;
    dbHoteis[chave] = hotel;
    return true;
}

bool ContainerHotelaria::excluirHotel(const Codigo& codigo) {
    string chave = codigo.getCodigo();
    if (dbHoteis.count(chave) == 0) return false;

    // OBS: seu Quarto não referencia o hotel (não existe getCodigoHotel()),
    // então não há como verificar quartos que pertencem a este hotel.
    // Neste modelo atual permitimos excluir o hotel diretamente.
    dbHoteis.erase(chave);
    return true;
}

// ------------------------ CRUD QUARTO ----------------------------------

bool ContainerHotelaria::criarQuarto(const Quarto& quarto) {
    string chave = to_string(quarto.getNumero().getNumero());
    if (dbQuartos.count(chave) > 0) return false;
    dbQuartos[chave] = quarto;
    return true;
}

bool ContainerHotelaria::lerQuarto(const Numero& numero, Quarto* quarto) {
    string chave = to_string(numero.getNumero());
    if (dbQuartos.count(chave) == 0) return false;
    *quarto = dbQuartos[chave];
    return true;
}

bool ContainerHotelaria::atualizarQuarto(const Quarto& quarto) {
    string chave = to_string(quarto.getNumero().getNumero());
    if (dbQuartos.count(chave) == 0) return false;
    dbQuartos[chave] = quarto;
    return true;
}

bool ContainerHotelaria::excluirQuarto(const Numero& numero) {
    string chave = to_string(numero.getNumero());
    if (dbQuartos.count(chave) == 0) return false;
    dbQuartos.erase(chave);
    return true;
}

// ------------------------ LISTAGEM -------------------------------------

vector<Hotel> ContainerHotelaria::listarHoteis() {
    vector<Hotel> lista;
    for (auto& par : dbHoteis) lista.push_back(par.second);
    return lista;
}

vector<Quarto> ContainerHotelaria::listarQuartos() {
    vector<Quarto> lista;
    for (auto& par : dbQuartos) lista.push_back(par.second);
    return lista;
}

bool ContainerHotelaria::hotelExiste(const Codigo& codigo) {
    return dbHoteis.count(codigo.getCodigo()) > 0;
}
