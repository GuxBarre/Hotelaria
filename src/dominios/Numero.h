#ifndef NUMERO_H
#define NUMERO_H

#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
/**
 * @class Numero
 * @brief Representa o domínio de número de quarto.
 * * @details
 * Regras de formato válido conforme especificação:
 * - Deve ser um numero inteiro.
 * - Intervalo permitido: 1 a 999 (inclusive).
 */
class Numero {
private:
    int numero;
    
    /**
     * @brief Valida se o número está dentro do intervalo permitido.
     * * @param numero O inteiro a ser validado.
     * @throw invalid_argument Se o numero for menor que 1 ou maior que 999.
     */
    void validar(int numero);

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o objeto com um estado padrão.
     */
    Numero(); 

    /**
     * @brief Sobrecarga do operador de conversão para string.
     * * Permite que o objeto seja convertido implicitamente para uma string,
     * retornando o numero armazenado internamente.
     * * @return string O numero do atributo armazenado.
     */
    operator string() const;
    /**
     * @brief Construtor de inicialização.
     * * Já instancia o objeto validando o número fornecido.
     * * @param numero Inteiro representando o número do quarto.
     * @throw invalid_argument Se o numero estiver fora do intervalo de 1 a 999.
     */
    Numero(int numero); 
    
    virtual ~Numero();

    /**
     * @brief Define o número do quarto.
     * * @param numero Inteiro entre 1 e 999.
     * @throw invalid_argument Se o numero violar a regra de intervalo.
     */
    void setNumero(int numero);

    /**
     * @brief Recupera o número armazenado.
     * * @return int O número do quarto.
     */
    int getNumero() const;
};

#endif