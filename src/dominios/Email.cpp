#include "Email.h"
#include <vector> // Útil para separar o domínio em partes, se desejar, ou fazemos manual

using namespace std;

Email::Email() {
    this->valor = "teste@dominio.com"; // Valor padrão válido
}

Email::Email(string email) {
    setValor(email);
}

Email::~Email() {
}

void Email::validar(string email) {
    // 1. Verificação básica do @
    size_t posArroba = email.find('@');
    if (posArroba == string::npos || posArroba == 0 || posArroba == email.length() - 1) {
        throw invalid_argument("Erro: Formato invalido. Deve ser parte-local@dominio.");
    }
    
    // Verifica se existe mais de um @
    if (email.find('@', posArroba + 1) != string::npos) {
        throw invalid_argument("Erro: Email deve ter apenas um '@'.");
    }

    string local = email.substr(0, posArroba);
    string dominio = email.substr(posArroba + 1);

    // 2. Validação da Parte Local
    if (local.length() > 64) {
        throw invalid_argument("Erro: Parte local excede 64 caracteres.");
    }

    // Regra: Não pode iniciar ou terminar com . ou -
    if (local.front() == '.' || local.front() == '-' || 
        local.back() == '.' || local.back() == '-') {
        throw invalid_argument("Erro: Parte local nao pode iniciar ou terminar com ponto ou hifen.");
    }

    for (size_t i = 0; i < local.length(); i++) {
        char c = local[i];
        
        // Validar caracteres permitidos (a-z, 0-9, ., -)
        // Nota: A regra pede a-z (minusculas), entao checamos o intervalo ASCII
        bool ehLetra = (c >= 'a' && c <= 'z');
        bool ehDigito = (c >= '0' && c <= '9');
        bool ehPonto = (c == '.');
        bool ehHifen = (c == '-');

        if (!ehLetra && !ehDigito && !ehPonto && !ehHifen) {
            throw invalid_argument("Erro: Caractere invalido na parte local.");
        }

        // Regra: Ponto ou hifen deve ser seguido por letra ou digito
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

    // 3. Validação do Domínio
    if (dominio.length() > 255) {
        throw invalid_argument("Erro: Dominio excede 255 caracteres.");
    }
    
    // Regra: Domínio não pode ter partes vazias (ex: ..) ou começar/terminar com ponto
    if (dominio.front() == '.' || dominio.back() == '.') {
        throw invalid_argument("Erro: Dominio nao pode iniciar ou terminar com ponto.");
    }

    // Percorrer o domínio para validar caracteres e pontos consecutivos
    size_t inicioParte = 0;
    size_t posPonto = dominio.find('.', inicioParte);

    while (inicioParte < dominio.length()) {
        // Se não achar mais pontos, define o fim como o final da string
        size_t fimParte = (posPonto == string::npos) ? dominio.length() : posPonto;
        
        // Extrai a parte atual (ex: "gmail" de "gmail.com")
        string parte = dominio.substr(inicioParte, fimParte - inicioParte);

        if (parte.empty()) {
            throw invalid_argument("Erro: Dominio contem partes vazias (pontos consecutivos).");
        }

        // Regra: Parte não pode iniciar ou terminar com hífen
        if (parte.front() == '-' || parte.back() == '-') {
            throw invalid_argument("Erro: Parte do dominio nao pode iniciar ou terminar com hifen.");
        }

        // Valida caracteres da parte
        for (char c : parte) {
            bool ehLetra = (c >= 'a' && c <= 'z');
            bool ehDigito = (c >= '0' && c <= '9');
            bool ehHifen = (c == '-');

            if (!ehLetra && !ehDigito && !ehHifen) {
                throw invalid_argument("Erro: Caractere invalido no dominio.");
            }
        }

        // Prepara para a próxima iteração
        if (posPonto == string::npos) {
            break;
        }
        inicioParte = posPonto + 1;
        posPonto = dominio.find('.', inicioParte);
    }
}

void Email::setValor(string email) {
    validar(email);
    this->valor = email;
}

string Email::getValor() const {
    return valor;
}