#include "Senha.h"
#include <cctype>
#include <string>
using namespace std;

Senha::Senha() {
    this->senha = "A1b%2";
}

Senha::Senha(string senha) {
    setSenha(senha);
}

Senha::~Senha() {
}

void Senha::validar(string senha) {
    if (senha.length() != 5) {
        throw invalid_argument("Senha deve ter exatamente 5 caracteres.");
    }

    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;
    bool temEspecial = false;
    
    const string especiaisPermitidos = "!\"#$%&?";

    for (size_t i = 0; i < senha.length(); i++) {
        char c = senha[i];

        bool ehMaiuscula = isupper(c);
        bool ehMinuscula = islower(c);
        bool ehDigito = isdigit(c);
        bool ehEspecial = (especiaisPermitidos.find(c) != string::npos);

        if (!ehMaiuscula && !ehMinuscula && !ehDigito && !ehEspecial) {
            throw invalid_argument("Senha contem caractere invalido.");
        }

        if (ehMaiuscula) temMaiuscula = true;
        if (ehMinuscula) temMinuscula = true;
        if (ehDigito) temDigito = true;
        if (ehEspecial) temEspecial = true;

        if (i > 0) {
            char anterior = senha[i-1];
            
            if (isalpha(anterior) && isalpha(c)) {
                throw invalid_argument("Senha nao pode ter letras consecutivas.");
            }
            if (isdigit(anterior) && isdigit(c)) {
                throw invalid_argument("Senha nao pode ter digitos consecutivos.");
            }
        }
    }

    if (!temMaiuscula || !temMinuscula || !temDigito || !temEspecial) {
        throw invalid_argument("Senha deve conter pelo menos uma maiuscula, uma minuscula, um digito e um especial.");
    }
}

void Senha::setSenha(string senha) {
    validar(senha);
    this->senha = senha;
}

string Senha::getSenha() const {
    return senha;
}

Senha::operator string() const {
    return senha;
}