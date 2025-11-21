#ifndef DINHEIRO_H
#define DINHEIRO_H

#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
/**
 * @class Dinheiro
 * @brief Representa o domínio de valores monetários.
 * * @details
 * Regras de formato válido conforme especificação:
 * - Valor deve estar entre 0,01 e 1.000.000,00.
 * - O armazenamento deve ser realizado em número inteiro (centavos) para evitar erros de arredondamento.
 */
class Dinheiro {
private:
    /**
     * @brief Armazena o valor em centavos.
     * * Utiliza long long para garantir capacidade, atendendo ao requisito de armazenamento inteiro.
     */
    long long valorCentavos; 
    
    /**
     * @brief Valida se o valor em centavos está na faixa permitida.
     * * @param valor O valor em centavos a ser validado.
     * @throw invalid_argument Se o valor estiver fora do intervalo de 1 a 100.000.000 (correspondente a 0,01 - 1.000.000,00).
     */
    void validar(long long valor);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com valor 0.
     */
    Dinheiro(); 

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o valor armazenado internamente.
     * * @return string O valor do atributo armazenado.
     */
    operator string() const;

    /**
     * @brief Construtor que inicializa com um valor em ponto flutuante.
     * * Converte o valor double para centavos e valida.
     * * @param valor Valor monetário (ex: 100.50).
     * @throw invalid_argument Se o valor estiver fora da faixa permitida.
     */
    Dinheiro(double valor); 
    
    virtual ~Dinheiro();

    /**
     * @brief Define o valor monetário.
     * * Realiza a conversão de double para representação interna em centavos e valida as regras de negócio.
     * * @param valor Valor monetário (ex: 100.50).
     * @throw invalid_argument Se o valor for menor que 0,01 ou maior que 1.000.000,00.
     */
    void setDinheiro(double valor);

    /**
     * @brief Recupera o valor monetário.
     * * Converte o valor interno (centavos) de volta para double.
     * * @return double O valor monetário.
     */
    double getDinheiro() const; 
};

#endif