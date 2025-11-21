#include "Endereco.h"

void Endereco::validarEndereco(const std::string& endereco) const {

    if (endereco.length() < 5 || endereco.length() > 30) {
        throw std::invalid_argument("Erro: Endereço deve ter entre 5 e 30 caracteres.");
    }

    for (size_t i = 0; i < endereco.length(); i++) {
        char c = endereco[i];
        bool isLetra = isalpha(c);
        bool isDigito = isdigit(c);
        bool isPonto = (c == '.');
        bool isVirgula = (c == ',');
        bool isEspaco = (c == ' ');

        if (!isLetra && !isDigito && !isPonto && !isVirgula && !isEspaco) {
            throw std::invalid_argument("Endereco contem caractere invalido.");
        }

        if (i == 0 || i == endereco.length() - 1) {
            if (isPonto || isVirgula || isEspaco) {
                throw std::invalid_argument("Endereco nao pode comecar ou terminar com ponto, virgula ou espaco.");
            }
        }

        if (i < endereco.length() - 1) {
            char next = endereco[i+1];
            bool nextIsPonto = (next == '.');
            bool nextIsVirgula = (next == ',');
            bool nextIsEspaco = (next == ' ');

            if (isVirgula && (nextIsVirgula || nextIsPonto)) {
                throw std::invalid_argument("Virgula nao pode ser seguida de ponto ou virgula.");
            }

            if (isPonto && (nextIsVirgula || nextIsPonto)) {
                throw std::invalid_argument("Ponto nao pode ser seguido de ponto ou virgula.");
            }

            if (isEspaco && !(isalpha(next) || isdigit(next))) {
                throw std::invalid_argument("Espaco deve ser seguido de letra ou numero.");
            }
        }
    }
}
    

Endereco::Endereco() {
    this->valor = "";
} 

void Endereco::setEndereco(const std::string& endereco) {
    validarEndereco(endereco);
    this->valor = endereco;
}

Endereco::Endereco(const std::string& endereco) {
    setEndereco(endereco);
}

std::string Endereco::getEndereco() const {
    return this->valor;
}