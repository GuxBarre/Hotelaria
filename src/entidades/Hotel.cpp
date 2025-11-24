#include "Hotel.h"

Hotel::Hotel() {}

Hotel::~Hotel() {
}

void Hotel::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Hotel::getNome() const {
    return this->nome;
}

void Hotel::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

Endereco Hotel::getEndereco() const {
    return this->endereco;
}

void Hotel::setTelefone(const Telefone& telefone) {
    this->telefone = telefone;
}

Telefone Hotel::getTelefone() const {
    return this->telefone;
}

void Hotel::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo Hotel::getCodigo() const {
    return this->codigo;
}

void Hotel::adicionarQuarto(const Quarto& quarto) {
    this->quartos.push_back(quarto);
}

std::vector<Quarto> Hotel::getQuartos() const {
    return this->quartos;
}

bool Hotel::removerQuarto(const Numero& numero) {
    for (auto it = quartos.begin(); it != quartos.end(); ++it) {
        if (it->getNumero().getNumero() == numero.getNumero()) {
            quartos.erase(it);
            return true;
        }
    }
    return false;
}
std::vector<Quarto>& Hotel::getQuartosRef() {
    return this->quartos;
}