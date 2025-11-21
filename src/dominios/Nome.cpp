#include "Nome.h"
#include <cctype> // Necessário para isupper, isalpha, isspace

using namespace std;

Nome::Nome() {
    this->nome = "Nome Padrao"; // Um valor válido inicial genérico
}

Nome::Nome(string nome) {
    setNome(nome);
}

Nome::~Nome() {
}

void Nome::validar(string nome) {
    // 1. Verificar Tamanho (5 a 20)
    if (nome.length() < 5 || nome.length() > 20) {
        throw invalid_argument("Erro: Nome deve ter entre 5 e 20 caracteres.");
    }

    // Percorrer a string para validar caractere por caractere
    for (size_t i = 0; i < nome.length(); i++) {
        char c = nome[i];

        // 2. Caractere invalido (não é letra nem espaço)
        // isalpha verifica se é letra, isspace verifica se é espaço
        if (!isalpha(c) && c != ' ') {
            throw invalid_argument("Erro: Nome contem caracteres invalidos (apenas letras e espaco).");
        }

        // 3. Regra do Espaço
        if (c == ' ') {
            // Não pode terminar com espaço
            if (i == nome.length() - 1) {
                throw invalid_argument("Erro: Nome nao pode terminar com espaco.");
            }
            // Espaço deve ser seguido por letra (impede espaços duplos)
            if (!isalpha(nome[i + 1])) {
                throw invalid_argument("Erro: Espaco deve ser seguido por letra (sem espacos duplos).");
            }
        }

        // 4. Regra de Capitalização (Primeira letra de cada termo)
        // Se for o primeiro caractere (i==0) OU o anterior foi um espaço
        bool deveSerMaiuscula = (i == 0) || (nome[i - 1] == ' ');
        
        if (deveSerMaiuscula) {
            if (!isupper(c)) {
                throw invalid_argument("Erro: Primeira letra de cada termo deve ser maiuscula.");
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