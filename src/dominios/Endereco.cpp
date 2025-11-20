#include "Endereco.h"

/**
 * @brief Valida o endereço.
 * Verifica se o tamanho da string passada (parametro) está correto.
 * Não verifica o atributo 'valor' da classe, mas sim o argumento recebido.
 */
void Endereco::validarEndereco(const std::string& endereco) const {
    // 1. Tamanho (5 a 30)
    if (endereco.length() < 5 || endereco.length() > 30) {
        throw std::invalid_argument("Erro: Endereço deve ter entre 5 e 30 caracteres.");
    }

    // 2. Validar caracteres permitidos e regras de posição
    // Permitidos: Letra (A-Z, a-z), Dígito (0-9), Vírgula, Ponto, Espaço.
    
    for (size_t i = 0; i < endereco.length(); i++) {
        char c = endereco[i];

        // Verifica se é caracter válido
        bool isLetra = isalpha(c);
        bool isDigito = isdigit(c);
        bool isPonto = (c == '.');
        bool isVirgula = (c == ',');
        bool isEspaco = (c == ' ');

        if (!isLetra && !isDigito && !isPonto && !isVirgula && !isEspaco) {
            throw std::invalid_argument("Endereco contem caractere invalido.");
        }

        // Regra: Primeiro e último caracter não podem ser vírgula, ponto ou espaço
        if (i == 0 || i == endereco.length() - 1) {
            if (isPonto || isVirgula || isEspaco) {
                throw std::invalid_argument("Endereco nao pode comecar ou terminar com ponto, virgula ou espaco.");
            }
        }

        // Regras de sequência (olhando para o próximo caractere)
        if (i < endereco.length() - 1) {
            char next = endereco[i+1];
            bool nextIsPonto = (next == '.');
            bool nextIsVirgula = (next == ',');
            bool nextIsEspaco = (next == ' '); // Regra implicita: espaço seguido de letra/digito

            // Vírgula não pode ser seguida por vírgula ou ponto
            if (isVirgula && (nextIsVirgula || nextIsPonto)) {
                throw std::invalid_argument("Virgula nao pode ser seguida de ponto ou virgula.");
            }

            // Ponto não pode ser seguido por vírgula ou ponto
            if (isPonto && (nextIsVirgula || nextIsPonto)) {
                throw std::invalid_argument("Ponto nao pode ser seguido de ponto ou virgula.");
            }

            // Espaço deve ser seguido por letra ou dígito (Implica: não pode ter espaço duplo, nem espaço-ponto)
            if (isEspaco && !(isalpha(next) || isdigit(next))) {
                throw std::invalid_argument("Espaco deve ser seguido de letra ou numero.");
            }
        }
    }
}
    
/**
 * @brief Construtor padrão.
 */
Endereco::Endereco() {
    this->valor = "";
} 

/**
 * @brief Setter do endereço.
 * Valida antes de atribuir.
 * Nota: Corrigido de 'setValor' para 'setEndereco' para casar com o .h
 */
void Endereco::setEndereco(const std::string& endereco) {
    validarEndereco(endereco);
    this->valor = endereco;
}

/**
 * @brief Construtor com parâmetros.
 * Utiliza o método setEndereco para garantir a validação.
 */
Endereco::Endereco(const std::string& endereco) {
    setEndereco(endereco);
}

/**
 * @brief Getter do endereço.
 */
std::string Endereco::getEndereco() const {
    return this->valor;
}