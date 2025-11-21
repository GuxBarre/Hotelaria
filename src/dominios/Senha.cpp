#include "Senha.h"
#include <stdexcept>
#include <cctype>

using namespace std;

static bool ehLetraMinuscula(char c) {
    return std::islower(static_cast<unsigned char>(c));
}

static bool ehLetraMaiuscula(char c) {
    return std::isupper(static_cast<unsigned char>(c));
}

static bool ehDigito(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

static bool ehEspecial(char c) {
    // caracteres especiais permitidos
    const string especiais = "!\"#$%&?";
    return especiais.find(c) != string::npos;
}

void Senha::validar(const string &senha) {
    // 1. Tamanho exato
    if (senha.size() != 5) {
        throw invalid_argument("Senha invalida: deve ter exatamente 5 caracteres.");
    }

    bool temMinuscula = false;
    bool temMaiuscula = false;
    bool temDigito    = false;
    bool temEspecial  = false;

    for (size_t i = 0; i < senha.size(); ++i) {
        char c = senha[i];

        bool ehLetra = ehLetraMinuscula(c) || ehLetraMaiuscula(c);
        bool ehNum   = ehDigito(c);
        bool ehEsp   = ehEspecial(c);

        // 2. Só pode ser letra, digito ou especial permitido
        if (!ehLetra && !ehNum && !ehEsp) {
            throw invalid_argument("Senha invalida: caractere nao permitido.");
        }

        // 3. Regras de nao repetir tipo consecutivo:
        //    letra nao pode vir depois de letra
        //    digito nao pode vir depois de digito
        if (i > 0) {
            char ant = senha[i - 1];
            bool antLetra = std::isalpha(static_cast<unsigned char>(ant));
            bool antNum   = std::isdigit(static_cast<unsigned char>(ant));

            if (antLetra && ehLetra) {
                throw invalid_argument("Senha invalida: duas letras consecutivas.");
            }
            if (antNum && ehNum) {
                throw invalid_argument("Senha invalida: dois digitos consecutivos.");
            }
        }

        // 4. Marcar presença dos tipos
        if (ehLetraMinuscula(c)) temMinuscula = true;
        if (ehLetraMaiuscula(c)) temMaiuscula = true;
        if (ehNum)               temDigito    = true;
        if (ehEsp)               temEspecial  = true;
    }

    // 5. Precisa ter pelo menos 1 de cada tipo
    if (!temMinuscula || !temMaiuscula || !temDigito || !temEspecial) {
        throw invalid_argument("Senha invalida: precisa de minuscula, maiuscula, digito e especial.");
    }
}

void Senha::setValor(const string &senha) {
    validar(senha);
    valor = senha;
}

string Senha::getValor() const {
    return valor;
}
