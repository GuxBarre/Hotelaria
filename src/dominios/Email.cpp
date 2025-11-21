#include "Email.h"
#include <stdexcept>
#include <cctype>   // std::tolower

using namespace std;

static bool ehLetraMinuscula(char c) {
    c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    return (c >= 'a' && c <= 'z');
}

static bool ehDigito(char c) {
    return (c >= '0' && c <= '9');
}

void Email::validar(const string &email) {
    // 1. Tem que ter exatamente um '@' e não pode ser primeiro nem último
    size_t posArroba = email.find('@');
    if (posArroba == string::npos || posArroba == 0 || posArroba == email.size() - 1) {
        throw invalid_argument("Email invalido: formato parte-local@dominio incorreto.");
    }
    if (email.find('@', posArroba + 1) != string::npos) {
        throw invalid_argument("Email invalido: mais de um '@'.");
    }

    string local = email.substr(0, posArroba);
    string dominio = email.substr(posArroba + 1);

    // 2. Tamanhos
    if (local.size() == 0 || local.size() > 64) {
        throw invalid_argument("Email invalido: tamanho da parte local invalido.");
    }
    if (dominio.size() == 0 || dominio.size() > 255) {
        throw invalid_argument("Email invalido: tamanho do dominio invalido.");
    }

    // 3. Validar parte local
    //    letras (a-z), digitos (0-9), ponto (.) ou hifen (-)
    //    nao pode iniciar/terminar com '.' ou '-'
    //    '.' ou '-' deve ser seguido por letra ou digito
    if (local.front() == '.' || local.front() == '-' ||
        local.back()  == '.' || local.back()  == '-') {
        throw invalid_argument("Email invalido: parte local começa/termina com '.' ou '-'.");
    }

    for (size_t i = 0; i < local.size(); ++i) {
        char c = local[i];

        bool okChar = ehLetraMinuscula(c) || ehDigito(c) || c == '.' || c == '-';
        if (!okChar) {
            throw invalid_argument("Email invalido: caractere invalido na parte local.");
        }

        if (c == '.' || c == '-') {
            if (i + 1 >= local.size()) {
                throw invalid_argument("Email invalido: '.' ou '-' na parte local no final.");
            }
            char prox = local[i + 1];
            if (!ehLetraMinuscula(prox) && !ehDigito(prox)) {
                // impede '..', '.-', '--', '-.' etc.
                throw invalid_argument("Email invalido: '.' ou '-' deve ser seguido de letra ou digito na parte local.");
            }
        }
    }

    // 4. Validar dominio
    //    composto por uma ou mais partes separadas por '.'
    //    cada parte: letras (a-z), digitos (0-9) ou hifen (-)
    //    nao pode iniciar/terminar com hifen
    //    e nao pode ter partes vazias (ou seja, "algo..com" invalido)
    if (dominio.front() == '.' || dominio.back() == '.') {
        throw invalid_argument("Email invalido: dominio nao pode comecar/terminar com '.'.");
    }

    size_t inicio = 0;
    while (inicio < dominio.size()) {
        size_t ponto = dominio.find('.', inicio);
        if (ponto == string::npos) {
            ponto = dominio.size();
        }

        // pedaço do dominio entre dois pontos
        if (ponto == inicio) {
            throw invalid_argument("Email invalido: partes vazias no dominio.");
        }

        string parte = dominio.substr(inicio, ponto - inicio);

        // nao pode comecar/terminar com '-'
        if (parte.front() == '-' || parte.back() == '-') {
            throw invalid_argument("Email invalido: parte do dominio comeca/termina com '-'.");
        }

        for (char c : parte) {
            bool okChar = ehLetraMinuscula(c) || ehDigito(c) || c == '-';
            if (!okChar) {
                throw invalid_argument("Email invalido: caractere invalido no dominio.");
            }
        }

        if (ponto == dominio.size()) break;
        inicio = ponto + 1; // pula o '.'
    }
}

void Email::setValor(const string &email) {
    validar(email);
    this->valor = email;
}

string Email::getValor() const {
    return valor;
}
