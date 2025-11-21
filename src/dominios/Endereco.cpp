#include "Endereco.h"
#include <string>
using namespace std;
void Endereco::validarEndereco(const string& endereco) const {

    if (endereco.length() < 5 || endereco.length() > 30) {
        throw invalid_argument("Endereço deve ter entre 5 e 30 caracteres.");
    }

    for (size_t i = 0; i < endereco.length(); i++) {
        char c = endereco[i];
        bool isLetra = isalpha(c);
        bool isDigito = isdigit(c);
        bool isPonto = (c == '.');
        bool isVirgula = (c == ',');
        bool isEspaco = (c == ' ');

        if (!isLetra && !isDigito && !isPonto && !isVirgula && !isEspaco) {
            throw invalid_argument("Endereco contem caractere invalido.");
        }

        if (i == 0 || i == endereco.length() - 1) {
            if (isPonto || isVirgula || isEspaco) {
                throw invalid_argument("Endereco nao pode comecar ou terminar com ponto, virgula ou espaco.");
            }
        }

        if (i < endereco.length() - 1) {
            char next = endereco[i+1];
            bool nextIsPonto = (next == '.');
            bool nextIsVirgula = (next == ',');
            bool nextIsEspaco = (next == ' ');

            if (isVirgula && (nextIsVirgula || nextIsPonto)) {
                throw invalid_argument("Virgula nao pode ser seguida de ponto ou virgula.");
            }

            if (isPonto && (nextIsVirgula || nextIsPonto)) {
                throw invalid_argument("Ponto nao pode ser seguido de ponto ou virgula.");
            }

            if (isEspaco && !(isalpha(next) || isdigit(next))) {
                throw invalid_argument("Espaco deve ser seguido de letra ou numero.");
            }
        }
    }
}
    

Endereco::Endereco() {
    this->endereco = "Rua Padrao";
} 

void Endereco::setEndereco(const string& endereco) {
    validarEndereco(endereco);
    this->endereco = endereco;
}

Endereco::Endereco(const string& endereco) {
    setEndereco(endereco);
}

string Endereco::getEndereco() const {
    return this->endereco;
}

Endereco::operator string() const {
    return endereco;
}