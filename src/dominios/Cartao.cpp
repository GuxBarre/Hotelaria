#include "Cartao.h"

/**
 * @brief Construtor Padrão.
 * Inicializa o objeto com uma string vazia.
 * Não lança exceções neste estado inicial.
 */
Cartao::Cartao() {
    // Inicializa vazio ou você poderia definir um estado inválido padrão
    this->numero = ""; 
}

/**
 * @brief Construtor com validação imediata.
 * Tenta definir o valor e validar. Se falhar, a exceção sobe para quem chamou.
 * @param numero O número do cartão a ser validado.
 */
Cartao::Cartao(const string& numero) {
    setValor(numero);
}

/**
 * @brief Define o número do cartão.
 * Este método atua como um "guardião", impedindo que o objeto assuma um estado inválido.
 * @param numero String numérica de 16 dígitos.
 */
void Cartao::setValor(const string& numero) {
    validar(numero); // Se falhar, lança exceção e não executa a linha abaixo
    this->numero = numero;
}

/**
 * @brief Retorna o número atual armazenado.
 * @return string Número do cartão.
 */
string Cartao::getValor() const {
    return this->numero;
}

/**
 * @brief Orquestrador de validações.
 * Executa três verificações sequenciais:
 * 1. Tamanho (deve ser 16).
 * 2. Conteúdo (apenas dígitos numéricos).
 * 3. Integridade (Algoritmo de Luhn).
 * * @param numero A string a ser verificada.
 * @throw std::invalid_argument Caso qualquer uma das verificações falhe.
 */
void Cartao::validar(const string& numero) const {
    // 1. Verificar tamanho (Requisito da imagem: 16 dígitos)
    if (numero.length() != 16) {
        throw invalid_argument("Erro: O cartao deve possuir exatamente 16 digitos.");
    }

    // 2. Verificar se contém apenas números
    for (char c : numero) {
        if (!isdigit(c)) {
            throw invalid_argument("Erro: O cartao deve conter apenas numeros.");
        }
    }

    // 3. Verificar Algoritmo de Luhn (Requisito da imagem)
    if (!validarLuhn(numero)) {
        throw invalid_argument("Erro: Numero de cartao invalido (Falha na verificacao de Luhn).");
    }
}

/**
 * @brief Implementação do Algoritmo de Luhn.
 * Percorre o número da direita para a esquerda. Dobra o valor de cada segundo dígito.
 * Se o dobro for maior que 9, subtrai 9 (ex: 16 vira 7).
 * A soma total deve ser divisível por 10 para o cartão ser válido.
 * * @param numero A string numérica validada previamente (tamanho e dígitos).
 * @return true Se o checksum for válido (soma % 10 == 0).
 * @return false Caso contrário.
 */
bool Cartao::validarLuhn(const string& numero) const {
    int soma = 0;
    bool dobrar = false; // Começamos do último dígito, que não é dobrado (dígito verificador)

    // Percorre a string de trás para frente
    for (int i = numero.length() - 1; i >= 0; i--) {
        // Converte char para int ('0' é 48 na tabela ASCII)
        int n = numero[i] - '0';

        if (dobrar) {
            n *= 2;
            if (n > 9) {
                n -= 9; // Mesma coisa que somar os dígitos (ex: 18 -> 1+8=9 ou 18-9=9)
            }
        }

        soma += n;
        dobrar = !dobrar; // Alterna a flag para o próximo dígito
    }

    // Se o módulo de 10 for 0, o número é válido
    return (soma % 10 == 0);
}