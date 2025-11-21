#include "Email.h"
#include <vector>

using namespace std;

Email::Email() {
    this->valor = "teste@dominio.com";
}

Email::Email(string email) {
    setEmail(email);
}

Email::~Email() {
}

void Email::validar(string email) {
    size_t posArroba = email.find('@');
    if (posArroba == string::npos || posArroba == 0 || posArroba == email.length() - 1) {
        throw invalid_argument("Erro: Formato invalido. Deve ser parte-local@dominio.");
    }
    if (email.find('@', posArroba + 1) != string::npos) {
        throw invalid_argument("Erro: Email deve ter apenas um '@'.");
    }

    string local = email.substr(0, posArroba);
    string dominio = email.substr(posArroba + 1);

    if (local.length() > 64) {
        throw invalid_argument("Erro: Parte local excede 64 caracteres.");
    }

    if (local.front() == '.' || local.front() == '-' || 
        local.back() == '.' || local.back() == '-') {
        throw invalid_argument("Erro: Parte local nao pode iniciar ou terminar com ponto ou hifen.");
    }

    for (size_t i = 0; i < local.length(); i++) {
        char c = local[i];
    
        bool ehLetra = (c >= 'a' && c <= 'z');
        bool ehDigito = (c >= '0' && c <= '9');
        bool ehPonto = (c == '.');
        bool ehHifen = (c == '-');

        if (!ehLetra && !ehDigito && !ehPonto && !ehHifen) {
            throw invalid_argument("Erro: Caractere invalido na parte local.");
        }

        if (ehPonto || ehHifen) {
            if (i + 1 < local.length()) {
                char prox = local[i+1];
                bool proxLetra = (prox >= 'a' && prox <= 'z');
                bool proxDigito = (prox >= '0' && prox <= '9');
                
                if (!proxLetra && !proxDigito) {
                    throw invalid_argument("Erro: Ponto ou hifen deve ser seguido por letra ou digito.");
                }
            }
        }
    }
    if (dominio.length() > 255) {
        throw invalid_argument("Erro: Dominio excede 255 caracteres.");
    }
    
    if (dominio.front() == '.' || dominio.back() == '.') {
        throw invalid_argument("Erro: Dominio nao pode iniciar ou terminar com ponto.");
    }

    size_t inicioParte = 0;
    size_t posPonto = dominio.find('.', inicioParte);

    while (inicioParte < dominio.length()) {
        size_t fimParte = (posPonto == string::npos) ? dominio.length() : posPonto;
        
        string parte = dominio.substr(inicioParte, fimParte - inicioParte);

        if (parte.empty()) {
            throw invalid_argument("Erro: Dominio contem partes vazias (pontos consecutivos).");
        }

        if (parte.front() == '-' || parte.back() == '-') {
            throw invalid_argument("Erro: Parte do dominio nao pode iniciar ou terminar com hifen.");
        }

        for (char c : parte) {
            bool ehLetra = (c >= 'a' && c <= 'z');
            bool ehDigito = (c >= '0' && c <= '9');
            bool ehHifen = (c == '-');

            if (!ehLetra && !ehDigito && !ehHifen) {
                throw invalid_argument("Erro: Caractere invalido no dominio.");
            }
        }

        if (posPonto == string::npos) {
            break;
        }
        inicioParte = posPonto + 1;
        posPonto = dominio.find('.', inicioParte);
    }
}

void Email::setEmail(string email) {
    validar(email);
    this->valor = email;
}

string Email::getEmail() const {
    return valor;
}