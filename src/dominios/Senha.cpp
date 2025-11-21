#include "Senha.h"
#include <cctype> // Necessário para isupper, islower, isdigit, isalpha

using namespace std;

Senha::Senha() {
    this->valor = "A1b%2"; // Valor padrão que atende a todas as regras
}

Senha::Senha(string senha) {
    setValor(senha);
}

Senha::~Senha() {
}

void Senha::validar(string senha) {
    // 1. Validação de Tamanho
    if (senha.length() != 5) {
        throw invalid_argument("Erro: Senha deve ter exatamente 5 caracteres.");
    }

    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;
    bool temEspecial = false;
    
    const string especiaisPermitidos = "!\"#$%&?";

    for (size_t i = 0; i < senha.length(); i++) {
        char c = senha[i];

        // Identificação do tipo de caractere
        bool ehMaiuscula = isupper(c);
        bool ehMinuscula = islower(c);
        bool ehDigito = isdigit(c);
        // Verifica se o char existe na string de especiais permitidos
        bool ehEspecial = (especiaisPermitidos.find(c) != string::npos);

        // 2. Validação de Caractere Inválido
        if (!ehMaiuscula && !ehMinuscula && !ehDigito && !ehEspecial) {
            throw invalid_argument("Erro: Senha contem caractere invalido.");
        }

        // Atualiza as flags de presença
        if (ehMaiuscula) temMaiuscula = true;
        if (ehMinuscula) temMinuscula = true;
        if (ehDigito) temDigito = true;
        if (ehEspecial) temEspecial = true;

        // 3. Validação de Consecutivos
        if (i > 0) {
            char anterior = senha[i-1];
            
            // Letra seguida de letra (seja maiúscula ou minúscula)
            if (isalpha(anterior) && isalpha(c)) {
                throw invalid_argument("Erro: Senha nao pode ter letras consecutivas.");
            }

            // Dígito seguido de dígito
            if (isdigit(anterior) && isdigit(c)) {
                throw invalid_argument("Erro: Senha nao pode ter digitos consecutivos.");
            }
        }
    }

    // 4. Validação de Completude (Pelo menos um de cada tipo)
    if (!temMaiuscula || !temMinuscula || !temDigito || !temEspecial) {
        throw invalid_argument("Erro: Senha deve conter pelo menos uma maiuscula, uma minuscula, um digito e um especial.");
    }
}

void Senha::setValor(string senha) {
    validar(senha);
    this->valor = senha;
}

string Senha::getValor() const {
    return valor;
}