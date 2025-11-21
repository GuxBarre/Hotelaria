#include "Nome.h"
#include <cctype> 
#include <string>
using namespace std;

Nome::Nome() {
    this->nome = "Nome Padrao";
}

Nome::Nome(string nome) {
    setNome(nome);
}

Nome::~Nome() {
}

void Nome::validar(string nome) {
    if (nome.length() < 5 || nome.length() > 20) {
        throw invalid_argument("Nome deve ter entre 5 e 20 caracteres.");
    }

    for (size_t i = 0; i < nome.length(); i++) {
        char c = nome[i];

        if (!isalpha(c) && c != ' ') {
            throw invalid_argument("Nome contem caracteres invalidos (apenas letras e espaco).");
        }

        if (c == ' ') {
            if (i == nome.length() - 1) {
                throw invalid_argument("Nome nao pode terminar com espaco.");
            }
            if (!isalpha(nome[i + 1])) {
                throw invalid_argument("Espaco deve ser seguido por letra (sem espacos duplos).");
            }
        }

        bool deveSerMaiuscula = (i == 0) || (nome[i - 1] == ' ');
        
        if (deveSerMaiuscula) {
            if (!isupper(c)) {
                throw invalid_argument("Primeira letra de cada termo deve ser maiuscula.");
            }
        }
    }
}

void Nome::setNome(string nome) {
    validar(nome);
    this->nome = nome;
}

string Nome::getNome() const {
    return nome;
}

Nome::operator string() const {
    return nome;
}