#include "ContainerHotelaria.h"

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
    vector<Quarto> quartosAntigos = dbHoteis[chave].getQuartos();
    
    Hotel hotelAtualizado = hotel; 
    dbHoteis[chave] = hotel;
    return true;
}

bool ContainerHotelaria::excluirHotel(const Codigo& codigo) {
    string chave = codigo.getCodigo();
    if (dbHoteis.count(chave) == 0) return false;
    dbHoteis.erase(chave);
    return true;
}

// ------------------------ CRUD QUARTO ----------------------------------

bool ContainerHotelaria::criarQuarto(const Quarto& quarto, const Codigo& codigoHotel) {
    string chaveHotel = codigoHotel.getCodigo();
    if (dbHoteis.count(chaveHotel) == 0) {
        return false;
    }
    Quarto qAux;
    if (lerQuarto(quarto.getNumero(), codigoHotel, &qAux)) {
        return false; 
    }
    dbHoteis[chaveHotel].adicionarQuarto(quarto); 
    
    return true;
}

bool ContainerHotelaria::lerQuarto(const Numero& numero, const Codigo& codigoHotel, Quarto* quarto) {
    string chaveHotel = codigoHotel.getCodigo();
    if (dbHoteis.count(chaveHotel) == 0) return false;
    vector<Quarto> lista = dbHoteis[chaveHotel].getQuartos();
    
    for(const auto& q : lista) {
        if (q.getNumero().getNumero() == numero.getNumero()) {
            *quarto = q;
            return true;
        }
    }
    return false;
}

bool ContainerHotelaria::atualizarQuarto(const Quarto& quarto, const Codigo& codigoHotel) {
    string chaveHotel = codigoHotel.getCodigo();
    if (dbHoteis.count(chaveHotel) == 0) return false;
    vector<Quarto>& lista = dbHoteis[chaveHotel].getQuartosRef();
    bool removeu = dbHoteis[chaveHotel].removerQuarto(quarto.getNumero());
    if (removeu) {
        dbHoteis[chaveHotel].adicionarQuarto(quarto);
        return true;
    }
    return false;
}

bool ContainerHotelaria::excluirQuarto(const Numero& numero, const Codigo& codigoHotel) {
    string chaveHotel = codigoHotel.getCodigo();
    if (dbHoteis.count(chaveHotel) == 0) return false;
    return dbHoteis[chaveHotel].removerQuarto(numero);
}

// ------------------------ LISTAGEM -------------------------------------

vector<Hotel> ContainerHotelaria::listarHoteis() {
    vector<Hotel> lista;
    for (auto& par : dbHoteis) lista.push_back(par.second);
    return lista;
}

vector<Quarto> ContainerHotelaria::listarQuartos(const Codigo& codigoHotel) {
    string chaveHotel = codigoHotel.getCodigo();
    if (dbHoteis.count(chaveHotel) == 0) return {};
    
    return dbHoteis[chaveHotel].getQuartos();
}

bool ContainerHotelaria::hotelExiste(const Codigo& codigo) {
    return dbHoteis.count(codigo.getCodigo()) > 0;
}